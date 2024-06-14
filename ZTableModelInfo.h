
#pragma once

#include <QVariant>

class ZTableModelInfo
{
public:
	enum class ClientRole
	{
		name,
		iconUrl,
        maskUrl,
		zoptVal,
	};
	ZTableModelInfo();
	~ZTableModelInfo();
	QVariant getUser(ClientRole role);
	bool setUser(ClientRole role,const QVariant& d);

	QString _name{ "name" };
	QString _iconUrl{ "icon" };
    QString _maskUrl{"mask"};
};
