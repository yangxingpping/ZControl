
#pragma once

#include <QVariant>

class Demo
{
public:
	enum class ClientRole
	{
		name,
		iconUrl,
	};
	Demo();
	~Demo();
	QVariant getUser(ClientRole role);

	QString _name{ "name" };
	QString _iconUrl{ "qrc:/demo.svg" };
};
