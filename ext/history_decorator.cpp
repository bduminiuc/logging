#include "history_decorator.h"

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

        HistoryDecorator::HistoryDecorator(SinkPtr s)
            : SinkDecorator(s)
        {
        }

        HistoryDecorator::HistoryDecorator(SinkPtr s,
                                           MessageFormatterPtr formatter)
            : SinkDecorator(s, formatter)
        {
        }

        void HistoryDecorator::log(const std::string &message, level_t lvl)
        {
            m_buffer += message;
        }

        void HistoryDecorator::flush()
        {
            SinkDecorator::log(m_buffer, level_t::Undefined);
        }

#ifndef __QNX__
    } // namespace sinks
} // namespace logging
} // namespace acore
#endif