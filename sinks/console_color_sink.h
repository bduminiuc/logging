/**
 * @file console_color_sink.h
 * @author bduminyuk (bduminyuk@lan.aommz.com)
 * @brief
 * @version 3.0.0
 * @date 2021-04-12
 *
 * @copyright Copyright (c) 2021
 *
 */
#ifndef __ACORE_LOGGING_SINKS_CONSOLE_COLOR_SINK_H__
#define __ACORE_LOGGING_SINKS_CONSOLE_COLOR_SINK_H__

#include "sink.h"

namespace acore
{
namespace logging
{
    namespace sinks
    {
        /**
         * @brief Класс ConsoleColorSink.
         * Осуществляет запись сообщения в stdout, если уровень сообщения ниже
         * Warning. В противном случае записывает сообщение в stderr.
         *
         * В сообщениях уровень сообщения выделяется цветом.
         */
        class ConsoleColorSink : public Sink
        {
        public:
            ConsoleColorSink();
            ConsoleColorSink(MessageFormatterPtr formatter);

            void log(const std::string &message, level_t lvl) ACORE_OVERRIDE;
            void flush() ACORE_OVERRIDE;
        };
    } // namespace sinks
} // namespace logging
} // namespace acore

#endif // __ACORE_LOGGING_SINKS_CONSOLE_COLOR_SINK_H__
