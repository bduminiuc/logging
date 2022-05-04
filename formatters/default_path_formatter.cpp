#include "default_path_formatter.h"

#include "acore/format.h"

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

        DefaultPathFormatter::DefaultPathFormatter(
            const std::string &pathPattern)
            : PathFormatter(pathPattern)
        {
        }

        std::string DefaultPathFormatter::format() const
        {
#ifdef __QNX__
            return ::format(get_pattern().c_str());
#else
    return acore::format::format(get_pattern().c_str());
#endif
        }

#ifndef __QNX__
    } // namespace formatters
} // namespace logging
} // namespace acore
#endif