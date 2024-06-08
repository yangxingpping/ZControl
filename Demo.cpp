
#include "Demo.h"

Demo::Demo()
{
}

Demo::~Demo()
{
}

QVariant Demo::getUser(ClientRole role)
{
	switch (role)
	{
	case Demo::ClientRole::name:
	{
		return _name;
	}break;
	case Demo::ClientRole::iconUrl:
	{
		return _iconUrl;
	}break;
	default:
		break;
	}
	return QVariant();
}



