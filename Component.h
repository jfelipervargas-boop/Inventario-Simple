#ifndef COMPONENT_H
#define COMPONENT_H

#include <QString>

class Component {
public:

    int id_component;
    QString name;
    QString type;
    int quantity;
    int MinQuantity;
    int MaxQuantity;
    QString location;
    QString purchase_date;

    Component() {}

    Component(int idComp,
              const QString& name,
              const QString& type,
              int quantity,
              int minQty,
              int maxQty,
              const QString& location,
              const QString& purchaseDate)
        : id_component(idComp),
        name(name),
        type(type),
        quantity(quantity),
        MinQuantity(minQty),
        MaxQuantity(maxQty),
        location(location),
        purchase_date(purchaseDate)
    {}
};

#endif // COMPONENT_H
