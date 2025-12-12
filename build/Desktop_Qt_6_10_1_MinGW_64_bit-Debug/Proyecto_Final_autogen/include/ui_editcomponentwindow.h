/********************************************************************************
** Form generated from reading UI file 'editcomponentwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITCOMPONENTWINDOW_H
#define UI_EDITCOMPONENTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_EditComponentWindow
{
public:
    QLineEdit *txtType;
    QLineEdit *txtMax;
    QLineEdit *txtName;
    QPushButton *btnCancel;
    QLineEdit *txtLocation;
    QLineEdit *txtDate;
    QPushButton *btnSave;
    QLineEdit *txtQuantity;
    QLineEdit *txtId;
    QLineEdit *txtMin;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_4;
    QLabel *label_3;
    QLabel *label_8;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_7;

    void setupUi(QDialog *EditComponentWindow)
    {
        if (EditComponentWindow->objectName().isEmpty())
            EditComponentWindow->setObjectName("EditComponentWindow");
        EditComponentWindow->resize(249, 333);
        txtType = new QLineEdit(EditComponentWindow);
        txtType->setObjectName("txtType");
        txtType->setGeometry(QRect(120, 70, 111, 31));
        txtMax = new QLineEdit(EditComponentWindow);
        txtMax->setObjectName("txtMax");
        txtMax->setGeometry(QRect(120, 160, 111, 31));
        txtName = new QLineEdit(EditComponentWindow);
        txtName->setObjectName("txtName");
        txtName->setGeometry(QRect(120, 40, 111, 31));
        btnCancel = new QPushButton(EditComponentWindow);
        btnCancel->setObjectName("btnCancel");
        btnCancel->setGeometry(QRect(60, 290, 121, 24));
        txtLocation = new QLineEdit(EditComponentWindow);
        txtLocation->setObjectName("txtLocation");
        txtLocation->setGeometry(QRect(120, 190, 111, 31));
        txtDate = new QLineEdit(EditComponentWindow);
        txtDate->setObjectName("txtDate");
        txtDate->setGeometry(QRect(120, 220, 111, 31));
        btnSave = new QPushButton(EditComponentWindow);
        btnSave->setObjectName("btnSave");
        btnSave->setGeometry(QRect(60, 260, 121, 24));
        txtQuantity = new QLineEdit(EditComponentWindow);
        txtQuantity->setObjectName("txtQuantity");
        txtQuantity->setGeometry(QRect(120, 100, 111, 31));
        txtId = new QLineEdit(EditComponentWindow);
        txtId->setObjectName("txtId");
        txtId->setGeometry(QRect(120, 10, 111, 31));
        txtMin = new QLineEdit(EditComponentWindow);
        txtMin->setObjectName("txtMin");
        txtMin->setGeometry(QRect(120, 130, 111, 31));
        label_5 = new QLabel(EditComponentWindow);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 130, 101, 20));
        label_6 = new QLabel(EditComponentWindow);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(20, 160, 101, 20));
        label_4 = new QLabel(EditComponentWindow);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(40, 110, 49, 16));
        label_3 = new QLabel(EditComponentWindow);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(50, 80, 49, 16));
        label_8 = new QLabel(EditComponentWindow);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(10, 220, 101, 20));
        label_2 = new QLabel(EditComponentWindow);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(40, 50, 49, 16));
        label = new QLabel(EditComponentWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(60, 14, 49, 16));
        label_7 = new QLabel(EditComponentWindow);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(40, 190, 61, 20));

        retranslateUi(EditComponentWindow);

        QMetaObject::connectSlotsByName(EditComponentWindow);
    } // setupUi

    void retranslateUi(QDialog *EditComponentWindow)
    {
        EditComponentWindow->setWindowTitle(QCoreApplication::translate("EditComponentWindow", "Dialog", nullptr));
        btnCancel->setText(QCoreApplication::translate("EditComponentWindow", "Cancelar", nullptr));
        btnSave->setText(QCoreApplication::translate("EditComponentWindow", "Guardar", nullptr));
        label_5->setText(QCoreApplication::translate("EditComponentWindow", "Cantidad Minima", nullptr));
        label_6->setText(QCoreApplication::translate("EditComponentWindow", "Cantidad Maxima", nullptr));
        label_4->setText(QCoreApplication::translate("EditComponentWindow", "Cantidad", nullptr));
        label_3->setText(QCoreApplication::translate("EditComponentWindow", "Tipo", nullptr));
        label_8->setText(QCoreApplication::translate("EditComponentWindow", "Fecha de Compra", nullptr));
        label_2->setText(QCoreApplication::translate("EditComponentWindow", "Nombre", nullptr));
        label->setText(QCoreApplication::translate("EditComponentWindow", "Id", nullptr));
        label_7->setText(QCoreApplication::translate("EditComponentWindow", "Ubicacion", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditComponentWindow: public Ui_EditComponentWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITCOMPONENTWINDOW_H
