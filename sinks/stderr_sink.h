/**
 * @file stderr_sink.h
 * @author bduminyuk (bduminyuk@lan.aommz.com)
 * @brief Файл описывает класс StderrSink.
 * @version 1.0
 * @date 2020-10-23
 *
 * @copyright Copyright (c) 2020
 *
 */
#ifndef __ACORE_LOGGING_STDERR_SINK_H__
#define __ACORE_LOGGING_STDERR_SINK_H__

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
         * @brief Класс StrerrSink.
         * Осуществляет запись сообщения в стандартный поток для ошибок stderr.
         */
        class StderrSink : public Sink
        {
        public:
            StderrSink();
            StderrSink(MessageFormatterPtr formatter);

            void log(const std::string &message, level_t lvl) ACORE_OVERRIDE;
            void flush() ACORE_OVERRIDE;
        };

#ifndef __QNX__
    } // namespace sinks
} // namespace logging
} // namespace acore
#endif

#endif // __ACORE_LOGGING_STDERR_SINK_H__