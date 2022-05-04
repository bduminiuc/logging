#ifndef __QNX__

#include "stdout_color_sink.h"
#include "details/color.h"

#include <iostream>

namespace acore
{
namespace logging
{
    namespace sinks
    {

        StdoutColorSink::StdoutColorSink()
            : Sink()
        {
            set_pattern(ACORE_LOGGING_DEFAULT_COLOR_PATTERN);
        }

        StdoutColorSink::StdoutColorSink(MessageFormatterPtr formatter)
            : Sink(formatter)
        {
            set_pattern(ACORE_LOGGING_DEFAULT_COLOR_PATTERN);
        }

        void StdoutColorSink::log(const std::string &message, level_t lvl)
        {
            details::message msg = details::split(message);
            auto c = details::color_from_lvl(lvl);
            details::print(stdout, c, msg);
        }

        void StdoutColorSink::flush()
        {
            std::fflush(stdout);
            std::cout << std::flush;
        }

    } // namespace sinks
} // namespace logging
} // namespace acore

#endif
