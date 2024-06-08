
#pragma once

#include <QVariant>
#include <QObject>

class Demo
{
public:
	enum class ClientRole
	{
		Role1,
		Role2,
	};

	QVariant getSys(int role);
	QVariant getUser(ClientRole role);
};
