#ifndef QTXTOOLBOXLIB_GLOBAL_H
#define QTXTOOLBOXLIB_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(QTXTOOLBOX_LIBRARY)
#  define QTXTOOLBOXLIBSHARED_EXPORT Q_DECL_EXPORT
#else
#  define QTXTOOLBOXLIBSHARED_EXPORT Q_DECL_IMPORT
#endif

#define QTX_VERSION_STR "1.0.0"
#define QTX_VERSION 0x010000 // QTX_VERSION is (major << 16) + (minor << 8) + patch.

#define QTX_BEGIN_NAMESPACE namespace ::qtx {
#define QTX_END_NAMESPACE }

#endif // QTXTOOLBOXLIB_GLOBAL_H
