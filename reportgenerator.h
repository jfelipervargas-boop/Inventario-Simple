#ifndef REPORTMANAGER_H
#define REPORTMANAGER_H

#include <QString>
#include <QVector>
#include "Component.h"

class ReportManager {
public:
    ReportManager() = default;

    bool generateCSV(const QVector<Component>& list, const QString& filePath);
    bool generatePDF(const QVector<Component>& list, const QString& filePath);
};

#endif // REPORTMANAGER_H
