#include "addcomponentwindow.h"
#include "ui_addcomponentwindow.h"
#include <QMessageBox>

AddComponentWindow::AddComponentWindow(QWidget *parent)
    : QDialog(parent), ui(new Ui::AddComponentWindow)
{
    ui->setupUi(this);
}

AddComponentWindow::~AddComponentWindow()
{
    delete ui;
}

void AddComponentWindow::on_btnSave_clicked()
{
    Component c;

    // NO SE ASIGNA ID — SQLite lo genera automáticamente
    c.name = ui->txtName->text();
    c.type = ui->txtType->text();
    c.location = ui->txtLocation->text();
    c.purchase_date = ui->txtDate->text();
    c.quantity = ui->txtQuantity->text().toInt();
    c.MinQuantity = ui->txtMin->text().toInt();
    c.MaxQuantity = ui->txtMax->text().toInt();

    if (c.name.isEmpty()) {
        QMessageBox::warning(this, "Datos incompletos", "El Nombre es obligatorio.");
        return;
    }

    emit componentAdded(c);
    accept();
}

void AddComponentWindow::on_btnCancel_clicked()
{
    reject();
}
