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
		//QML_ELEMENT
public:
	using ClientRole = typename RowItem::ClientRole;
	static_assert(std::is_enum_v<typename RowItem::ClientRole>);
	explicit ZTwoDimension(map<int, QByteArray> sysRoles, QObject* parent = nullptr)
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
		constexpr auto roleEntries = magic_enum::enum_entries<ClientRole>();
		for (auto&& kv : roleEntries)
		{
			//_roles.insert(magic_enum::enum_integer(kv.first), magic_enum::enum_name(kv.second));
		}
	}
	virtual ~ZTwoDimension() override
	{
	}
	int rowCount(const QModelIndex& index = QModelIndex()) const override
	{
		auto pret = _d.size();
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
			auto opte = magic_enum::enum_cast<ClientRole>(role - Qt::UserRole);
			if (!opte.has_value())
			{
				return QVariant();
			}
			return it->second->getUser(opte.value());
		}
	}
	QHash<int, QByteArray> roleNames() const override
	{
		return _roles;
	}
Q_SIGNALS:

public:
	map<int, unique_ptr<RowItem>> _d;
	QHash<int, QByteArray> _roles;
};
