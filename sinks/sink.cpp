#include "sink.h"
#include "acore/logging/ext/filters.h"
#include "acore/logging/formatters/default_message_formatter.h"
#include "acore/logging/message.h"

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

        Sink::Sink()
            : m_lvl(level_t::get_default())
#ifdef __QNX__
            , m_formatter(MessageFormatterPtr(new DefaultMessageFormatter))
            , m_customFilter(NULL)
#else
    , m_formatter(std::make_unique<formatters::DefaultMessageFormatter>())
#endif
        {
        }

        Sink::Sink(MessageFormatterPtr formatter)
            : m_lvl(level_t::get_default())
            , m_formatter(formatter)
#ifdef __QNX__
            , m_customFilter(NULL)
#endif
        {
        }

        Sink::~Sink()
        {
        }

        void Sink::set_level(level_t lvl)
        {
            m_lvl = lvl;
        }

        void Sink::set_pattern(const std::string &pattern)
        {
            if (m_formatter)
            {
                m_formatter->set_pattern(pattern);
            }
            else
            {
                m_formatter
#ifndef __QNX__
                    = std::make_unique<formatters::DefaultMessageFormatter>(
                        pattern);
#else
            = MessageFormatterPtr(new DefaultMessageFormatter(pattern));
#endif
            }
        }

        void Sink::set_message_formatter(MessageFormatterPtr f)
        {
            m_formatter = f;
        }

        void Sink::set_filter(const CustomFilter &filter)
        {
            m_customFilter = filter;
        }

        bool Sink::should_be_filtered(const Message &msg) const
        {
            if (m_lvl == level_t::Undefined || filter::if_level_undefined(msg))
            {
                return true;
            }

            if (m_customFilter)
            {
                return m_customFilter(msg);
            }

            return m_lvl > msg.lvl;
        }

        void Sink::_m_log_(const Message &message)
        {
            log(m_formatter->format(message), message.lvl);
        }

#ifndef __QNX__
    } // namespace sinks
} // namespace logging
} // namespace acore
#endif