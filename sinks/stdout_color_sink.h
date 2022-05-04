/**
 * @file stdout_color_sink.h
 * @author bduminyuk (bduminyuk@lan.aommz.com)
 * @brief Файл описывает класс StdoutColorSink.
 * @version 1.0
 * @date 2020-10-23
 *
 * @copyright Copyright (c) 2020
 *
 */
#ifndef __QNX__
#ifndef __ACORE_LOGGING_STDOUT_COLOR_SINK_H__
#define __ACORE_LOGGING_STDOUT_COLOR_SINK_H__
#include "sink.h"

namespace acore
{
namespace logging
{
    namespace sinks
    {

        /**
         * @brief Класс StdoutColorSink.
         * Осуществляет запись цветных сообщений в стандартный поток stdout.
         *
         * Цвет подбирается по схеме:
         * Debug - CYAN
         * Info - GREEN
         * Warning - YELLOW
         * Error - RED
         * Critical - MAGENTA
         */
        class StdoutColorSink : public Sink
        {
        public:
            StdoutColorSink();
            StdoutColorSink(MessageFormatterPtr formatter);

            void log(const std::string &message, level_t lvl) ACORE_OVERRIDE;
            void flush() ACORE_OVERRIDE;
        };

    } // namespace sinks
} // namespace logging
} // namespace acore

#endif // __ACORE_LOGGING_STDOUT_COLOR_SINK_H__
#endif