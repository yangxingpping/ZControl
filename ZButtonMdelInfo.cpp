
#include "ZButtonMdelInfo.h"

ZButtonMdelInfo::ZButtonMdelInfo()
{
}

ZButtonMdelInfo::~ZButtonMdelInfo()
{
}

QVariant ZButtonMdelInfo::getUser(ClientRole role)
{
	switch (role)
	{
	case ZButtonMdelInfo::ClientRole::name:
	{
		return _name;
	}break;
	case ZButtonMdelInfo::ClientRole::iconUrl:
	{
		return _iconUrl;
	}break;
    case ZButtonMdelInfo::ClientRole::maskUrl:
	{
		return _maskUrl;
	}break;
	case ZButtonMdelInfo::ClientRole::zoptVal:
	{
		return _name;
	}
	default:
		break;
	}
	return QVariant();
}



