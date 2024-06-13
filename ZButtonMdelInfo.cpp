
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
		return "ff";
	}break;
	case ZButtonMdelInfo::ClientRole::iconUrl:
	{
		return "byd";
	}break;
    case ZButtonMdelInfo::ClientRole::maskUrl:
	{
		return "hello";
	}break;
	case ZButtonMdelInfo::ClientRole::zoptVal:
	{
		return "world";
	}
	default:
		break;
	}
	return QVariant();
}



