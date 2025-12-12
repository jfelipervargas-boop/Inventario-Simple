/********************************************************************************
** Form generated from reading UI file 'addcomponentwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDCOMPONENTWINDOW_H
#define UI_ADDCOMPONENTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AddComponentWindow
{
public:
    QPushButton *btnSave;
    QPushButton *btnCancel;
    QLineEdit *txtId;
    QLineEdit *txtName;
    QLineEdit *txtQuantity;
    QLineEdit *txtType;
    QLineEdit *txtMax;
    QLineEdit *txtMin;
    QLineEdit *txtDate;
    QLineEdit *txtLocation;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;

    void setupUi(QDialog *AddComponentWindow)
    {
        if (AddComponentWindow->objectName().isEmpty())
            AddComponentWindow->setObjectName("AddComponentWindow");
        AddComponentWindow->resize(230, 332);
        btnSave = new QPushButton(AddComponentWindow);
        btnSave->setObjectName("btnSave");
        btnSave->setGeometry(QRect(50, 260, 121, 24));
        btnCancel = new QPushButton(AddComponentWindow);
        btnCancel->setObjectName("btnCancel");
        btnCancel->setGeometry(QRect(50, 290, 121, 24));
        txtId = new QLineEdit(AddComponentWindow);
        txtId->setObjectName("txtId");
        txtId->setGeometry(QRect(110, 10, 111, 31));
        txtName = new QLineEdit(AddComponentWindow);
        txtName->setObjectName("txtName");
        txtName->setGeometry(QRect(110, 40, 111, 31));
        txtQuantity = new QLineEdit(AddComponentWindow);
        txtQuantity->setObjectName("txtQuantity");
        txtQuantity->setGeometry(QRect(110, 100, 111, 31));
        txtType = new QLineEdit(AddComponentWindow);
        txtType->setObjectName("txtType");
        txtType->setGeometry(QRect(110, 70, 111, 31));
        txtMax = new QLineEdit(AddComponentWindow);
        txtMax->setObjectName("txtMax");
        txtMax->setGeometry(QRect(110, 160, 111, 31));
        txtMin = new QLineEdit(AddComponentWindow);
        txtMin->setObjectName("txtMin");
        txtMin->setGeometry(QRect(110, 130, 111, 31));
        txtDate = new QLineEdit(AddComponentWindow);
        txtDate->setObjectName("txtDate");
        txtDate->setGeometry(QRect(110, 220, 111, 31));
        txtLocation = new QLineEdit(AddComponentWindow);
        txtLocation->setObjectName("txtLocation");
        txtLocation->setGeometry(QRect(110, 190, 111, 31));
        label = new QLabel(AddComponentWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 20, 49, 16));
        label_2 = new QLabel(AddComponentWindow);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 50, 49, 16));
        label_3 = new QLabel(AddComponentWindow);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(40, 80, 49, 16));
        label_4 = new QLabel(AddComponentWindow);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(30, 110, 49, 16));
        label_5 = new QLabel(AddComponentWindow);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 130, 101, 20));
        label_6 = new QLabel(AddComponentWindow);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(10, 160, 101, 20));
        label_7 = new QLabel(AddComponentWindow);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(30, 196, 61, 20));
        label_8 = new QLabel(AddComponentWindow);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(10, 220, 101, 20));

        retranslateUi(AddComponentWindow);

        QMetaObject::connectSlotsByName(AddComponentWindow);
    } // setupUi

    void retranslateUi(QDialog *AddComponentWindow)
    {
        AddComponentWindow->setWindowTitle(QCoreApplication::translate("AddComponentWindow", "Dialog", nullptr));
        btnSave->setText(QCoreApplication::translate("AddComponentWindow", "Guardar", nullptr));
        btnCancel->setText(QCoreApplication::translate("AddComponentWindow", "Cancelar", nullptr));
        label->setText(QCoreApplication::translate("AddComponentWindow", "Id", nullptr));
        label_2->setText(QCoreApplication::translate("AddComponentWindow", "Nombre", nullptr));
        label_3->setText(QCoreApplication::translate("AddComponentWindow", "Tipo", nullptr));
        label_4->setText(QCoreApplication::translate("AddComponentWindow", "Cantidad", nullptr));
        label_5->setText(QCoreApplication::translate("AddComponentWindow", "Cantidad Minima", nullptr));
        label_6->setText(QCoreApplication::translate("AddComponentWindow", "Cantidad Maxima", nullptr));
        label_7->setText(QCoreApplication::translate("AddComponentWindow", "Ubicacion", nullptr));
        label_8->setText(QCoreApplication::translate("AddComponentWindow", "Fecha de Compra", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddComponentWindow: public Ui_AddComponentWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCOMPONENTWINDOW_H
