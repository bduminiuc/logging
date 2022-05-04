#include "default.h"

#include "logger.h"
#include "message.h"

#include "acore/logging/sinks/file_sink.h"
#include "acore/std/types.h"

#ifndef __QNX__
#include <unordered_map>

namespace acore
{
namespace logging
{

    static std::unordered_map<std::string, LoggerPtr> m_registry;
#else
#include "acore/logging/formatters/path_formatter.h"
#include "acore/logging/logger.h"
#include "acore/std/map.hpp"
static map<string, LoggerPtr> m_registry;
#endif
    static LoggerPtr m_defaultLogger;

#ifndef __QNX__
    void debug(const std::string &format_str, acore::format::ArgList args)
    {
        if (!m_defaultLogger)
        {
            throw std::runtime_error("Default logger wasn't set");
        }

        m_defaultLogger->debug(format_str, args);
    }

    void info(const std::string &format_str, acore::format::ArgList args)
    {
        if (!m_defaultLogger)
        {
            throw std::runtime_error("Default logger wasn't set");
        }

        m_defaultLogger->info(format_str, args);
    }

    void warning(const std::string &format_str, acore::format::ArgList args)
    {
        if (!m_defaultLogger)
        {
            throw std::runtime_error("Default logger wasn't set");
        }

        m_defaultLogger->warning(format_str, args);
    }

    void error(const std::string &format_str, acore::format::ArgList args)
    {
        if (!m_defaultLogger)
        {
            throw std::runtime_error("Default logger wasn't set");
        }

        m_defaultLogger->error(format_str, args);
    }

    void critical(const std::string &format_str, acore::format::ArgList args)
    {
        if (!m_defaultLogger)
        {
            throw std::runtime_error("Default logger wasn't set");
        }

        m_defaultLogger->critical(format_str, args);
    }

    void append(const std::string &path,
                const std::string &format_str,
                acore::format::ArgList args)
    {
        sinks::FileSink fsink(path);
        fsink.log(acore::format::format(format_str.c_str(), args),
                  level_t::Undefined);
    }
#else
void debug(const std::string &message)
{
    m_defaultLogger->debug(message);
}

void info(const std::string &message)
{
    m_defaultLogger->info(message);
}

void warning(const std::string &message)
{
    m_defaultLogger->warning(message);
}

void error(const std::string &message)
{
    m_defaultLogger->error(message);
}

void critical(const std::string &message)
{
    m_defaultLogger->critical(message);
}

void append(const std::string &path, const std::string &message)
{
    FileSink fsink(path);
    fsink.log(message, level_t::Undefined);
}

#endif

    void set_default(LoggerPtr lptr)
    {
#ifndef __QNX__
        std::pair<std::unordered_map<std::string, LoggerPtr>::iterator, bool>
            pair = m_registry.insert({ lptr->get_name(), lptr });

        // pair.first - iterator, iterator->second - LoggerPtr
        m_defaultLogger = pair.first->second;
#else
    m_registry[lptr->get_name()] = lptr;
    m_defaultLogger = lptr;
#endif
    }

    void register_logger(LoggerPtr lptr)
    {
#ifdef __QNX__
        m_registry[lptr->get_name()] = lptr;
#else
    m_registry.insert({ lptr->get_name(), lptr });
#endif
    }

    LoggerPtr get(const std::string &name)
    {
        return m_registry.at(name);
    }

    LoggerPtr get_default()
    {
        return m_defaultLogger;
    }

#ifndef __QNX__
    void drop(const std::string &name)
    {
        m_registry.erase(name);
    }
#endif
    void drop_all()
    {
        m_registry.clear();
    }

#ifndef __QNX__
} // namespace logging
} // namespace acore
#endif
