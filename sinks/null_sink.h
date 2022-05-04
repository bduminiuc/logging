/**
 * @file null_sink.h
 * @author bduminyuk (bduminyuk@lan.aommz.com)
 * @brief Файл описывает класс NullSink.
 * @version 1.0
 * @date 2020-10-25
 *
 * @copyright Copyright (c) 2020
 *
 */
#ifndef __ACORE_LOGGING_NULL_SINK_H__
#define __ACORE_LOGGING_NULL_SINK_H__

#include "sink.h"

#ifndef __QNX__
namespace acore
{
namespace logging
{
    namespace sinks
    {
#endif
        /**
         * @brief Класс NullSink игнорирует любую сообщения.
         *
         * Синк, игнорирующий любые сообщения (аналог /dev/null).
         */
        class NullSink : public Sink
        {
        public:
            NullSink();
            NullSink(MessageFormatterPtr formatter);

            void log(const std::string &, level_t) ACORE_OVERRIDE;
            void flush() ACORE_OVERRIDE;
        };

#ifndef __QNX__
    } // namespace sinks
} // namespace logging
} // namespace acore
#endif

#endif // __ACORE_LOGGING_NULL_SINK_H__