#include "DatabaseManager.h"
#include <QDebug>

DatabaseManager::DatabaseManager(const QString& dbPath)
    : dbPath(dbPath)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbPath);
}

DatabaseManager::~DatabaseManager() {
    close();
}

bool DatabaseManager::open() {
    if (!db.open()) {
        qDebug() << "Error al abrir la base de datos:" << db.lastError().text();
        return false;
    }
    return createTable();
}

void DatabaseManager::close() {
    if (db.isOpen())
        db.close();
}

bool DatabaseManager::createTable() {
    QSqlQuery query;
    QString sql =
        "CREATE TABLE IF NOT EXISTS components ("
        "id_component INTEGER PRIMARY KEY AUTOINCREMENT,"
        "name TEXT NOT NULL,"
        "type TEXT,"
        "quantity INTEGER,"
        "MinQuantity INTEGER,"
        "MaxQuantity INTEGER,"
        "location TEXT,"
        "purchase_date TEXT"
        ");";

    if (!query.exec(sql)) {
        qDebug() << "Error creando tabla:" << query.lastError();
        return false;
    }
    return true;
}

bool DatabaseManager::insertComponent(const Component& comp) {
    QSqlQuery query;
    query.prepare(
        "INSERT INTO components (name, type, quantity, MinQuantity, MaxQuantity, location, purchase_date) "
        "VALUES (?, ?, ?, ?, ?, ?, ?)"
        );
    query.addBindValue(comp.name);
    query.addBindValue(comp.type);
    query.addBindValue(comp.quantity);
    query.addBindValue(comp.MinQuantity);
    query.addBindValue(comp.MaxQuantity);
    query.addBindValue(comp.location);
    query.addBindValue(comp.purchase_date);

    if (!query.exec()) {
        qDebug() << "Error insertando componente:" << query.lastError();
        return false;
    }

    int newID = query.lastInsertId().toInt();
    qDebug() << "INSERT OK. Nuevo ID generado por SQLite =" << newID;

    return true;
}


bool DatabaseManager::updateComponent(const Component& comp) {
    QSqlQuery query;
    query.prepare(
        "UPDATE components SET name=?, type=?, quantity=?, MinQuantity=?, MaxQuantity=?, location=?, purchase_date=? "
        "WHERE id_component=?"
        );
    query.addBindValue(comp.name);
    query.addBindValue(comp.type);
    query.addBindValue(comp.quantity);
    query.addBindValue(comp.MinQuantity);
    query.addBindValue(comp.MaxQuantity);
    query.addBindValue(comp.location);
    query.addBindValue(comp.purchase_date);
    query.addBindValue(comp.id_component);

    if (!query.exec()) {
        qDebug() << "Error actualizando componente:" << query.lastError();
        return false;
    }
    return query.numRowsAffected() > 0;
}

bool DatabaseManager::deleteComponent(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM components WHERE id_component=?");
    query.addBindValue(id);

    if (!query.exec()) {
        qDebug() << "Error eliminando componente:" << query.lastError();
        return false;
    }
    return query.numRowsAffected() > 0;
}

QVector<Component> DatabaseManager::getAllComponents() {
    QVector<Component> list;
    QSqlQuery query("SELECT * FROM components");

    while (query.next()) {
        Component c(
            query.value("id_component").toInt(),
            query.value("name").toString(),
            query.value("type").toString(),
            query.value("quantity").toInt(),
            query.value("MinQuantity").toInt(),
            query.value("MaxQuantity").toInt(),
            query.value("location").toString(),
            query.value("purchase_date").toString()
            );
        list.push_back(c);
    }

    return list;
}

Component DatabaseManager::getComponentById(int id) {
    QSqlQuery query;
    query.prepare("SELECT * FROM components WHERE id_component=?");
    query.addBindValue(id);
    Component c;

    if (query.exec() && query.next()) {
        c = Component(
            query.value("id_component").toInt(),
            query.value("name").toString(),
            query.value("type").toString(),
            query.value("quantity").toInt(),
            query.value("MinQuantity").toInt(),
            query.value("MaxQuantity").toInt(),
            query.value("location").toString(),
            query.value("purchase_date").toString()
            );
    }

    return c;
}

QVector<Component> DatabaseManager::searchComponents(const QString& condition) {
    QVector<Component> list;
    QString sql = "SELECT * FROM components";

    if (!condition.isEmpty()) {
        sql += " WHERE " + condition;
    }

    QSqlQuery query(sql);

    while (query.next()) {
        Component c(
            query.value("id_component").toInt(),
            query.value("name").toString(),
            query.value("type").toString(),
            query.value("quantity").toInt(),
            query.value("MinQuantity").toInt(),
            query.value("MaxQuantity").toInt(),
            query.value("location").toString(),
            query.value("purchase_date").toString()
            );
        list.push_back(c);
    }

    return list;
}
