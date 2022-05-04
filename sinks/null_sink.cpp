#include "null_sink.h"

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
        NullSink::NullSink()
            : Sink()
        {
        }

        NullSink::NullSink(MessageFormatterPtr formatter)
            : Sink(formatter)
        {
        }

        void NullSink::log(const std::string &, level_t)
        {
        }

        void NullSink::flush()
        {
        }

#ifndef __QNX__
    } // namespace sinks
} // namespace logging
} // namespace acore
#endif
