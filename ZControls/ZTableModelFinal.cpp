#include "ZTableModelFinal.h"

ZTableModelFinal::ZTableModelFinal(QObject* p /*= nullptr*/)
	:QAbstractTableModel(p)
{
	_roles = { {Qt::DisplayRole, "display"} };
}

ZTableModelFinal::~ZTableModelFinal()
{

}

int ZTableModelFinal::rowCount(const QModelIndex& index) const
{
	return _v.size();
}

int ZTableModelFinal::columnCount(const QModelIndex& index) const
{
	return 1;
}

QVariant ZTableModelFinal::data(const QModelIndex& index, int role) const
{
	return _v[index.row()];
}

QHash<int, QByteArray> ZTableModelFinal::roleNames() const
{
	return _roles;
}

bool ZTableModelFinal::setData(const QModelIndex& index, const QVariant& value, int role /*= Qt::EditRole*/)
{
	_v[index.row()] = value.toString();
	emit dataChanged(index, index);
	return true;
}

QVariant ZTableModelFinal::headerData(int section, Qt::Orientation orientation, int role /*= Qt::DisplayRole*/) const
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

QVariant ZTableModelFinal::zdata(const QModelIndex& index, int role /*= Qt::DisplayRole*/) const
{
	assert(0);
	return QVariant();
}

int ZTableModelFinal::zrowCount(const QModelIndex& index /*= QModelIndex()*/) const
{
	assert(0);
	return 0;
}

int ZTableModelFinal::zcolumnCount(const QModelIndex& index) const
{
	assert(0);
	return 0;
}

bool ZTableModelFinal::zsetData(const QModelIndex& index, const QVariant& value, int role /*= Qt::EditRole*/)
{
	assert(0);
	return false;
}

Qt::ItemFlags ZTableModelFinal::flags(const QModelIndex& index) const
{
	if (!index.isValid())
		return Qt::NoItemFlags;
	return Qt::ItemIsEditable | QAbstractTableModel::flags(index);
}

