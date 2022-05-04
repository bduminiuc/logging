/**
 * @file stdout_sink.h
 * @author bduminyuk (bduminyuk@lan.aommz.com)
 * @brief Файл описывает класс StdoutSink.
 * @version 1.0
 * @date 2020-10-23
 *
 * @copyright Copyright (c) 2020
 *
 */
#ifndef __ACORE_LOGGING_STDOUT_SINK_H__
#define __ACORE_LOGGING_STDOUT_SINK_H__

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
         * @brief Класс StdoutSink.
         * Осуществляет запись сообщения в стандартный поток stdout.
         */
        class StdoutSink : public Sink
        {
        public:
            StdoutSink();
            StdoutSink(MessageFormatterPtr formatter);
            void log(const std::string &message, level_t lvl) ACORE_OVERRIDE;
            void flush() ACORE_OVERRIDE;
        };

#ifndef __QNX__
    } // namespace sinks
} // namespace logging
} // namespace acore
#endif

#endif // __ACORE_LOGGING_STDOUT_SINK_H__