#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "InventoryManager.h"
#include "addcomponentwindow.h"
#include "editcomponentwindow.h"
#include "confirmdeletedialog.h"

#include <QMessageBox>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QDir>


MainWindow::MainWindow(QWidget *parent, InventoryManager *inv)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , model(nullptr)
    , inventory(inv)
{
    ui->setupUi(this);

    setupModelAndView();
    loadTable();

    connect(ui->btnAdd,    &QPushButton::clicked, this, &MainWindow::onAddClicked);
    connect(ui->btnEdit,   &QPushButton::clicked, this, &MainWindow::onEditClicked);
    connect(ui->btnDelete, &QPushButton::clicked, this, &MainWindow::onDeleteClicked);
    connect(ui->Generate_Report, &QPushButton::clicked, this, &MainWindow::onGenerateReportClicked);
}

MainWindow::~MainWindow()
{
    delete model;
    delete ui;
}

void MainWindow::setupModelAndView()
{
    if (!ui->TableView) {
        qDebug() << "ERROR: La QTableView no existe o no se llama TableView.";
        return;
    }

    model = new QStandardItemModel(this);

    // Configuración consistente con loadTable()
    model->setColumnCount(6);
    model->setHorizontalHeaderLabels(
        {"ID", "Nombre", "Tipo", "Cantidad", "Ubicacion", "Fecha de Compra"}
        );

    ui->TableView->setModel(model);

    ui->TableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->TableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->TableView->horizontalHeader()->setStretchLastSection(true);
    ui->TableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->TableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void MainWindow::loadTable()
{
    if (!inventory) {
        qDebug() << "ERROR: InventoryManager no existe.";
        return;
    }
    if (!model) return;

    model->removeRows(0, model->rowCount());

    QVector<Component> list = inventory->getAll();
    model->setRowCount(list.size());

    for (int r = 0; r < list.size(); r++) {
        const Component &c = list[r];

        model->setItem(r, 0, new QStandardItem(QString::number(c.id_component)));
        model->setItem(r, 1, new QStandardItem(c.name));
        model->setItem(r, 2, new QStandardItem(c.type));
        model->setItem(r, 3, new QStandardItem(QString::number(c.quantity)));
        model->setItem(r, 4, new QStandardItem(c.location));
        model->setItem(r, 5, new QStandardItem(c.purchase_date));
    }
}

void MainWindow::onAddClicked()
{
    AddComponentWindow dlg(this);

    connect(&dlg, &AddComponentWindow::componentAdded,
            this, [&](const Component& c) {
                inventory->addComponent(c);
                loadTable();
            });

    dlg.exec();
}

void MainWindow::onEditClicked()
{
    QModelIndex idx = ui->TableView->currentIndex();
    if (!idx.isValid()) {
        QMessageBox::warning(this, "Error", "Selecciona un elemento.");
        return;
    }

    int row = idx.row();
    int id = model->item(row, 0)->text().toInt();  // columna 0 = ID

    Component comp = inventory->getById(id);

    EditComponentWindow dlg(comp, this);

    connect(&dlg, &EditComponentWindow::componentEdited,
            this, [&](Component updated) {
                inventory->updateComponent(updated);
                loadTable();
            });

    dlg.exec();
}

void MainWindow::onDeleteClicked()
{
    QModelIndex idx = ui->TableView->currentIndex();
    if (!idx.isValid()) {
        QMessageBox::warning(this, "Error", "Selecciona un elemento.");
        return;
    }

    int row = idx.row();
    int id = model->item(row, 0)->text().toInt();  // columna 0 = ID

    ConfirmDeleteDialog dlg(this);

    connect(&dlg, &ConfirmDeleteDialog::confirmed,
            this, [&]() {
                inventory->removeComponent(id);
                loadTable();
            });

    dlg.exec();
}

void MainWindow::onGenerateReportClicked()
{
    QString filename = "Reporte_Inventario.csv";
    QFile file(filename);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "No se pudo crear el archivo CSV.");
        return;
    }

    QTextStream out(&file);

    // Encabezados
    out << "ID,Nombre,Tipo,Cantidad,Ubicacion,Fecha de Compra\n";

    QVector<Component> list = inventory->getAll();

    for (int i = 0; i < list.size(); i++) {
        const Component &c = list[i];

        out << c.id_component << ","
            << c.name << ","
            << c.type << ","
            << c.quantity << ","
            << c.location << ","
            << c.purchase_date << "\n";
    }

    file.close();

    QMessageBox::information(this, "Reporte generado",
                             "El archivo CSV fue generado correctamente:\n" + filename);
}
