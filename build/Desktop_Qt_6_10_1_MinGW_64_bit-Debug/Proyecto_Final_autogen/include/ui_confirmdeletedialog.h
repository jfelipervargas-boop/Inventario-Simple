/********************************************************************************
** Form generated from reading UI file 'confirmdeletedialog.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIRMDELETEDIALOG_H
#define UI_CONFIRMDELETEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ConfirmDeleteDialog
{
public:
    QPushButton *btnYes;
    QPushButton *btnNo;
    QLabel *label;

    void setupUi(QDialog *ConfirmDeleteDialog)
    {
        if (ConfirmDeleteDialog->objectName().isEmpty())
            ConfirmDeleteDialog->setObjectName("ConfirmDeleteDialog");
        ConfirmDeleteDialog->resize(203, 112);
        btnYes = new QPushButton(ConfirmDeleteDialog);
        btnYes->setObjectName("btnYes");
        btnYes->setGeometry(QRect(10, 60, 80, 24));
        btnNo = new QPushButton(ConfirmDeleteDialog);
        btnNo->setObjectName("btnNo");
        btnNo->setGeometry(QRect(110, 60, 80, 24));
        label = new QLabel(ConfirmDeleteDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 20, 161, 20));

        retranslateUi(ConfirmDeleteDialog);

        QMetaObject::connectSlotsByName(ConfirmDeleteDialog);
    } // setupUi

    void retranslateUi(QDialog *ConfirmDeleteDialog)
    {
        ConfirmDeleteDialog->setWindowTitle(QCoreApplication::translate("ConfirmDeleteDialog", "Dialog", nullptr));
        btnYes->setText(QCoreApplication::translate("ConfirmDeleteDialog", "Si", nullptr));
        btnNo->setText(QCoreApplication::translate("ConfirmDeleteDialog", "No", nullptr));
        label->setText(QCoreApplication::translate("ConfirmDeleteDialog", "\302\277Eliminar este Componente?", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConfirmDeleteDialog: public Ui_ConfirmDeleteDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIRMDELETEDIALOG_H
