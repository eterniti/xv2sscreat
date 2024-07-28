#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>
#include <QCheckBox>
#include <QLineEdit>
#include "X2mFile.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    bool Initialize();

private slots:
    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionExit_triggered();

    void on_actionAbout_triggered();

    void on_guidButton_clicked();    

    void on_ssNameLangComboBox_currentIndexChanged(int index);

    void on_ssNameEdit_textEdited(const QString &arg1);

    void on_ssNameCopyButton_clicked();

    void on_addEditButton_clicked();

    void on_ssDescLangComboBox_currentIndexChanged(int index);

    void on_ssDescEdit_textChanged();

    void on_ssDescCopyButton_clicked();

    void on_idbEff1Button_clicked();

    void on_idbEff2Button_clicked();

    void on_idbEff3Button_clicked();

    void on_idbCopyButton_triggered(QAction *arg1);

    void on_guidCopyButton_clicked();   

    void on_ssHowLangComboBox_currentIndexChanged(int index);

    void on_ssHowEdit_textChanged();

    void on_ssHowCopyButton_clicked();

    void on_idbCustomBlastButton_clicked();

protected:
    void closeEvent(QCloseEvent *event);

private:
    Ui::MainWindow *ui;
    X2mFile *x2m;

    std::string temp_skill_dir;
    std::string temp_skill_prefix;
    uint16_t temp_skill_id2;
    uint16_t temp_skill_id1;

    std::vector<QString> bcs_bodies;

    int prev_trans_index=-1;
    int prev_pup_index=-1;
    int prev_aura_index=-1;
    int prev_body_index=-1;

    bool ProcessShutdown();

    void ProcessX2m();
    bool Validate();
    bool Build();

    void IdbEntryToGui(const IdbEntry &entry);
    void GuiToIdbEntry(IdbEntry &entry);
    void EditIdbEffect(IdbEffect &effect);

    int LinkOrEmbed(X2mFile *cost_x2m);
};

#endif // MAINWINDOW_H
