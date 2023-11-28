#ifndef DEBUG_H
#define DEBUG_H

#include <iostream>
#include <QString>
#include <QDebug>

// Macro for debug output
#ifdef QT_DEBUG
    #define DEBUG_LOG(msg) \
        qDebug() << "File:" << __FILE__ << "Line:" << __LINE__ << "Function:" << __FUNCTION__ << "Message:" << (msg)
#else
    #define DEBUG_LOG(msg) // Empty definition for non-debug builds
#endif

#endif // DEBUG_H
