#pragma once
#include "magic_enum.hpp"
#include <QAbstractListModel>
#include <QLocale>
#include <QtQml>
#include <memory>
#include <map>
#include <vector>

using std::map;
using std::unique_ptr;
using std::vector;


class ZTwoDimension : public QAbstractListModel
{
	Q_OBJECT;
	QML_ELEMENT;
public:
	explicit ZTwoDimension(map<int, QByteArray> sysRoles, QObject* parent = nullptr);
	virtual ~ZTwoDimension() override;
	int rowCount(const QModelIndex& index = QModelIndex()) const override;
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
	QHash<int, QByteArray> roleNames() const override;

	virtual QVariant zdata(const QModelIndex& index, int role = Qt::DisplayRole) const = 0;
	virtual int zrowCount(const QModelIndex& index = QModelIndex()) const = 0;
Q_SIGNALS:

public:
	QHash<int, QByteArray> _roles;
};
