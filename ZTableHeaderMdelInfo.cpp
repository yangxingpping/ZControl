
#include "ZTableHeaderMdelInfo.h"

ZTableHeaderMdelInfo::ZTableHeaderMdelInfo()
{
}

ZTableHeaderMdelInfo::~ZTableHeaderMdelInfo()
{
}

QVariant ZTableHeaderMdelInfo::getUser(ClientRole role)
{
	switch (role)
	{
	case ZTableHeaderMdelInfo::ClientRole::name:
	{
		return _name;
	}break;
	case ZTableHeaderMdelInfo::ClientRole::iconUrl:
	{
		return _iconUrl;
	}break;
    case ZTableHeaderMdelInfo::ClientRole::maskUrl:
	{
		return _maskUrl;
	}break;
	case ZTableHeaderMdelInfo::ClientRole::zoptVal:
	{
		return "four";
	}
	default:
		break;
	}
	return QVariant();
}



