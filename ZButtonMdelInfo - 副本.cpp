
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
		return "hello";
	}break;
	case ZButtonMdelInfo::ClientRole::zoptVal:
	{
		return "world";
	}
	case ZButtonMdelInfo::ClientRole::optVal:
	{
		return "next";
	}break;
	default:
		break;
	}
	return QVariant();
}



