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

template<class ValueType>
class ZTwoDimensionImpl : public ZTwoDimension
{
public:
	using ClientRole = typename ValueType::ClientRole;
	static_assert(std::is_enum_v<ClientRole>);
	explicit ZTwoDimensionImpl(map<int, QByteArray> sysRoles, QObject* parent = nullptr)
		: ZTwoDimension(sysRoles, parent)
	{
		constexpr auto entries = magic_enum::enum_entries<ClientRole>();
		for (auto&& kv : entries)
		{
			_roles.insert(magic_enum::enum_integer(kv.first) + Qt::UserRole, QByteArrayLiteral(kv.second.data()));
		}
	}
	virtual ~ZTwoDimensionImpl() override
	{}
	virtual QVariant zdata(const QModelIndex& index, int role = Qt::DisplayRole) const
	{
		auto it = _data.find(index.row());
		if (it == _data.end())
		{
			return QVariant();
		}
		if (role >= Qt::UserRole)
		{
			auto opte = magic_enum::enum_cast<ClientRole>(role - Qt::UserRole);
			assert(opte.has_value());
			return it->second->getUser(opte.value());
		}
		return QVariant();
	}
	virtual int zrowCount(const QModelIndex& index = QModelIndex()) const
	{
		return _data.size();
	}
Q_SIGNALS:

public:
	map<int, unique_ptr<ValueType>> _data;
};
