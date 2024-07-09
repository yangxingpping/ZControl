
#pragma once
#include "os.h"
#include <QVariant>

class ZCONTROLPLUGIN_EXPORT ZButtonModelInfo
{
public:
	enum class ClientRole
	{
		name,
		iconUrl,
		maskUrl,
		zoptVal,
		optVal2,
	};
	ZButtonModelInfo();
	~ZButtonModelInfo();
	QVariant getUser(ClientRole role);

	QString _name{ "name" };
	QString _iconUrl{ "icon" };
	QString _maskUrl{ "mask" };
};
