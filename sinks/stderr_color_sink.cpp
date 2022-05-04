#ifndef __QNX__
#include "stderr_color_sink.h"

#include "details/color.h"

namespace acore
{
namespace logging
{
    namespace sinks
    {

        StderrColorSink::StderrColorSink()
            : Sink()
        {
            set_pattern(ACORE_LOGGING_DEFAULT_COLOR_PATTERN);
        }

        StderrColorSink::StderrColorSink(MessageFormatterPtr formatter)
            : Sink(formatter)
        {
            set_pattern(ACORE_LOGGING_DEFAULT_COLOR_PATTERN);
        }

        void StderrColorSink::log(const std::string &message, level_t lvl)
        {
            details::message msg = details::split(message);
            auto color = details::color_from_lvl(lvl);
            details::print(stderr, color, msg);
        }

        void StderrColorSink::flush()
        {
            std::fflush(stderr);
        }

    } // namespace sinks
} // namespace logging
} // namespace acore

#endif