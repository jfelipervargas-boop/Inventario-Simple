#ifndef CONFIRMDELETEDIALOG_H
#define CONFIRMDELETEDIALOG_H

#include <QDialog>

namespace Ui {
class ConfirmDeleteDialog;
}

class ConfirmDeleteDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ConfirmDeleteDialog(QWidget *parent = nullptr);
    ~ConfirmDeleteDialog();

signals:
    void confirmed();

private slots:
    void on_btnYes_clicked();
    void on_btnNo_clicked();

private:
    Ui::ConfirmDeleteDialog *ui;
};

#endif // CONFIRMDELETEDIALOG_H
