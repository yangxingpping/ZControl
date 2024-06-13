#include "ZConfig.h"

ZConfig::ZConfig(QObject* parent) 
    :QObject(parent)
    ,_color({255,0,0})
{
    int c = 1;
    _tableHeader.append("first");
    _tableHeader.append("second");
    _tableHeader.append("third");
    _tableHeader.append("four");
}
