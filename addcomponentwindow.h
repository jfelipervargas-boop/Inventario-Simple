#ifndef ADDCOMPONENTWINDOW_H
#define ADDCOMPONENTWINDOW_H

#include <QDialog>
#include "Component.h"

namespace Ui {
class AddComponentWindow;
}

class AddComponentWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AddComponentWindow(QWidget *parent = nullptr);
    ~AddComponentWindow();

signals:
    void componentAdded(const Component& c);


private slots:
    void on_btnSave_clicked();
    void on_btnCancel_clicked();

private:
    Ui::AddComponentWindow *ui;
};

#endif // ADDCOMPONENTWINDOW_H
