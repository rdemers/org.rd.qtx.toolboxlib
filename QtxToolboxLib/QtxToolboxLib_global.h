#ifndef QTXTOOLBOXLIB_GLOBAL_H
#define QTXTOOLBOXLIB_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(QTXTOOLBOX_LIBRARY)
#  define QTXTOOLBOXLIBSHARED_EXPORT Q_DECL_EXPORT
#else
#  define QTXTOOLBOXLIBSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // QTXTOOLBOXLIB_GLOBAL_H