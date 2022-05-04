#include "stderr_sink.h"
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

        StderrSink::StderrSink()
            : Sink()
        {
        }

        StderrSink::StderrSink(MessageFormatterPtr formatter)
            : Sink(formatter)
        {
        }

        void StderrSink::log(const std::string &message, level_t lvl)
        {
            std::cerr << message << std::endl;
        }

        void StderrSink::flush()
        {
            std::cerr << std::flush;
        }

#ifndef __QNX__
    } // namespace sinks
} // namespace logging
} // namespace acore
#endif