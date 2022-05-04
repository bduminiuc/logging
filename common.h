/**
 * @file common.h
 * @author bduminyuk (bduminyuk@lan.aommz.com)
 * @brief Файл содержит общие объявления типов и функций,
 * которые применяются ко всему модулю.
 * @version 1.0
 * @date 2020-10-23
 *
 * @copyright Copyright (c) 2020
 *
 */
#ifndef __ACORE_LOGGING_COMMON_H__
#define __ACORE_LOGGING_COMMON_H__

#include "acore/std/memory.h"
#include "acore/std/string.h"
#include "acore/std/types.h"

#ifndef __QNX__
namespace acore
{
namespace logging
{

    namespace sinks
    {
        class Sink;
    }

    namespace formatters
    {
        class PathFormatter;
        class MessageFormatter;
    } // namespace formatters

    class Message;
    class Logger;

    typedef std::shared_ptr<Logger> LoggerPtr;
    typedef std::shared_ptr<sinks::Sink> SinkPtr;
    typedef std::shared_ptr<formatters::PathFormatter> PathFormatterPtr;
    typedef std::shared_ptr<formatters::MessageFormatter> MessageFormatterPtr;

#else
class Sink;
class PathFormatter;
class MessageFormatter;
class Message;
class Logger;

typedef shared_ptr<Logger> LoggerPtr;
typedef shared_ptr<Sink> SinkPtr;
typedef shared_ptr<PathFormatter> PathFormatterPtr;
typedef shared_ptr<MessageFormatter> MessageFormatterPtr;
#endif

#define ACORE_LOGGING_DEFAULT_COLOR_PATTERN                                    \
    "{TIME}: [%^{lvl:>8}%$] [{name}] - {message}"

#ifndef __QNX__

    template <class T, class... Args>
    inline SinkPtr make_sink(Args &&...args)
    {
        return std::make_shared<T>(std::forward<Args>(args)...);
    }

    template <class... Args>
    inline LoggerPtr make_logger(Args &&...args)
    {
        return std::make_shared<Logger>(std::forward<Args>(args)...);
    }

} // namespace logging
} // namespace acore
#endif

#endif // __ACORE_LOGGING_COMMON_H__