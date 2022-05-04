#ifndef __QNX__
#ifndef __ACORE_LOGGING_STDERR_COLOR_SINK_H__
#define __ACORE_LOGGING_STDERR_COLOR_SINK_H__

#include "sink.h"

namespace acore
{
namespace logging
{
    namespace sinks
    {
        /**
         * @brief Класс StderrColorSink.
         * Осуществляет запись цветных сообщений в стандартный поток stdout.
         *
         * Цвет подбирается по схеме:
         * Debug - CYAN
         * Info - GREEN
         * Warning - YELLOW
         * Error - RED
         * Critical - MAGENTA
         */
        class StderrColorSink : public Sink
        {
        public:
            StderrColorSink();
            StderrColorSink(MessageFormatterPtr formatter);

            void log(const std::string &message, level_t lvl) ACORE_OVERRIDE;
            void flush() ACORE_OVERRIDE;
        };

    } // namespace sinks
} // namespace logging
} // namespace acore

#endif // __ACORE_LOGGING_STDERR_COLOR_SINK_H__
#endif