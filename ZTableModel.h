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
     QHash<int, QByteArray> roleNames() const override;

	 virtual QVariant zdata(const QModelIndex& index, int role = Qt::DisplayRole) const;
	 virtual int zrowCount(const QModelIndex& index = QModelIndex()) const;
     Qt::ItemFlags flags(const QModelIndex& index) const override;
 public:
	 QHash<int, QByteArray> _roles;
 };
