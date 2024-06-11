
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
	default:
		break;
	}
	return QVariant();
}



