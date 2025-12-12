#include <QApplication>
#include "mainwindow.h"
#include "DatabaseManager.h"
#include "InventoryManager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    DatabaseManager *db = new DatabaseManager("inventory.db");
    if (!db->open()) {
        qCritical() << "No se pudo abrir/crear la base de datos";
        return -1;
    }

    InventoryManager *inventory = new InventoryManager(db);

    MainWindow w(nullptr, inventory);
    w.show();

    return a.exec();
}
