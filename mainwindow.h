#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>

#include "InventoryManager.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr, InventoryManager *inv = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QStandardItemModel *model;
    InventoryManager *inventory;

    void setupModelAndView();
    void loadTable();

private slots:
    void onAddClicked();
    void onEditClicked();
    void onDeleteClicked();
    void onGenerateReportClicked();

};

#endif // MAINWINDOW_H
