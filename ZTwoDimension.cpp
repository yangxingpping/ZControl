#pragma once
#include "magic_enum.hpp"
#include "ZTwoDimension.h"
#include <QLocale>
#include <QtQml>
#include <memory>
#include <map>
#include <vector>

using std::map;
using std::unique_ptr;
using std::vector;



ZTwoDimension::ZTwoDimension(map<int, QByteArray> sysRoles, QObject* parent)
	:QAbstractListModel(parent)
{
	if (!sysRoles.empty())
	{
		assert(sysRoles.rbegin()->first < Qt::UserRole);
	}
	for (auto&& kv : sysRoles)
	{
		_roles.insert(kv.first, kv.second);
	}
}
ZTwoDimension::~ZTwoDimension()
{
}
int ZTwoDimension::rowCount(const QModelIndex& index) const
{
	return zrowCount(index);
}
QVariant ZTwoDimension::data(const QModelIndex& index, int role) const
{
	return zdata(index, role);
}
QHash<int, QByteArray> ZTwoDimension::roleNames() const
{
	return _roles;
}
