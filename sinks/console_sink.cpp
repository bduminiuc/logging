#include "console_sink.h"
#include <iostream>

#ifndef __QNX__
namespace acore
{
namespace logging
{
    namespace sinks
    {
#else
#include "acore/logging/formatters/path_formatter.h"
#endif

        ConsoleSink::ConsoleSink()
            : Sink()
        {
        }

        ConsoleSink::ConsoleSink(MessageFormatterPtr formatter)
            : Sink(formatter)
        {
        }

        void ConsoleSink::log(const std::string &message, level_t lvl)
        {
            std::ostream *os = &std::cout;

            if (lvl >= level_t::Warning)
            {
                os = &std::cerr;
            }

            *os << message << std::endl;
        }

        void ConsoleSink::flush()
        {
            std::cout << std::flush;
            std::cerr << std::flush;
        }

#ifndef __QNX__
    } // namespace acore
} // namespace logging
} // namespace sinks
#endif
