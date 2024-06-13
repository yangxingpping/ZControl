
#pragma once

#include <QVariant>

class ZTableHeaderMdelInfo
{
public:
	enum class ClientRole
	{
		name,
		iconUrl,
		maskUrl,
		zoptVal,
	};
	ZTableHeaderMdelInfo();
	~ZTableHeaderMdelInfo();
	QVariant getUser(ClientRole role);

	QString _name{ "name" };
	QString _iconUrl{ "qrc:/res/demo.svg" };
    QString _maskUrl{"qrc:/res/bottomCheckedMenuStyle.svg"};
};
