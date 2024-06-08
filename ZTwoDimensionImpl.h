#pragma once
#include "magic_enum.hpp"
#include "ZTwoDimension.h"
#include <QAbstractListModel>
#include <QLocale>
#include <QtQml>
#include <QVariant>
#include <memory>
#include <map>
#include <vector>

using std::map;
using std::unique_ptr;
using std::vector;

template<typename ValueType>
class ZTwoDimensionImpl : public ZTwoDimension
{
public:
	explicit ZTwoDimensionImpl(map<int, QByteArray> sysRoles, QObject* parent = nullptr)
		: ZTwoDimension(sysRoles, parent)
	{

	}
	virtual ~ZTwoDimensionImpl() override
	{}
	virtual QVariant zdata(const QModelIndex& index, int role = Qt::DisplayRole) const
	{
		return QVariant();
	}
	virtual int zrowCount(const QModelIndex& index = QModelIndex()) const
	{
		return 1;
	}
Q_SIGNALS:

public:
	//std::map<int, std::shared_ptr<ValueType> _d;
	QHash<int, QByteArray> _roles;
};
