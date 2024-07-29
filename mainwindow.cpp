#include <QFileDialog>
#include <QMessageBox>
#include <QCloseEvent>
#include <QDesktopWidget>
#include <QClipboard>

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "listdialog.h"
#include "cssdialog.h"
#include "embdialog.h"
#include "idbeffectdialog.h"
#include "colordialog.h"

#include "Xenoverse2.h"
#include "BpeFile.h"
#include "xv2ins_common.h"
#include "Config.h"
#include "debug.h"

#define INTERNAL_DATA "Internal package content"
#define GAME_PREFIX "GAME:///"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QLocale::setDefault(QLocale::c());
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    if (x2m)
        delete x2m;

    delete ui;
}

bool MainWindow::Initialize()
{
    ui->actionOpen->setIcon(ui->mainToolBar->style()->standardIcon(QStyle::SP_DialogOpenButton));
    ui->actionSave->setIcon(ui->mainToolBar->style()->standardIcon(QStyle::SP_DialogSaveButton));

    // Main info tab
    ui->modVersionEdit->setValidator(new QDoubleValidator(this));   
    // Idb tab
    ui->idbStarsEdit->setValidator(new QIntValidator(-32768, 32767, this));
    ui->idbU0AEdit->setValidator(new QIntValidator(-32768, 32767, this));
    ui->idbU0CEdit->setValidator(new QIntValidator(-32768, 32767, this));
    ui->idbU0EEdit->setValidator(new QIntValidator(-32768, 32767, this));
    ui->idbBuyEdit->setValidator(new QIntValidator(this));
    ui->idbSellEdit->setValidator(new QIntValidator(this));
    ui->idbTpEdit->setValidator(new QIntValidator(this));
    ui->idbU24Edit->setValidator(new QIntValidator(this));
    ui->idbU28Edit->setValidator(new QIntValidator(this));
    ui->idbU2CEdit->setValidator(new QIntValidator(this));
    ui->idbNU0CEdit->setValidator(new QIntValidator(this));
    ui->idbNU0AEdit->setValidator(new QIntValidator(-32768, 32767, this));
    ui->idbNU2CEdit->setValidator(new QIntValidator(this));
    ui->idbStpEdit->setValidator(new QIntValidator(this));
    ui->idbCopyButton->addAction(ui->actionFromGameIdb);    

    set_debug_level(2);
    QDir::setCurrent(qApp->applicationDirPath());

    Bootstrap(false, false);
    if (!game_talisman_idb)
        Xenoverse2::InitIdb(false, false, true, false, false, false, false, false);

    // Fill types combo box
    std::vector<std::string> bt;
    if (Xenoverse2::GetAllDefaultBlastTypes(bt))
    {
        for (const std::string &str: bt)
        {
            ui->idbBlastType->addItem(Utils::StdStringToQString(str));
        }
    }

    x2m = new X2mFile();
    x2m->SetType(X2mType::NEW_SUPERSOUL);

    // Handle arguments
    if (qApp->arguments().size() == 2)
    {
        QString file = qApp->arguments()[1];

        config.lf_editor_open = file;
        X2mFile *new_x2m = new X2mFile();

        if (new_x2m->LoadFromFile(Utils::QStringToStdString(file)))
        {
            delete x2m;
            x2m = new_x2m;
            config.lf_editor_save = file;
        }
        else
        {
            delete new_x2m;
        }
    }

    if (x2m->GetType() != X2mType::NEW_SUPERSOUL)
    {
        DPRINTF("This kind of x2m is not supported by this editor.\n");
        return false;
    }

    ProcessX2m();
    return true;
}

void MainWindow::on_actionOpen_triggered()
{
    QString file = QFileDialog::getOpenFileName(this, "Open file", config.lf_editor_open, "X2M Files (*.x2m)");

    if (file.isNull())
        return;

    config.lf_editor_open = file;

    X2mFile *new_x2m = new X2mFile();

    if (!new_x2m->LoadFromFile(Utils::QStringToStdString(file)))
    {
        DPRINTF("Load file failed.\n");
        delete new_x2m;
        return;
    }

    config.lf_editor_save = file;

    if (new_x2m->GetType() != X2mType::NEW_SUPERSOUL)
    {
        DPRINTF("That x2m is not of new supersoul type!\n");
        delete new_x2m;
        return;
    }

    delete x2m;
    x2m = new_x2m;
    ProcessX2m();
}

void MainWindow::on_actionSave_triggered()
{
    if (!Validate())
        return;

    QString file = QFileDialog::getSaveFileName(this, "Save file", config.lf_editor_save, "X2M Files (*.x2m)");

    if (file.isNull())
        return;

    config.lf_editor_save = file;

    if (!Build())
    {
        DPRINTF("Build failed.\n");
        return;
    }

    if (!x2m->SaveToFile(Utils::QStringToStdString(file)))
    {
        DPRINTF("x2m save failed.\n");
        return;
    }

    UPRINTF("File has been succesfully written.\n");
}

void MainWindow::on_actionExit_triggered()
{
    if (ProcessShutdown())
        qApp->exit();
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox box;

    box.setWindowTitle(PROGRAM_NAME_SSCREAT);
    box.setTextFormat(Qt::RichText);
    box.setIcon(QMessageBox::Icon::Information);
    box.setText(QString("%1 v%2 by Eternity<br>Built on %3 %4<br><br>If you liked the program, you can support its development at<br><a href='https://www.patreon.com/eternity_tools'>https://www.patreon.com/eternity_tools</a>").arg(PROGRAM_NAME_SSCREAT).arg(PROGRAM_VERSION).arg(__DATE__).arg(__TIME__));

    box.exec();
}

bool MainWindow::ProcessShutdown()
{
    config.Save();
    return true;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if (ProcessShutdown())
        event->accept();
    else
        event->ignore();
}

void MainWindow::ProcessX2m()
{
    // Info tab
    ui->modNameEdit->setText(Utils::StdStringToQString(x2m->GetModName(), false));
    ui->modAuthorEdit->setText(Utils::StdStringToQString(x2m->GetModAuthor(), false));
    ui->modVersionEdit->setText(QString::number(x2m->GetModVersion()));
    ui->modGuidEdit->setText(Utils::StdStringToQString(x2m->GetModGuid()));
    ui->ssNameEdit->setText(Utils::StdStringToQString(x2m->GetSSItem().item_name[ui->ssNameLangComboBox->currentIndex()], false));
    ui->ssDescEdit->setText(Utils::StdStringToQString(x2m->GetSSItem().item_desc[ui->ssDescLangComboBox->currentIndex()], false));
    ui->ssHowEdit->setText(Utils::StdStringToQString(x2m->GetSSItem().item_how[ui->ssHowLangComboBox->currentIndex()], false));

    // Files tab
    if (x2m->JungleExists())
    {
        ui->addDataEdit->setText(INTERNAL_DATA);
        ui->addDataEdit->setEnabled(false);
    }
    else
    {
        ui->addDataEdit->setText("");
        ui->addDataEdit->setEnabled(true);
    }   

    // Idb tab
    IdbEntry &idb = x2m->GetSSItem().idb;    
    IdbEntryToGui(idb);

    // Update to new format
    x2m->SetFormatVersion(x2m->X2M_CURRENT_VERSION);
}

bool MainWindow::Validate()
{
    // Info tab
    if (ui->modNameEdit->text().isEmpty())
    {
        DPRINTF("[INFO] Mod name cannot be empty.\n");
        return false;
    }

    if (ui->modAuthorEdit->text().isEmpty())
    {
        DPRINTF("[INFO] Mod author cannot be empty.\n");
        return false;
    }

    if (ui->modVersionEdit->text().isEmpty())
    {
        DPRINTF("[INFO] Mod version cannot be empty.\n");
        return false;
    }    

    if (Utils::IsEmptyString(x2m->GetSSItem().item_name[XV2_LANG_ENGLISH]))
    {
        DPRINTF("[INFO] Name cannot be empty for english language.\n");
        return false;
    }

    if (Utils::IsEmptyString(x2m->GetSSItem().item_desc[XV2_LANG_ENGLISH]))
    {
        for (int i = 0; i < XV2_LANG_NUM; i++)
        {
            if (i == XV2_LANG_ENGLISH)
                continue;

            if (!Utils::IsEmptyString(x2m->GetSSItem().item_desc[i]))
            {
                DPRINTF("[INFO] If desc is empty in english language, it must be empty in the rest too.\n");
                return false;
            }
        }
    }

    if (Utils::IsEmptyString(x2m->GetSSItem().item_how[XV2_LANG_ENGLISH]))
    {
        for (int i = 0; i < XV2_LANG_NUM; i++)
        {
            if (i == XV2_LANG_ENGLISH)
                continue;

            if (!Utils::IsEmptyString(x2m->GetSSItem().item_how[i]))
            {
                DPRINTF("[INFO] If how is empty in english language, it must be empty in the rest too.\n");
                return false;
            }
        }
    }

    // Files tab
    if (ui->addDataEdit->isEnabled())
    {
        QString add_data = ui->addDataEdit->text().trimmed();

        if (!add_data.isEmpty())
        {
            std::string add_data_std = Utils::QStringToStdString(add_data);

            if (!Utils::IsEmptyString(add_data_std))
            {
                if (!Utils::DirExists(add_data_std))
                {
                    DPRINTF("[FILES] Directory %s doesn't exist.\n", add_data_std.c_str());
                    return false;
                }
                else if (Utils::IsDirectoryEmpty(add_data_std, true))
                {
                    DPRINTF("[FILES] Directory %s is either empty or it only contains empty directories!\n", add_data_std.c_str());
                    return false;
                }
            }
        }
    }

    // IDB tab
    if (ui->idbStarsEdit->text().isEmpty())
    {
        DPRINTF("[IDB] Stars cannot be empty.\n");
        return false;
    }

    if (ui->idbU0AEdit->text().isEmpty())
    {
        DPRINTF("[IDB] U_0A cannot be empty.\n");
        return false;
    }

    if (ui->idbU0CEdit->text().isEmpty())
    {
        DPRINTF("[IDB] U_0C cannot be empty.\n");
        return false;
    }

    if (ui->idbU0EEdit->text().isEmpty())
    {
        DPRINTF("[IDB] U_0E cannot be empty.\n");
        return false;
    }

    if (ui->idbBuyEdit->text().isEmpty())
    {
        DPRINTF("[IDB] Buy cannot be empty.\n");
        return false;
    }

    if (ui->idbSellEdit->text().isEmpty())
    {
        DPRINTF("[IDB] Sell cannot be empty.\n");
        return false;
    }

    if (ui->idbTpEdit->text().isEmpty())
    {
        DPRINTF("[IDB] TP cannot be empty.\n");
        return false;
    }    

    if (ui->idbU24Edit->text().isEmpty())
    {
        DPRINTF("[IDB] U_24 cannot be empty.\n");
        return false;
    }

    if (ui->idbU28Edit->text().isEmpty())
    {
        DPRINTF("[IDB] U_28 cannot be empty.\n");
        return false;
    }

    if (ui->idbU2CEdit->text().isEmpty())
    {
        DPRINTF("[IDB] U_2C cannot be empty.\n");
        return false;
    }

    return true;
}

bool MainWindow::Build()
{
    // Info
    x2m->SetModName(Utils::QStringToStdString(ui->modNameEdit->text(), false));
    x2m->SetModAuthor(Utils::QStringToStdString(ui->modAuthorEdit->text(), false));
    x2m->SetModVersion(ui->modVersionEdit->text().toFloat());   

    // Files
    QString add_data = ui->addDataEdit->text().trimmed();

    if (ui->addDataEdit->isEnabled())
    {
        std::string add_data_std = Utils::QStringToStdString(add_data);

        x2m->DeleteJungle();

        if (!Utils::IsEmptyString(add_data_std) && !x2m->AddExternalDirectory(add_data_std, X2M_JUNGLE))
        {
            DPRINTF("AddExternalDirectory failed on additional data.\n");
            return false;
        }
    }
    else
    {
        if (add_data == INTERNAL_DATA)
        {
            // Do nothing
        }
        else
        {
            DPRINTF("%s: Bug in implementation.\n", FUNCNAME);
            return false;
        }
    }    

    // IDB
    IdbEntry &idb_entry = x2m->GetSSItem().idb;
    GuiToIdbEntry(idb_entry);
    idb_entry.id = idb_entry.name_id = idb_entry.desc_id = X2M_DUMMY_ID16;

    if (x2m->HasSSSkillDepend())
    {
        idb_entry.model = 0;
    }

    // Attachment clear (if needed)
    if (!x2m->HasSSSkillDepend())
    {
        x2m->DeleteDir(X2M_SS_BLAST_ATTACHMENT);
    }

    return true;
}

void MainWindow::on_guidButton_clicked()
{
    uint8_t guid[16];
    std::string guid_str;

    Utils::GetRandomData(guid, sizeof(guid));
    guid_str = Utils::GUID2String(guid);

    x2m->SetModGuid(guid_str);
    ui->modGuidEdit->setText(Utils::StdStringToQString(guid_str));
}

void MainWindow::on_ssNameLangComboBox_currentIndexChanged(int index)
{
    ui->ssNameEdit->setText(Utils::StdStringToQString(x2m->GetSSItem().item_name[index], false));
}

void MainWindow::on_ssNameEdit_textEdited(const QString &arg1)
{
    x2m->GetSSItem().item_name[ui->ssNameLangComboBox->currentIndex()] = Utils::QStringToStdString(arg1, false);
}

void MainWindow::on_ssNameCopyButton_clicked()
{
    ListDialog dialog(ListMode::TALISMAN, this);

    if (!dialog.exec())
        return;

    const IdbEntry *entry = game_talisman_idb->FindEntryByID(dialog.GetResultData());
    if (!entry)
        return;

    for (int i = 0; i < XV2_LANG_NUM; i++)
    {
        std::string name;

        if (!Xenoverse2::GetTalismanName(entry->name_id, name, i))
            return;

        x2m->GetSSItem().item_name[i] = name;
    }

    int lang = ui->ssNameLangComboBox->currentIndex();

    if (lang >= 0 && lang < XV2_LANG_NUM)
    {
        ui->ssNameEdit->setText(Utils::StdStringToQString(x2m->GetSSItem().item_name[lang], false));
    }
}

void MainWindow::on_ssDescLangComboBox_currentIndexChanged(int index)
{
    ui->ssDescEdit->setText(Utils::StdStringToQString(x2m->GetSSItem().item_desc[index], false));
}

void MainWindow::on_ssDescEdit_textChanged()
{
    QString text = ui->ssDescEdit->toPlainText();
    x2m->GetSSItem().item_desc[ui->ssDescLangComboBox->currentIndex()] = Utils::QStringToStdString(text, false);
}

void MainWindow::on_ssDescCopyButton_clicked()
{
    ListDialog dialog(ListMode::TALISMAN, this);

    if (!dialog.exec())
        return;

    const IdbEntry *entry = game_talisman_idb->FindEntryByID(dialog.GetResultData());
    if (!entry)
        return;

    for (int i = 0; i < XV2_LANG_NUM; i++)
    {
        std::string desc;

        if (!Xenoverse2::GetTalismanDesc(entry->desc_id, desc, i))
            return;

        x2m->GetSSItem().item_desc[i] = desc;
    }

    int lang = ui->ssDescLangComboBox->currentIndex();

    if (lang >= 0 && lang < XV2_LANG_NUM)
    {
        ui->ssDescEdit->setText(Utils::StdStringToQString(x2m->GetSSItem().item_desc[lang], false));
    }
}

void MainWindow::on_ssHowLangComboBox_currentIndexChanged(int index)
{
    ui->ssHowEdit->setText(Utils::StdStringToQString(x2m->GetSSItem().item_how[index], false));
}

void MainWindow::on_ssHowEdit_textChanged()
{
    QString text = ui->ssHowEdit->toPlainText();
    x2m->GetSSItem().item_how[ui->ssHowLangComboBox->currentIndex()] = Utils::QStringToStdString(text, false);
}

void MainWindow::on_ssHowCopyButton_clicked()
{
    ListDialog dialog(ListMode::TALISMAN, this);

    if (!dialog.exec())
        return;

    const IdbEntry *entry = game_talisman_idb->FindEntryByID(dialog.GetResultData());
    if (!entry)
        return;

    for (int i = 0; i < XV2_LANG_NUM; i++)
    {
        std::string how;

        if (!Xenoverse2::GetTalismanHow(entry->how_id, how, i))
            return;

        x2m->GetSSItem().item_how[i] = how;
    }

    int lang = ui->ssHowLangComboBox->currentIndex();

    if (lang >= 0 && lang < XV2_LANG_NUM)
    {
        ui->ssHowEdit->setText(Utils::StdStringToQString(x2m->GetSSItem().item_how[lang], false));
    }
}

void MainWindow::on_addEditButton_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, "Choose directory that conteins data directory", config.ld_add_data);

    if (dir.isNull())
        return;

    std::string dir_std = Utils::NormalizePath(Utils::QStringToStdString(dir));

    if (dir_std.length() != 0 && !Utils::EndsWith(dir_std, "/"))
        dir_std += '/';

    if (!Utils::DirExists(dir_std + "data"))
    {
        if (QMessageBox::question(this, "Use that directory?",
                                  "That directory doesn't contain a directory called \"data\" inside. "
                                  "Are you sure that it is the correct directory?",
                                  QMessageBox::StandardButtons(QMessageBox::Yes|QMessageBox::No),
                                  QMessageBox::No) == QMessageBox::No)
        {
            return;
        }
    }
    else if (Utils::DirExists(dir_std + "data/system"))
    {
        if (QMessageBox::question(this, "Use that directory?",
                                  "That directory contains a system directory that will affect the whole game, "
                                  "what defeats the philosophy of a new character mod.\n\n"
                                  "Are you sure you want to use that directory?",
                                  QMessageBox::StandardButtons(QMessageBox::Yes|QMessageBox::No),
                                  QMessageBox::No) == QMessageBox::No)
        {
            return;
        }
    }

    config.ld_add_data = dir;
    x2m->DeleteJungle();

    ui->addDataEdit->setText(dir);
    ui->addDataEdit->setEnabled(true);
}

void MainWindow::IdbEntryToGui(const IdbEntry &entry)
{
    ui->idbStarsEdit->setText(QString("%1").arg((int16_t)entry.stars));
    ui->idbU0AEdit->setText(QString("%1").arg((int16_t)entry.dlc_flag));
    ui->idbU0CEdit->setText(QString("%1").arg((int16_t)entry.availability));
    ui->idbU0EEdit->setText(QString("%1").arg((int16_t)entry.unk_0E));
    ui->idbBuyEdit->setText(QString("%1").arg((int32_t)entry.buy));
    ui->idbSellEdit->setText(QString("%1").arg((int32_t)entry.sell));
    ui->idbTpEdit->setText(QString("%1").arg((int32_t)entry.tp));
    ui->idbU24Edit->setText(QString("%1").arg((int32_t)entry.unk_24[0]));
    ui->idbU28Edit->setText(QString("%1").arg((int32_t)entry.unk_24[1]));
    ui->idbU2CEdit->setText(QString("%1").arg((int32_t)entry.unk_24[2]));
    ui->idbNU0CEdit->setText(QString("%1").arg((int32_t)entry.new_unk_0C));
    ui->idbNU0AEdit->setText(QString("%1").arg((int16_t)entry.new_unk_0A));
    ui->idbNU2CEdit->setText(QString("%1").arg((int32_t)entry.new_unk_2C));
    ui->idbStpEdit->setText(QString("%1").arg((int32_t)entry.stp));

    int32_t idx = (int32_t)entry.model;
    if (idx < 0 || idx >= ui->idbBlastType->count() || x2m->HasSSSkillDepend())
        idx = 0;
    ui->idbBlastType->setCurrentIndex(idx);

    ui->idbHumCheck->setChecked(entry.racelock & IDB_RACE_HUM);
    ui->idbHufCheck->setChecked(entry.racelock & IDB_RACE_HUF);
    ui->idbSymCheck->setChecked(entry.racelock & IDB_RACE_SYM);
    ui->idbSyfCheck->setChecked(entry.racelock & IDB_RACE_SYF);
    ui->idbNmcCheck->setChecked(entry.racelock & IDB_RACE_NMC);
    ui->idbFriCheck->setChecked(entry.racelock & IDB_RACE_FRI);
    ui->idbMamCheck->setChecked(entry.racelock & IDB_RACE_MAM);
    ui->idbMafCheck->setChecked(entry.racelock & IDB_RACE_MAF);

    if (x2m->HasSSSkillDepend())
    {
        QString text = Utils::StdStringToQString(x2m->GetSSSkillDepend().name, false);
        text = ((x2m->SSSkillDependHasAttachment()) ? "EMBEDDED - " : "LINKED - ") + text;

        ui->idbBlastType->setItemText(0,  text);
        ui->idbBlastType->setDisabled(true);
        ui->idbCustomBlastButton->setText("Clear custom");
    }
    else
    {
        ui->idbBlastType->setItemText(0, "[DEFAULT]");
        ui->idbBlastType->setEnabled(true);
        ui->idbCustomBlastButton->setText("Set custom");
    }
}

void MainWindow::GuiToIdbEntry(IdbEntry &entry)
{
    entry.stars = (uint16_t) ui->idbStarsEdit->text().toInt();
    entry.dlc_flag = (uint16_t) ui->idbU0AEdit->text().toInt();
    entry.availability = (uint16_t) ui->idbU0CEdit->text().toInt();
    entry.unk_0E = (uint16_t) ui->idbU0EEdit->text().toInt();
    entry.buy = (uint32_t) ui->idbBuyEdit->text().toInt();
    entry.sell = (uint32_t) ui->idbSellEdit->text().toInt();
    entry.tp = (uint32_t) ui->idbTpEdit->text().toInt();    
    entry.unk_24[0] = (uint32_t) ui->idbU24Edit->text().toInt();
    entry.unk_24[1] = (uint32_t) ui->idbU28Edit->text().toInt();
    entry.unk_24[2] = (uint32_t) ui->idbU2CEdit->text().toInt();
    entry.new_unk_0C = (uint32_t) ui->idbNU0CEdit->text().toInt();
    entry.new_unk_0A = (uint16_t) ui->idbNU0AEdit->text().toInt();
    entry.new_unk_2C = (uint32_t) ui->idbNU2CEdit->text().toInt();
    entry.stp = (uint32_t) ui->idbStpEdit->text().toInt();

    entry.racelock = 0;

    if (ui->idbHumCheck->isChecked())
        entry.racelock |= IDB_RACE_HUM;

    if (ui->idbHufCheck->isChecked())
        entry.racelock |= IDB_RACE_HUF;

    if (ui->idbSymCheck->isChecked())
        entry.racelock |= IDB_RACE_SYM;

    if (ui->idbSyfCheck->isChecked())
        entry.racelock |= IDB_RACE_SYF;

    if (ui->idbNmcCheck->isChecked())
        entry.racelock |= IDB_RACE_NMC;

    if (ui->idbFriCheck->isChecked())
        entry.racelock |= IDB_RACE_FRI;

    if (ui->idbMamCheck->isChecked())
        entry.racelock |= IDB_RACE_MAM;

    if (ui->idbMafCheck->isChecked())
        entry.racelock |= IDB_RACE_MAF;

    entry.model = (uint32_t)ui->idbBlastType->currentIndex();
    if (x2m->HasSSSkillDepend())
        entry.model = 0;
}

void MainWindow::EditIdbEffect(IdbEffect &effect)
{
    IdbEffectDialog dialog(this, effect);

    if (!dialog.exec())
        return;

    effect = dialog.GetEffect();
}

void MainWindow::on_idbEff1Button_clicked()
{
    EditIdbEffect(x2m->GetSSItem().idb.effects[0]);
}

void MainWindow::on_idbEff2Button_clicked()
{
    EditIdbEffect(x2m->GetSSItem().idb.effects[1]);
}

void MainWindow::on_idbEff3Button_clicked()
{
    EditIdbEffect(x2m->GetSSItem().idb.effects[2]);
}

void MainWindow::on_idbCopyButton_triggered(QAction *arg1)
{
    if (arg1 == ui->actionFromGameIdb)
    {
        ListDialog dialog(ListMode::TALISMAN, this);

        if (!dialog.exec())
            return;

        int idx = dialog.GetResultData();

        if (idx < 0)
            return;

        const IdbEntry *in = game_talisman_idb->FindEntryByID(idx);
        if (!in)
            return;

        X2mItem &item = x2m->GetSSItem();

        bool copy_effects = true;
        IdbEffect effects[3];

        QMessageBox box(this);

        box.addButton("Copy effects too", QMessageBox::YesRole);
        box.addButton("Don't copy effects", QMessageBox::NoRole);
        box.setText("Do you want to copy the effects too?");
        box.setIcon(QMessageBox::Icon::Question);

        if (box.exec() != 0)
        {
            copy_effects = false;
            effects[0] = item.idb.effects[0];
            effects[1] = item.idb.effects[1];
            effects[2] = item.idb.effects[2];
        }

        item.idb = *in;
        item.idb.id = item.idb.name_id = item.idb.desc_id = X2M_DUMMY_ID16;

        if (!copy_effects)
        {
            item.idb.effects[0] = effects[0];
            item.idb.effects[1] = effects[1];
            item.idb.effects[2] = effects[2];
        }

        IdbEntryToGui(item.idb);
    }
}

int MainWindow::LinkOrEmbed(X2mFile *blast_x2m)
{
    QMessageBox box(this);
    QPushButton *link_button;
    QPushButton *embed_button;

    QString text = "Do you want to link this blast skill mod, or embed it?";

    if (blast_x2m)
    {
        text += "\n\nMod name: " + Utils::StdStringToQString(blast_x2m->GetModName(), false);
    }

    box.setWindowTitle("Link or embed?");
    box.setText(text);

    link_button = box.addButton("Link", QMessageBox::YesRole);
    embed_button = box.addButton("Embed", QMessageBox::YesRole);
    box.addButton(QMessageBox::Cancel);

    box.setDefaultButton(embed_button);

    box.exec();
    QAbstractButton *clicked = box.clickedButton();

    if (clicked == link_button)
    {
        return -1;
    }
    else if (clicked == embed_button)
    {
        return 1;
    }

    return 0;
}

void MainWindow::on_guidCopyButton_clicked()
{
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(ui->modGuidEdit->text());
}

void MainWindow::on_idbCustomBlastButton_clicked()
{
    if (x2m->HasSSSkillDepend())
    {
        GuiToIdbEntry(x2m->GetSSItem().idb);

        if (x2m->SSSkillDependHasAttachment())
            x2m->RemoveSSSkillDependAttachment();

        x2m->RemoveSSSkillDepend();
        IdbEntryToGui(x2m->GetSSItem().idb);
        return;
    }

    QString file = QFileDialog::getOpenFileName(this, "Select blast skill x2m", config.lf_depends_bskill, "X2M Files (*.x2m)");

    if (file.isNull())
        return;

    config.lf_depends_bskill = file;

    X2mFile blast_x2m;

    if (!blast_x2m.LoadFromFile(Utils::QStringToStdString(file)))
    {
        DPRINTF("Failed to load x2m.\n");
        return;
    }

    if (blast_x2m.GetType() != X2mType::NEW_SKILL || blast_x2m.GetSkillType() != X2mSkillType::BLAST)
    {
        DPRINTF("That x2m is not a blast skill one!\n");
        return;
    }

    if (!blast_x2m.BlastSkillSsIntended())
    {
        DPRINTF("This blast skill mod cannot be used as it is.\nPlease edit that mod and set \"This blast skill will be used by a Super Soul\"");
        return;
    }

    int ret = LinkOrEmbed(&blast_x2m);
    if (ret == 0)
        return;

    if (x2m->HasSSSkillDepend() && x2m->SSSkillDependHasAttachment())
    {
        x2m->RemoveSSSkillDependAttachment();
    }

    if (!x2m->SetSSSkillDepend(&blast_x2m))
    {
        DPRINTF("Failed to set the skill.\n");
        return;
    }

    GuiToIdbEntry(x2m->GetSSItem().idb);

    if (ret > 0)
    {
        if (!x2m->SetSSSkillDependAttachment(&blast_x2m))
        {
            DPRINTF("Failed to embed the skill.\n");
            x2m->RemoveSSSkillDepend();
        }
        else
        {
            ui->idbBlastType->setCurrentIndex(0);
        }
    }
    else
    {
        ui->idbBlastType->setCurrentIndex(0);
    }

    IdbEntryToGui(x2m->GetSSItem().idb);
}
