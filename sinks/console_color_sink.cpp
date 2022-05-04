#include "console_color_sink.h"

#include "details/color.h"

#include <iostream>

namespace acore
{
namespace logging
{
    namespace sinks
    {
        ConsoleColorSink::ConsoleColorSink()
            : Sink()
        {
            set_pattern(ACORE_LOGGING_DEFAULT_COLOR_PATTERN);
        }

        ConsoleColorSink::ConsoleColorSink(MessageFormatterPtr formatter)
            : Sink(formatter)
        {
            set_pattern(ACORE_LOGGING_DEFAULT_COLOR_PATTERN);
        }

        void ConsoleColorSink::log(const std::string &message, level_t lvl)
        {
            details::message msg = details::split(message);
            auto color = details::color_from_lvl(lvl);

            std::FILE *output = stdout;

            if (lvl >= level_t::Warning)
            {
                output = stderr;
            }

            details::print(output, color, msg);
        }

        void ConsoleColorSink::flush()
        {
            std::cout << std::flush;
            std::cerr << std::flush;
        }

    } // namespace sinks
} // namespace logging
} // namespace acore