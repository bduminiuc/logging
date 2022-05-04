#include "path_formatter.h"

#ifndef __QNX__
namespace acore
{
namespace logging
{
    namespace formatters
    {
#else
#include "acore/logging/formatters/message_formatter.h"
#include "acore/logging/logger.h"
#endif

        PathFormatter::PathFormatter(const std::string &pathPattern)
            : m_pattern(pathPattern)
        {
        }

        PathFormatter::~PathFormatter()
        {
        }

        const std::string &PathFormatter::get_pattern() const
        {
            return m_pattern;
        }

#ifndef __QNX__
    } // namespace formatters
} // namespace logging
} // namespace acore
#endif