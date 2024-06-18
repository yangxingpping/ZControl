
#include "ZButtonModelInfo.h"

ZButtonModelInfo::ZButtonModelInfo()
{
}

ZButtonModelInfo::~ZButtonModelInfo()
{
}

QVariant ZButtonModelInfo::getUser(ClientRole role)
{
	switch (role)
	{
	case ZButtonModelInfo::ClientRole::name:
	{
		return _name;
	}break;
	case ZButtonModelInfo::ClientRole::iconUrl:
	{
		return "byd";
	}break;
    case ZButtonModelInfo::ClientRole::maskUrl:
	{
		return "helloA";
	}break;
	case ZButtonModelInfo::ClientRole::zoptVal:
	{
		return "worldB";
	}
	case ZButtonModelInfo::ClientRole::optVal2:
	{
		return "nextH";
	}break;
	default:
		break;
	}
	return QVariant();
}



