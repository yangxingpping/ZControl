#include "ZTableModel.h"

ZTableModel::ZTableModel(QObject* p /*= nullptr*/)
	:QAbstractTableModel(p)
{

}

ZTableModel::~ZTableModel()
{

}

int ZTableModel::rowCount(const QModelIndex& index) const
{
	return zrowCount(index);
}

int ZTableModel::columnCount(const QModelIndex& index) const
{
	return _roles.size();
}

QVariant ZTableModel::data(const QModelIndex& index, int role) const
{
	return zdata(index, role);
}

QHash<int, QByteArray> ZTableModel::roleNames() const
{
	return _roles;
}

QVariant ZTableModel::zdata(const QModelIndex& index, int role /*= Qt::DisplayRole*/) const
{
	assert(0);
	return QVariant();
}

int ZTableModel::zrowCount(const QModelIndex& index /*= QModelIndex()*/) const
{
	assert(0);
	return 0;
}

Qt::ItemFlags ZTableModel::flags(const QModelIndex& index) const
{
	if (!index.isValid())
		return Qt::NoItemFlags;
	return Qt::ItemIsEditable | QAbstractTableModel::flags(index);
}

