#include "stdout_sink.h"
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

        StdoutSink::StdoutSink()
            : Sink()
        {
        }

        StdoutSink::StdoutSink(MessageFormatterPtr formatter)
            : Sink(formatter)
        {
        }

        void StdoutSink::log(const std::string &message, level_t lvl)
        {
            std::cout << message << std::endl;
        }

        void StdoutSink::flush()
        {
            std::cout << std::flush;
        }

#ifndef __QNX__
    } // namespace sinks
} // namespace logging
} // namespace acore
#endif