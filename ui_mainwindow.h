/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionExit;
    QAction *actionAbout;
    QAction *actionFromGameIdb;
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *modInfoTab;
    QLineEdit *modNameEdit;
    QLabel *label_2;
    QPushButton *guidButton;
    QLabel *label;
    QLineEdit *modVersionEdit;
    QLineEdit *modAuthorEdit;
    QLabel *label_5;
    QLabel *label_4;
    QLineEdit *modGuidEdit;
    QComboBox *ssNameLangComboBox;
    QLabel *label_3;
    QLineEdit *ssNameEdit;
    QPushButton *ssNameCopyButton;
    QLabel *label_32;
    QTextEdit *ssDescEdit;
    QComboBox *ssDescLangComboBox;
    QPushButton *ssDescCopyButton;
    QPushButton *guidCopyButton;
    QLabel *label_113;
    QTextEdit *ssHowEdit;
    QComboBox *ssHowLangComboBox;
    QPushButton *ssHowCopyButton;
    QWidget *filesTab;
    QLabel *label_8;
    QLabel *label_9;
    QLineEdit *addDataEdit;
    QPushButton *addEditButton;
    QWidget *idbTab;
    QLabel *label_20;
    QCheckBox *idbHumCheck;
    QCheckBox *idbNmcCheck;
    QCheckBox *idbSymCheck;
    QCheckBox *idbHufCheck;
    QLabel *label_19;
    QCheckBox *idbMamCheck;
    QCheckBox *idbMafCheck;
    QCheckBox *idbFriCheck;
    QCheckBox *idbSyfCheck;
    QLineEdit *idbStarsEdit;
    QLabel *label_33;
    QToolButton *idbCopyButton;
    QLineEdit *idbU0AEdit;
    QLabel *label_34;
    QLineEdit *idbU0CEdit;
    QLineEdit *idbU0EEdit;
    QLabel *label_35;
    QLabel *label_36;
    QLineEdit *idbBuyEdit;
    QLineEdit *idbSellEdit;
    QLabel *label_37;
    QLineEdit *idbTpEdit;
    QLabel *label_38;
    QLineEdit *idbU24Edit;
    QLineEdit *idbU28Edit;
    QLabel *label_40;
    QLabel *label_41;
    QLabel *label_42;
    QLineEdit *idbU2CEdit;
    QLabel *label_43;
    QPushButton *idbEff1Button;
    QPushButton *idbEff2Button;
    QPushButton *idbEff3Button;
    QLabel *label_44;
    QLabel *label_45;
    QLineEdit *idbNU0CEdit;
    QLabel *label_106;
    QLineEdit *idbStpEdit;
    QLabel *label_114;
    QLineEdit *idbNU0AEdit;
    QLabel *label_115;
    QLineEdit *idbNU2CEdit;
    QLabel *label_116;
    QComboBox *idbBlastType;
    QLabel *label_6;
    QPushButton *idbCustomBlastButton;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(661, 589);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionFromGameIdb = new QAction(MainWindow);
        actionFromGameIdb->setObjectName(QStringLiteral("actionFromGameIdb"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(20, 20, 621, 500));
        tabWidget->setAutoFillBackground(true);
        modInfoTab = new QWidget();
        modInfoTab->setObjectName(QStringLiteral("modInfoTab"));
        modInfoTab->setAutoFillBackground(true);
        modNameEdit = new QLineEdit(modInfoTab);
        modNameEdit->setObjectName(QStringLiteral("modNameEdit"));
        modNameEdit->setGeometry(QRect(70, 21, 315, 20));
        label_2 = new QLabel(modInfoTab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 103, 47, 13));
        guidButton = new QPushButton(modInfoTab);
        guidButton->setObjectName(QStringLiteral("guidButton"));
        guidButton->setGeometry(QRect(300, 140, 91, 23));
        label = new QLabel(modInfoTab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(28, 23, 51, 16));
        modVersionEdit = new QLineEdit(modInfoTab);
        modVersionEdit->setObjectName(QStringLiteral("modVersionEdit"));
        modVersionEdit->setGeometry(QRect(70, 101, 61, 20));
        modAuthorEdit = new QLineEdit(modInfoTab);
        modAuthorEdit->setObjectName(QStringLiteral("modAuthorEdit"));
        modAuthorEdit->setGeometry(QRect(70, 61, 215, 20));
        label_5 = new QLabel(modInfoTab);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(23, 183, 51, 16));
        label_4 = new QLabel(modInfoTab);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(31, 143, 31, 16));
        modGuidEdit = new QLineEdit(modInfoTab);
        modGuidEdit->setObjectName(QStringLiteral("modGuidEdit"));
        modGuidEdit->setEnabled(false);
        modGuidEdit->setGeometry(QRect(70, 141, 215, 20));
        ssNameLangComboBox = new QComboBox(modInfoTab);
        ssNameLangComboBox->setObjectName(QStringLiteral("ssNameLangComboBox"));
        ssNameLangComboBox->setGeometry(QRect(400, 180, 91, 22));
        label_3 = new QLabel(modInfoTab);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(22, 63, 47, 13));
        ssNameEdit = new QLineEdit(modInfoTab);
        ssNameEdit->setObjectName(QStringLiteral("ssNameEdit"));
        ssNameEdit->setGeometry(QRect(70, 181, 315, 20));
        ssNameCopyButton = new QPushButton(modInfoTab);
        ssNameCopyButton->setObjectName(QStringLiteral("ssNameCopyButton"));
        ssNameCopyButton->setGeometry(QRect(500, 180, 95, 23));
        label_32 = new QLabel(modInfoTab);
        label_32->setObjectName(QStringLiteral("label_32"));
        label_32->setGeometry(QRect(24, 223, 71, 16));
        ssDescEdit = new QTextEdit(modInfoTab);
        ssDescEdit->setObjectName(QStringLiteral("ssDescEdit"));
        ssDescEdit->setGeometry(QRect(70, 223, 315, 91));
        ssDescLangComboBox = new QComboBox(modInfoTab);
        ssDescLangComboBox->setObjectName(QStringLiteral("ssDescLangComboBox"));
        ssDescLangComboBox->setGeometry(QRect(400, 223, 91, 22));
        ssDescCopyButton = new QPushButton(modInfoTab);
        ssDescCopyButton->setObjectName(QStringLiteral("ssDescCopyButton"));
        ssDescCopyButton->setGeometry(QRect(500, 223, 95, 23));
        guidCopyButton = new QPushButton(modInfoTab);
        guidCopyButton->setObjectName(QStringLiteral("guidCopyButton"));
        guidCopyButton->setGeometry(QRect(405, 140, 95, 23));
        label_113 = new QLabel(modInfoTab);
        label_113->setObjectName(QStringLiteral("label_113"));
        label_113->setGeometry(QRect(29, 330, 49, 16));
        ssHowEdit = new QTextEdit(modInfoTab);
        ssHowEdit->setObjectName(QStringLiteral("ssHowEdit"));
        ssHowEdit->setGeometry(QRect(70, 330, 315, 91));
        ssHowLangComboBox = new QComboBox(modInfoTab);
        ssHowLangComboBox->setObjectName(QStringLiteral("ssHowLangComboBox"));
        ssHowLangComboBox->setGeometry(QRect(400, 330, 91, 22));
        ssHowCopyButton = new QPushButton(modInfoTab);
        ssHowCopyButton->setObjectName(QStringLiteral("ssHowCopyButton"));
        ssHowCopyButton->setGeometry(QRect(500, 330, 95, 23));
        tabWidget->addTab(modInfoTab, QString());
        filesTab = new QWidget();
        filesTab->setObjectName(QStringLiteral("filesTab"));
        filesTab->setAutoFillBackground(true);
        label_8 = new QLabel(filesTab);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 23, 101, 16));
        label_9 = new QLabel(filesTab);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 63, 381, 16));
        addDataEdit = new QLineEdit(filesTab);
        addDataEdit->setObjectName(QStringLiteral("addDataEdit"));
        addDataEdit->setGeometry(QRect(100, 21, 425, 20));
        addEditButton = new QPushButton(filesTab);
        addEditButton->setObjectName(QStringLiteral("addEditButton"));
        addEditButton->setGeometry(QRect(535, 20, 61, 23));
        tabWidget->addTab(filesTab, QString());
        idbTab = new QWidget();
        idbTab->setObjectName(QStringLiteral("idbTab"));
        idbTab->setAutoFillBackground(true);
        label_20 = new QLabel(idbTab);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(79, 110, 31, 16));
        idbHumCheck = new QCheckBox(idbTab);
        idbHumCheck->setObjectName(QStringLiteral("idbHumCheck"));
        idbHumCheck->setGeometry(QRect(70, 70, 51, 17));
        idbNmcCheck = new QCheckBox(idbTab);
        idbNmcCheck->setObjectName(QStringLiteral("idbNmcCheck"));
        idbNmcCheck->setGeometry(QRect(310, 70, 51, 17));
        idbSymCheck = new QCheckBox(idbTab);
        idbSymCheck->setObjectName(QStringLiteral("idbSymCheck"));
        idbSymCheck->setGeometry(QRect(190, 70, 51, 17));
        idbHufCheck = new QCheckBox(idbTab);
        idbHufCheck->setObjectName(QStringLiteral("idbHufCheck"));
        idbHufCheck->setGeometry(QRect(130, 70, 51, 17));
        label_19 = new QLabel(idbTab);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(10, 70, 61, 16));
        idbMamCheck = new QCheckBox(idbTab);
        idbMamCheck->setObjectName(QStringLiteral("idbMamCheck"));
        idbMamCheck->setGeometry(QRect(430, 70, 51, 17));
        idbMafCheck = new QCheckBox(idbTab);
        idbMafCheck->setObjectName(QStringLiteral("idbMafCheck"));
        idbMafCheck->setGeometry(QRect(490, 70, 51, 17));
        idbFriCheck = new QCheckBox(idbTab);
        idbFriCheck->setObjectName(QStringLiteral("idbFriCheck"));
        idbFriCheck->setGeometry(QRect(370, 70, 51, 17));
        idbSyfCheck = new QCheckBox(idbTab);
        idbSyfCheck->setObjectName(QStringLiteral("idbSyfCheck"));
        idbSyfCheck->setGeometry(QRect(250, 70, 51, 17));
        idbStarsEdit = new QLineEdit(idbTab);
        idbStarsEdit->setObjectName(QStringLiteral("idbStarsEdit"));
        idbStarsEdit->setGeometry(QRect(120, 108, 75, 20));
        label_33 = new QLabel(idbTab);
        label_33->setObjectName(QStringLiteral("label_33"));
        label_33->setGeometry(QRect(260, 110, 47, 13));
        idbCopyButton = new QToolButton(idbTab);
        idbCopyButton->setObjectName(QStringLiteral("idbCopyButton"));
        idbCopyButton->setGeometry(QRect(10, 23, 75, 23));
        idbCopyButton->setPopupMode(QToolButton::InstantPopup);
        idbCopyButton->setToolButtonStyle(Qt::ToolButtonTextOnly);
        idbU0AEdit = new QLineEdit(idbTab);
        idbU0AEdit->setObjectName(QStringLiteral("idbU0AEdit"));
        idbU0AEdit->setGeometry(QRect(300, 108, 75, 20));
        label_34 = new QLabel(idbTab);
        label_34->setObjectName(QStringLiteral("label_34"));
        label_34->setGeometry(QRect(50, 150, 71, 16));
        idbU0CEdit = new QLineEdit(idbTab);
        idbU0CEdit->setObjectName(QStringLiteral("idbU0CEdit"));
        idbU0CEdit->setGeometry(QRect(120, 148, 75, 20));
        idbU0EEdit = new QLineEdit(idbTab);
        idbU0EEdit->setObjectName(QStringLiteral("idbU0EEdit"));
        idbU0EEdit->setGeometry(QRect(300, 148, 75, 20));
        label_35 = new QLabel(idbTab);
        label_35->setObjectName(QStringLiteral("label_35"));
        label_35->setGeometry(QRect(260, 150, 47, 13));
        label_36 = new QLabel(idbTab);
        label_36->setObjectName(QStringLiteral("label_36"));
        label_36->setGeometry(QRect(85, 190, 41, 16));
        idbBuyEdit = new QLineEdit(idbTab);
        idbBuyEdit->setObjectName(QStringLiteral("idbBuyEdit"));
        idbBuyEdit->setGeometry(QRect(120, 188, 75, 20));
        idbSellEdit = new QLineEdit(idbTab);
        idbSellEdit->setObjectName(QStringLiteral("idbSellEdit"));
        idbSellEdit->setGeometry(QRect(300, 188, 75, 20));
        label_37 = new QLabel(idbTab);
        label_37->setObjectName(QStringLiteral("label_37"));
        label_37->setGeometry(QRect(269, 190, 31, 16));
        idbTpEdit = new QLineEdit(idbTab);
        idbTpEdit->setObjectName(QStringLiteral("idbTpEdit"));
        idbTpEdit->setGeometry(QRect(120, 228, 75, 20));
        label_38 = new QLabel(idbTab);
        label_38->setObjectName(QStringLiteral("label_38"));
        label_38->setGeometry(QRect(90, 230, 31, 16));
        idbU24Edit = new QLineEdit(idbTab);
        idbU24Edit->setObjectName(QStringLiteral("idbU24Edit"));
        idbU24Edit->setGeometry(QRect(120, 268, 75, 20));
        idbU28Edit = new QLineEdit(idbTab);
        idbU28Edit->setObjectName(QStringLiteral("idbU28Edit"));
        idbU28Edit->setGeometry(QRect(300, 268, 75, 20));
        label_40 = new QLabel(idbTab);
        label_40->setObjectName(QStringLiteral("label_40"));
        label_40->setGeometry(QRect(78, 270, 41, 16));
        label_41 = new QLabel(idbTab);
        label_41->setObjectName(QStringLiteral("label_41"));
        label_41->setGeometry(QRect(260, 270, 41, 16));
        label_42 = new QLabel(idbTab);
        label_42->setObjectName(QStringLiteral("label_42"));
        label_42->setGeometry(QRect(440, 270, 47, 13));
        idbU2CEdit = new QLineEdit(idbTab);
        idbU2CEdit->setObjectName(QStringLiteral("idbU2CEdit"));
        idbU2CEdit->setGeometry(QRect(480, 268, 75, 20));
        label_43 = new QLabel(idbTab);
        label_43->setObjectName(QStringLiteral("label_43"));
        label_43->setGeometry(QRect(66, 310, 47, 13));
        idbEff1Button = new QPushButton(idbTab);
        idbEff1Button->setObjectName(QStringLiteral("idbEff1Button"));
        idbEff1Button->setGeometry(QRect(120, 305, 75, 23));
        idbEff2Button = new QPushButton(idbTab);
        idbEff2Button->setObjectName(QStringLiteral("idbEff2Button"));
        idbEff2Button->setGeometry(QRect(300, 305, 75, 23));
        idbEff3Button = new QPushButton(idbTab);
        idbEff3Button->setObjectName(QStringLiteral("idbEff3Button"));
        idbEff3Button->setGeometry(QRect(480, 305, 75, 23));
        label_44 = new QLabel(idbTab);
        label_44->setObjectName(QStringLiteral("label_44"));
        label_44->setGeometry(QRect(247, 310, 47, 13));
        label_45 = new QLabel(idbTab);
        label_45->setObjectName(QStringLiteral("label_45"));
        label_45->setGeometry(QRect(427, 310, 47, 13));
        idbNU0CEdit = new QLineEdit(idbTab);
        idbNU0CEdit->setObjectName(QStringLiteral("idbNU0CEdit"));
        idbNU0CEdit->setGeometry(QRect(480, 228, 75, 20));
        label_106 = new QLabel(idbTab);
        label_106->setObjectName(QStringLiteral("label_106"));
        label_106->setGeometry(QRect(437, 230, 47, 13));
        idbStpEdit = new QLineEdit(idbTab);
        idbStpEdit->setObjectName(QStringLiteral("idbStpEdit"));
        idbStpEdit->setGeometry(QRect(300, 228, 75, 20));
        label_114 = new QLabel(idbTab);
        label_114->setObjectName(QStringLiteral("label_114"));
        label_114->setGeometry(QRect(270, 230, 31, 16));
        idbNU0AEdit = new QLineEdit(idbTab);
        idbNU0AEdit->setObjectName(QStringLiteral("idbNU0AEdit"));
        idbNU0AEdit->setGeometry(QRect(480, 108, 75, 20));
        label_115 = new QLabel(idbTab);
        label_115->setObjectName(QStringLiteral("label_115"));
        label_115->setGeometry(QRect(436, 110, 49, 16));
        idbNU2CEdit = new QLineEdit(idbTab);
        idbNU2CEdit->setObjectName(QStringLiteral("idbNU2CEdit"));
        idbNU2CEdit->setGeometry(QRect(480, 148, 75, 20));
        label_116 = new QLabel(idbTab);
        label_116->setObjectName(QStringLiteral("label_116"));
        label_116->setGeometry(QRect(436, 150, 49, 16));
        idbBlastType = new QComboBox(idbTab);
        idbBlastType->setObjectName(QStringLiteral("idbBlastType"));
        idbBlastType->setGeometry(QRect(120, 348, 253, 22));
        label_6 = new QLabel(idbTab);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(55, 350, 71, 16));
        idbCustomBlastButton = new QPushButton(idbTab);
        idbCustomBlastButton->setObjectName(QStringLiteral("idbCustomBlastButton"));
        idbCustomBlastButton->setGeometry(QRect(390, 348, 75, 24));
        tabWidget->addTab(idbTab, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 661, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuHelp->addAction(actionAbout);
        mainToolBar->addAction(actionOpen);
        mainToolBar->addAction(actionSave);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "XV2 Super Soul Creator", 0));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", 0));
        actionSave->setText(QApplication::translate("MainWindow", "Save as...", 0));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0));
        actionAbout->setText(QApplication::translate("MainWindow", "About", 0));
        actionFromGameIdb->setText(QApplication::translate("MainWindow", "From game", 0));
#ifndef QT_NO_TOOLTIP
        actionFromGameIdb->setToolTip(QApplication::translate("MainWindow", "From game", 0));
#endif // QT_NO_TOOLTIP
        label_2->setText(QApplication::translate("MainWindow", "Version:", 0));
        guidButton->setText(QApplication::translate("MainWindow", "Generate new", 0));
        label->setText(QApplication::translate("MainWindow", "Name:", 0));
        label_5->setText(QApplication::translate("MainWindow", "Name:", 0));
        label_4->setText(QApplication::translate("MainWindow", "GUID:", 0));
        ssNameLangComboBox->clear();
        ssNameLangComboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "English", 0)
         << QApplication::translate("MainWindow", "Spanish (es)", 0)
         << QApplication::translate("MainWindow", "Spanish (ca)", 0)
         << QApplication::translate("MainWindow", "French", 0)
         << QApplication::translate("MainWindow", "German", 0)
         << QApplication::translate("MainWindow", "Italian", 0)
         << QApplication::translate("MainWindow", "Portuguese", 0)
         << QApplication::translate("MainWindow", "Polish", 0)
         << QApplication::translate("MainWindow", "Russian", 0)
         << QApplication::translate("MainWindow", "Chinese (tw)", 0)
         << QApplication::translate("MainWindow", "Chinese (zh)", 0)
         << QApplication::translate("MainWindow", "Korean", 0)
         << QApplication::translate("MainWindow", "Japanese", 0)
        );
        label_3->setText(QApplication::translate("MainWindow", "Author:", 0));
        ssNameCopyButton->setText(QApplication::translate("MainWindow", "Copy from game", 0));
        label_32->setText(QApplication::translate("MainWindow", "Desc.:", 0));
        ssDescLangComboBox->clear();
        ssDescLangComboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "English", 0)
         << QApplication::translate("MainWindow", "Spanish (es)", 0)
         << QApplication::translate("MainWindow", "Spanish (ca)", 0)
         << QApplication::translate("MainWindow", "French", 0)
         << QApplication::translate("MainWindow", "German", 0)
         << QApplication::translate("MainWindow", "Italian", 0)
         << QApplication::translate("MainWindow", "Portuguese", 0)
         << QApplication::translate("MainWindow", "Polish", 0)
         << QApplication::translate("MainWindow", "Russian", 0)
         << QApplication::translate("MainWindow", "Chinese (tw)", 0)
         << QApplication::translate("MainWindow", "Chinese (zh)", 0)
         << QApplication::translate("MainWindow", "Korean", 0)
         << QApplication::translate("MainWindow", "Japanese", 0)
        );
        ssDescCopyButton->setText(QApplication::translate("MainWindow", "Copy from game", 0));
        guidCopyButton->setText(QApplication::translate("MainWindow", "Copy to clipboard", 0));
        label_113->setText(QApplication::translate("MainWindow", "How:", 0));
        ssHowLangComboBox->clear();
        ssHowLangComboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "English", 0)
         << QApplication::translate("MainWindow", "Spanish (es)", 0)
         << QApplication::translate("MainWindow", "Spanish (ca)", 0)
         << QApplication::translate("MainWindow", "French", 0)
         << QApplication::translate("MainWindow", "German", 0)
         << QApplication::translate("MainWindow", "Italian", 0)
         << QApplication::translate("MainWindow", "Portuguese", 0)
         << QApplication::translate("MainWindow", "Polish", 0)
         << QApplication::translate("MainWindow", "Russian", 0)
         << QApplication::translate("MainWindow", "Chinese (tw)", 0)
         << QApplication::translate("MainWindow", "Chinese (zh)", 0)
         << QApplication::translate("MainWindow", "Korean", 0)
         << QApplication::translate("MainWindow", "Japanese", 0)
        );
        ssHowCopyButton->setText(QApplication::translate("MainWindow", "Copy from game", 0));
        tabWidget->setTabText(tabWidget->indexOf(modInfoTab), QApplication::translate("MainWindow", "Mod info", 0));
        label_8->setText(QApplication::translate("MainWindow", "Additional data*:", 0));
        label_9->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:600;\">*This directory is optional. Use with care and only when needed!</span></p></body></html>", 0));
        addEditButton->setText(QApplication::translate("MainWindow", "Change", 0));
        tabWidget->setTabText(tabWidget->indexOf(filesTab), QApplication::translate("MainWindow", "Files", 0));
        label_20->setText(QApplication::translate("MainWindow", "Stars:", 0));
        idbHumCheck->setText(QApplication::translate("MainWindow", "HUM", 0));
        idbNmcCheck->setText(QApplication::translate("MainWindow", "NMC", 0));
        idbSymCheck->setText(QApplication::translate("MainWindow", "SYM", 0));
        idbHufCheck->setText(QApplication::translate("MainWindow", "HUF", 0));
        label_19->setText(QApplication::translate("MainWindow", "Race lock:", 0));
        idbMamCheck->setText(QApplication::translate("MainWindow", "MAM", 0));
        idbMafCheck->setText(QApplication::translate("MainWindow", "MAF", 0));
        idbFriCheck->setText(QApplication::translate("MainWindow", "FRI", 0));
        idbSyfCheck->setText(QApplication::translate("MainWindow", "SYF", 0));
        label_33->setText(QApplication::translate("MainWindow", "U_0A:", 0));
        idbCopyButton->setText(QApplication::translate("MainWindow", "Copy", 0));
        label_34->setText(QApplication::translate("MainWindow", "Availability:", 0));
        label_35->setText(QApplication::translate("MainWindow", "U_0E:", 0));
        label_36->setText(QApplication::translate("MainWindow", "Buy:", 0));
        label_37->setText(QApplication::translate("MainWindow", "Sell:", 0));
        label_38->setText(QApplication::translate("MainWindow", "TP:", 0));
        label_40->setText(QApplication::translate("MainWindow", "U_24:", 0));
        label_41->setText(QApplication::translate("MainWindow", "U_28:", 0));
        label_42->setText(QApplication::translate("MainWindow", "U_2C:", 0));
        label_43->setText(QApplication::translate("MainWindow", "Effect 1:", 0));
        idbEff1Button->setText(QApplication::translate("MainWindow", "Edit", 0));
        idbEff2Button->setText(QApplication::translate("MainWindow", "Edit", 0));
        idbEff3Button->setText(QApplication::translate("MainWindow", "Edit", 0));
        label_44->setText(QApplication::translate("MainWindow", "Effect 2:", 0));
        label_45->setText(QApplication::translate("MainWindow", "Effect 3:", 0));
        label_106->setText(QApplication::translate("MainWindow", "NU_0C:", 0));
        label_114->setText(QApplication::translate("MainWindow", "STP:", 0));
        label_115->setText(QApplication::translate("MainWindow", "NU_0A:", 0));
        label_116->setText(QApplication::translate("MainWindow", "NU_2C:", 0));
        idbBlastType->clear();
        idbBlastType->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "[DEFAULT]", 0)
        );
        label_6->setText(QApplication::translate("MainWindow", "Blast type:", 0));
        idbCustomBlastButton->setText(QApplication::translate("MainWindow", "Set custom", 0));
        tabWidget->setTabText(tabWidget->indexOf(idbTab), QApplication::translate("MainWindow", "IDB", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
