#pragma once
#include <QAbstractListModel>
#include <QLocale>
#include <QtQml>
#include <memory>
#include <map>

using std::map;
using std::unique_ptr;

template<typename RowItem, enum class Roles>
class ZRoundButtonItem : public QAbstractListModel
{
    Q_OBJECT
    QML_ELEMENT
public:
    explicit ZRoundButtonItem(QObject *parent = nullptr)
        :QAbstractListModel(parent)
    {
    }
    virtual ~ZRoundButtonItem() override
    {
    }
    int rowCount(const QModelIndex &index = QModelIndex()) const override
    {
    }
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override
    {
    }
    QHash<int, QByteArray> roleNames() const override
    {
    }
Q_SIGNALS:

public:
    map<int, unique_ptr<RowItem>> _d;
};
