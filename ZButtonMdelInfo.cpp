
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
		return "byd";
	}break;
    case ZButtonMdelInfo::ClientRole::maskUrl:
	{
		return "helloA";
	}break;
	case ZButtonMdelInfo::ClientRole::zoptVal:
	{
		return "worldB";
	}
	case ZButtonMdelInfo::ClientRole::optVal2:
	{
		return "nextH";
	}break;
	default:
		break;
	}
	return QVariant();
}



