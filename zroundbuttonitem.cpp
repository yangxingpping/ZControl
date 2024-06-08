
#include "zroundbuttonitem.h"

#include <QtMath>

#include <cmath>

ZRoundButtonItem::ZRoundButtonItem(QObject *parent)
    : QAbstractListModel(parent)
{
}

ZRoundButtonItem::~ZRoundButtonItem()
{
}

int ZRoundButtonItem::rowCount(const QModelIndex &index) const
{
    if (index.parent().isValid()) {
        return 0;
    }
    return 0;
}

QVariant ZRoundButtonItem::data(const QModelIndex &index, int role) const
{
    switch (role) 
    {
    case ZRoundButtonItem::DisplayRole:
    {

    }break;
    default:
    {
    }break;
    }
    return QVariant();
}

QHash<int, QByteArray> ZRoundButtonItem::roleNames() const
{
    return 
    {
        {ZRoundButtonItem::DisplayRole, QByteArrayLiteral("display")},
        {ZRoundButtonItem::IconRole, QByteArrayLiteral("icon")} 
    };
}
