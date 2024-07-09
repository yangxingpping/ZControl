#pragma once
#include "qsystemdetection.h"
#ifdef Q_OS_WIN
#include "Windows/export_flags/zControlExport.h"
#elif defined(Q_OS_ANDROID)
#include "Android/export_flags/zControlExport.h"
#endif
