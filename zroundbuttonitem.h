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

template<typename RowItem>
class ZTwoDimension : public QAbstractListModel
{
	Q_OBJECT
		QML_ELEMENT
public:
	using ClientRoles = typename RowItem::ClientRoles;
	static_assert(std::is_enum_v<typename RowItem::ClientRoles>);
	explicit ZTwoDimension(map<int, QByteArray> sysRoles, QObject* parent = nullptr)
		:QAbstractListModel(parent)
		, _roles(sysRoles)
	{
		if (!sysRoles.empty())
		{
			assert(sysRoles.rbegin()->first < Qt::UserRole);
		}
		constexpr auto roleEntries = magic_enum::enum_entries<ClientRoles>();
		for (auto&& kv : roleEntries)
		{
			_roles.insert({ magic_enum::enum_integer(kv.first), magic_enum::enum_name(kv.second) });
		}
	}
	virtual ~ZTwoDimension() override
	{
	}
	int rowCount(const QModelIndex& index = QModelIndex()) const override
	{
		auto pret = _d.count();
		int ret = static_cast<int>(pret);
		return ret;
	}
	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override
	{
		auto rowindx = index.row();
		auto it = _d.find(rowindx);
		if (it == _d.end())
		{
			return QVariant();
		}
		if (role < Qt::UserRole)
		{
			return it->second->getSys(role);
		}
		else
		{
			auto opte = magic_enum::enum_cast<ClientRoles>(role - Qt::UserRole);
			if (!opte.has_vale())
			{
				return QVariant();
			}
			return QVariant();
			//return it->second->getUser()
		}
	}
	QHash<int, QByteArray> roleNames() const override
	{
		return _roles;
	}
Q_SIGNALS:

public:
	map<int, unique_ptr<RowItem>> _d;
	map<int, QByteArray> _roles;
};
