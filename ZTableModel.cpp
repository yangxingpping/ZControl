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
	return zcolumnCount(index);
}

QVariant ZTableModel::data(const QModelIndex& index, int role) const
{
	return zdata(index, role);
}

bool ZTableModel::setData(const QModelIndex& index, const QVariant& value, int role /*= Qt::EditRole*/)
{
	return zsetData(index, value, role);
}

QHash<int, QByteArray> ZTableModel::roleNames() const
{
	assert(!_roles.isEmpty());
	return _roles;
}

QVariant ZTableModel::headerData(int section, Qt::Orientation orientation, int role /*= Qt::DisplayRole*/) const
{
	if (role == Qt::DisplayRole) {
		if (orientation == Qt::Horizontal) {
			switch (section) {
			case 0: return QString("Item");
			case 1: return QString("Detail");
			}
		}
		else if (orientation == Qt::Vertical) {
			return QString::number(section + 1);
		}
	}
	return QVariant();

}

bool ZTableModel::insertRows(int row, int count, const QModelIndex& parent)
{
	bool ret{ false };
	beginInsertRows(parent, row, row + count - 1);
	ret = zinsertRows(row, count, parent);
	endInsertRows();
	return ret;
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

int ZTableModel::zcolumnCount(const QModelIndex& index) const
{
	assert(0);
	return 0;
}

bool ZTableModel::zsetData(const QModelIndex& index, const QVariant& value, int role /*= Qt::EditRole*/)
{
	assert(0);
	return false;
}

bool ZTableModel::zinsertRows(int row, int count, const QModelIndex& parent)
{
	assert(0);
	return false;
}

Qt::ItemFlags ZTableModel::flags(const QModelIndex& index) const
{
	if (!index.isValid())
		return Qt::NoItemFlags;
	return /*Qt::ItemIsEditable |*/ QAbstractTableModel::flags(index);
}

