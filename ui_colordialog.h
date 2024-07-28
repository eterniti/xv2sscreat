/********************************************************************************
** Form generated from reading UI file 'colordialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COLORDIALOG_H
#define UI_COLORDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_ColorDialog
{
public:
    QDialogButtonBox *buttonBox;
    QCheckBox *noColorCheck;

    void setupUi(QDialog *ColorDialog)
    {
        if (ColorDialog->objectName().isEmpty())
            ColorDialog->setObjectName(QStringLiteral("ColorDialog"));
        ColorDialog->resize(570, 670);
        buttonBox = new QDialogButtonBox(ColorDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(0, 620, 561, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);
        noColorCheck = new QCheckBox(ColorDialog);
        noColorCheck->setObjectName(QStringLiteral("noColorCheck"));
        noColorCheck->setGeometry(QRect(40, 595, 70, 17));

        retranslateUi(ColorDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ColorDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ColorDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ColorDialog);
    } // setupUi

    void retranslateUi(QDialog *ColorDialog)
    {
        ColorDialog->setWindowTitle(QApplication::translate("ColorDialog", "Select color", 0));
        noColorCheck->setText(QApplication::translate("ColorDialog", "No color", 0));
    } // retranslateUi

};

namespace Ui {
    class ColorDialog: public Ui_ColorDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COLORDIALOG_H
