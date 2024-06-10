
#pragma once

#include <QVariant>

class Demo
{
public:
	enum class ClientRole
	{
		name,
		iconUrl,
        maskUrl,
	};
	Demo();
	~Demo();
	QVariant getUser(ClientRole role);

	QString _name{ "name" };
	QString _iconUrl{ "qrc:/res/demo.svg" };
    QString _maskUrl{"qrc:/res/bottomCheckedMenuStyle.svg"};
};
