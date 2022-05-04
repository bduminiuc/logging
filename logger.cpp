#include "logger.h"
#include "acore/logging/message.h"
#include "acore/logging/sinks/console_color_sink.h"

#ifndef __QNX__
#include <memory>
namespace af = acore::format;

namespace acore
{
namespace logging
{

    void Logger::debug(const std::string &format_str, af::ArgList args)
    {
        m_write_to_sinks(
            Message(level_t::Debug, m_name, af::fmt::format(format_str, args)));
    }

    void Logger::info(const std::string &format_str, af::ArgList args)
    {
        m_write_to_sinks(
            Message(level_t::Info, m_name, af::fmt::format(format_str, args)));
    }

    void Logger::warning(const std::string &format_str, af::ArgList args)
    {
        m_write_to_sinks(Message(
            level_t::Warning, m_name, af::fmt::format(format_str, args)));
    }

    void Logger::error(const std::string &format_str, af::ArgList args)
    {
        m_write_to_sinks(
            Message(level_t::Error, m_name, af::fmt::format(format_str, args)));
    }

    void Logger::critical(const std::string &format_str, af::ArgList args)
    {
        m_write_to_sinks(Message(
            level_t::Critical, m_name, af::fmt::format(format_str, args)));
    }
#else
#include "acore/logging/formatters/path_formatter.h"

Logger::Logger(const std::string &name)
    : m_name(name)
{
}

void Logger::debug(const std::string &message)
{
    m_write_to_sinks(Message(level_t::Debug, m_name, message));
}

void Logger::info(const std::string &message)
{
    m_write_to_sinks(Message(level_t::Info, m_name, message));
}

void Logger::warning(const std::string &message)
{
    m_write_to_sinks(Message(level_t::Warning, m_name, message));
}

void Logger::error(const std::string &message)
{
    m_write_to_sinks(Message(level_t::Error, m_name, message));
}

void Logger::critical(const std::string &message)
{
    m_write_to_sinks(Message(level_t::Critical, m_name, message));
}

#endif

    void Logger::write(const Message &msg)
    {
        m_write_to_sinks(msg);
    }

    void Logger::set_pattern(const std::string &pattern)
    {
        for (size_t i = 0; i < m_sinks.size(); i++)
        {
            m_sinks[i]->set_pattern(pattern);
        }
    }

    void Logger::flush()
    {
        for (size_t i = 0; i < m_sinks.size(); i++)
        {
            m_sinks[i]->flush();
        }
    }

    void Logger::add_sink(SinkPtr s)
    {
        m_sinks.push_back(s);
    }

    void Logger::set_message_formatter(MessageFormatterPtr f)
    {
        for (size_t i = 0; i < m_sinks.size(); i++)
        {
            m_sinks[i]->set_message_formatter(f);
        }
    }

    void Logger::set_level(level_t lvl)
    {
        for (size_t i = 0; i < m_sinks.size(); i++)
        {
            m_sinks[i]->set_level(lvl);
        }
    }

    const std::string &Logger::get_name() const
    {
        return m_name;
    }

    void Logger::join(const Logger &other)
    {
        for (size_t i = 0; i < other.m_sinks.size(); i++)
        {
            m_sinks.push_back(other.m_sinks[i]);
        }
    }

    void Logger::set_filter(const sinks::Sink::CustomFilter &filter)
    {
        for (size_t i = 0; i < m_sinks.size(); i++)
        {
            m_sinks[i]->set_filter(filter);
        }
    }

    void Logger::m_write_to_sinks(const Message &message)
    {
        for (size_t i = 0; i < m_sinks.size(); i++)
        {
            if (m_sinks[i]->should_be_filtered(message))
            {
                continue;
            }

            m_sinks[i]->_m_log_(message);
        }
    }

    void Logger::initialize(bool verbose)
    {
        if (verbose)
        {
#ifndef __QNX__
            add_sink(make_sink<sinks::ConsoleColorSink>());
#else
        add_sink(SinkPtr(new ConsoleSink()));
#endif
        }
    }

#ifndef __QNX__
    void Logger::initialize()
    {
        // stop recursion
    }

} // namespace logging
} // namespace acore
#endif