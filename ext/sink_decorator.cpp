#include "sink_decorator.h"

#ifndef __QNX__
namespace acore
{
namespace logging
{
    namespace ext
    {
#else
#include "acore/logging/formatters/path_formatter.h"
#endif

        SinkDecorator::SinkDecorator(SinkPtr s)
            : Sink()
            , wrapped(s)
        {
        }

        SinkDecorator::SinkDecorator(SinkPtr s, MessageFormatterPtr formatter)
            : Sink(formatter)
            , wrapped(s)
        {
        }

        void SinkDecorator::log(const std::string &message, level_t lvl)
        {
            wrapped->log(message, lvl);
        }

        void SinkDecorator::flush()
        {
            wrapped->flush();
        }

        bool SinkDecorator::should_be_filtered(const Message &msg) const
        {
            return wrapped->should_be_filtered(msg);
        }

#ifndef __QNX__
    } // namespace sinks
} // namespace logging
} // namespace acore
#endif
