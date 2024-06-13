
#pragma once

#include <QVariant>

class ZButtonMdelInfo
{
public:
	enum class ClientRole
	{
		name,
		iconUrl,
        maskUrl,
		zoptVal,
	};
	ZButtonMdelInfo();
	~ZButtonMdelInfo();
	QVariant getUser(ClientRole role);

	QString _name{ "name" };
	QString _iconUrl{ "icon" };
    QString _maskUrl{"mask"};
};
