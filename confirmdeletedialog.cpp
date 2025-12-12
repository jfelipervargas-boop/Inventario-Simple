#include "confirmdeletedialog.h"
#include "ui_confirmdeletedialog.h"

ConfirmDeleteDialog::ConfirmDeleteDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ConfirmDeleteDialog)
{
    ui->setupUi(this);
}

ConfirmDeleteDialog::~ConfirmDeleteDialog()
{
    delete ui;
}

void ConfirmDeleteDialog::on_btnYes_clicked()
{
    emit confirmed();
    close();
}

void ConfirmDeleteDialog::on_btnNo_clicked()
{
    close();
}
