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
	explicit ZTableModelImpl(map<int, QByteArray> sysRoles, QObject* parent = nullptr)
        : ZTableModel(parent)
	{
		for (auto&& kv : sysRoles)
		{
			_roles.insert(kv.first, kv.second);
		}
		
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
		return magic_enum::enum_count<ClientRole>();
	}
Q_SIGNALS:

public:
	vector<unique_ptr<ValueType>> _data;
};
