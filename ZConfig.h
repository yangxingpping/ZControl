
#pragma once

#include "zstdafx.h"
#include <QColor>
#include <QObject>
#include <QtQml>

class ZConfig : public QObject
{
	Q_OBJECT
	QML_ELEMENT
	Q_PROPERTY_AUTO(QColor, color)
	//QML_NAMED_ELEMENT(gconf);
	QML_SINGLETON
public:
	explicit ZConfig(QObject* parent = nullptr);
};
