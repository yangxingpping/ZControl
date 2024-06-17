#pragma once

 #include <qqml.h>
 #include <QAbstractTableModel>

 class ZTableModel : public QAbstractTableModel
 {
     Q_OBJECT
     QML_ELEMENT

 public:
     ZTableModel(QObject* p = nullptr);
     virtual ~ZTableModel();
     int rowCount(const QModelIndex & = QModelIndex()) const override;
     int columnCount(const QModelIndex & = QModelIndex()) const override;
     QVariant data(const QModelIndex& index, int role) const override;
     bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole) override;
     QHash<int, QByteArray> roleNames() const override;
     Qt::ItemFlags flags(const QModelIndex& index) const override;
     QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
     bool insertRows(int row, int count, const QModelIndex& parent = QModelIndex()) override;

	 virtual QVariant zdata(const QModelIndex& index, int role = Qt::DisplayRole) const;
	 virtual int zrowCount(const QModelIndex& index = QModelIndex()) const;
     virtual int zcolumnCount(const QModelIndex& index) const;
     virtual bool zsetData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole);
     virtual bool zinsertRows(int row, int count, const QModelIndex& parent = QModelIndex());

 public:
	 QHash<int, QByteArray> _roles;
 };
