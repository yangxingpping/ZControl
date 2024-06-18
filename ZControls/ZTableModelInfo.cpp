
#include "ZTableModelInfo.h"

ZTableModelInfo::ZTableModelInfo()
{
}

ZTableModelInfo::~ZTableModelInfo()
{
}

QVariant ZTableModelInfo::getUser(ClientRole role)
{
	switch (role)
	{
	case ZTableModelInfo::ClientRole::name:
	{
		return _name;
	}break;
	case ZTableModelInfo::ClientRole::iconUrl:
	{
		return "byd";
	}break;
    case ZTableModelInfo::ClientRole::maskUrl:
	{
		return "hello";
	}break;
	case ZTableModelInfo::ClientRole::zoptVal:
	{
		return "world";
	}
	default:
		break;
	}
	return QVariant();
}

bool ZTableModelInfo::setUser(ClientRole role, const QVariant& d)
{
	bool ret{ false };
	switch (role)
	{
	case ZTableModelInfo::ClientRole::name:
	{
		_name = d.toString();
		ret = true;
	}break;
	case ZTableModelInfo::ClientRole::iconUrl:
		break;
	case ZTableModelInfo::ClientRole::maskUrl:
		break;
	case ZTableModelInfo::ClientRole::zoptVal:
		break;
	default:
		break;
	}
	return ret;
}


