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

QHash<int, QByteArray> ZTableModel::roleNames() const
{
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

Qt::ItemFlags ZTableModel::flags(const QModelIndex& index) const
{
	if (!index.isValid())
		return Qt::NoItemFlags;
	return Qt::ItemIsEditable | QAbstractTableModel::flags(index);
}

