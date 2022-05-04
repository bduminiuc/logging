/**
 * @file console_sink.h
 * @author bduminyuk (bduminyuk@lan.aommz.com)
 * @brief Файл содержит отписание класса ConsoleSink.
 * @version 1.0
 * @date 2021-01-28
 *
 * @copyright Copyright (c) 2021
 *
 */
#ifndef __ACORE_LOGGING_CONSOLE_SINK_H__
#define __ACORE_LOGGING_CONSOLE_SINK_H__

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
         * @brief Класс ConsoleSink.
         * Осуществляет запись сообщения в stdout, если уровень
         * сообщения ниже Warning. В противном случае записывает сообщение в
         * stderr.
         */
        class ConsoleSink : public Sink
        {
        public:
            ConsoleSink();
            ConsoleSink(MessageFormatterPtr formatter);

            void log(const std::string &message, level_t lvl) ACORE_OVERRIDE;
            void flush() ACORE_OVERRIDE;
        };

#ifndef __QNX__
    } // namespace acore
} // namespace logging
} // namespace sinks
#endif

#endif // __ACORE_LOGGING_CONSOLE_SINK_H__
