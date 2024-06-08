#pragma once
#include <QAbstractListModel>
#include <QLocale>
#include <QtQml>
#include <memory>
#include <map>

using std::map;
using std::unique_ptr;
class ButtonDetail;
class ZRoundButtonItem : public QAbstractListModel
{
    Q_OBJECT
    QML_ELEMENT
public:
    explicit ZRoundButtonItem(QObject *parent = nullptr);
    ~ZRoundButtonItem() override;
    enum Roles 
    {
        DisplayRole = Qt::DisplayRole,
        IconRole,
    };
    int rowCount(const QModelIndex &index = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;
Q_SIGNALS:

private:
    map<int, unique_ptr<ButtonDetail>> _d;
};
