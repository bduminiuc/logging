#include "message_formatter.h"

#ifndef __QNX__
namespace acore
{
namespace logging
{
    namespace formatters
    {
#else
#include "acore/logging/formatters/path_formatter.h"
#include "acore/logging/logger.h"
#endif

        MessageFormatter::MessageFormatter(const std::string &messagePattern)
            : m_pattern(messagePattern)
        {
        }

        MessageFormatter::~MessageFormatter()
        {
        }

        void MessageFormatter::set_pattern(const std::string &pattern)
        {
            m_pattern = pattern;
        }

        const std::string &MessageFormatter::get_pattern() const
        {
            return m_pattern;
        }

#ifndef __QNX__
    } // namespace formatters
} // namespace logging
} // namespace acore
#endif