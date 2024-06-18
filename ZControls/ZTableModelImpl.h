#pragma once
#include "magic_enum.hpp"
#include "ZTableModel.h"
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
class ZTableModelImpl : public ZTableModel
{
public:
	using ClientRole = typename ValueType::ClientRole;
	static_assert(std::is_enum_v<ClientRole>);
	explicit ZTableModelImpl(QObject* parent = nullptr, map<int, QByteArray> sysRoles = {})
        : ZTableModel(parent)
	{
		for (auto&& kv : sysRoles)
		{
			_roles.insert(kv.first, kv.second);
		}
		
	}
	ZTableModelImpl(ZTableModelImpl& ref)
		:_data(ref._data)
		,_roles(ref._roles)
	{
	}
	ZTableModelImpl(ZTableModelImpl&& ref)
		:_roles(std::move(ref._roles))
		, _data(std::move(ref._data))
	{
	}
	ZTableModelImpl& operator=(const ZTableModelImpl& p)
	{
		_roles = p._roles;
		_data = p._data;
	}
	virtual ~ZTableModelImpl()
	{}
	virtual QVariant zdata(const QModelIndex& index, int role = Qt::DisplayRole) const override
	{
		if (_data.size() <= index.row())
		{
			assert(0);
			return QVariant();
		}
		if (role == Qt::DisplayRole)
		{
			auto opte = magic_enum::enum_cast<ClientRole>(index.column());
			assert(opte.has_value());
			return _data[index.row()]->getUser(opte.value());
		}
		return QVariant();
	}
	virtual int zrowCount(const QModelIndex& index = QModelIndex()) const override
	{
		return _data.size();
	}
	virtual int zcolumnCount(const QModelIndex& index) const override
	{
		int ret = magic_enum::enum_count<ClientRole>();
		return ret;
	}
	virtual bool zsetData(const QModelIndex& index, const QVariant& value, int role = Qt::DisplayRole)
	{
		bool ret{ false };
		auto opte = magic_enum::enum_cast<ClientRole>(index.column());
		if(!opte.has_value())
		{
			return false;
		}
		ret = _data[index.row()]->setUser(opte.value(), value);
		emit dataChanged(index, index, { role });
		return ret;
	}

	virtual bool zsetData2(int row, ClientRole col,  const QVariant& value, int role = Qt::DisplayRole)
	{
		bool ret{ false };
		ret = zsetData(this->index(row, magic_enum::enum_integer(col)), value, role);
		/*ret = _data[row]->setUser(col, value);
		emit dataChanged(index, index, { role });*/
		return ret;
	}

	virtual bool zinsertRows(int row, int count, const QModelIndex& parent = QModelIndex()) override
	{
		while(_data.size() < row+count)
		{
			_data.push_back(std::make_unique<ValueType>());
		}
		return true;
	}
Q_SIGNALS:

public:
	vector<unique_ptr<ValueType>> _data;
};
