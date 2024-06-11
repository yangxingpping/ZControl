
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
	};
	ZButtonMdelInfo();
	~ZButtonMdelInfo();
	QVariant getUser(ClientRole role);

	QString _name{ "name" };
	QString _iconUrl{ "qrc:/res/demo.svg" };
    QString _maskUrl{"qrc:/res/bottomCheckedMenuStyle.svg"};
};
