#ifndef EDITCOMPONENTWINDOW_H
#define EDITCOMPONENTWINDOW_H

#include <QDialog>
#include "Component.h"

namespace Ui {
class EditComponentWindow;
}

class EditComponentWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EditComponentWindow(Component comp, QWidget *parent = nullptr);
    ~EditComponentWindow();

signals:
    void componentEdited(Component c);

private slots:
    void on_btnSave_clicked();
    void on_btnCancel_clicked();

private:
    Ui::EditComponentWindow *ui;
    Component original;
};

#endif // EDITCOMPONENTWINDOW_H
