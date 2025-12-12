#include "editcomponentwindow.h"
#include "ui_editcomponentwindow.h"

EditComponentWindow::EditComponentWindow(Component comp, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::EditComponentWindow)
    , original(comp)
{
    ui->setupUi(this);

    ui->txtId->setText(QString::number(comp.id_component));
    ui->txtName->setText(comp.name);
    ui->txtType->setText(comp.type);
    ui->txtQuantity->setText(QString::number(comp.quantity));
    ui->txtMin->setText(QString::number(comp.MinQuantity));
    ui->txtMax->setText(QString::number(comp.MaxQuantity));
    ui->txtLocation->setText(comp.location);
    ui->txtDate->setText(comp.purchase_date);
}

EditComponentWindow::~EditComponentWindow()
{
    delete ui;
}

void EditComponentWindow::on_btnSave_clicked()
{
    Component c(
        ui->txtId->text().toInt(),
        ui->txtName->text(),
        ui->txtType->text(),
        ui->txtQuantity->text().toInt(),
        ui->txtMin->text().toInt(),
        ui->txtMax->text().toInt(),
        ui->txtLocation->text(),
        ui->txtDate->text()
        );

    emit componentEdited(c);
    close();
}

void EditComponentWindow::on_btnCancel_clicked()
{
    close();
}
