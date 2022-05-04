#include "default_message_formatter.h"

#include "acore/format.h"
#include "acore/logging/message.h"

#ifndef __QNX__
namespace af = acore::format;

namespace acore
{
namespace logging
{
    namespace formatters
    {

        static const char DEFAULT_MESSAGE_PATTERN[]
            = "{TIME}: [{lvl:>8}] [{name}] - {message}";

#else
#include "acore/logging/formatters/path_formatter.h"
#include "acore/logging/logger.h"

static const char DEFAULT_MESSAGE_PATTERN[]
    = "%H:%M:%S: [{>8:lvl}] [{>10:name}] - {message}";
#endif

        DefaultMessageFormatter::DefaultMessageFormatter()
            : MessageFormatter(DEFAULT_MESSAGE_PATTERN)
        {
        }

        DefaultMessageFormatter::DefaultMessageFormatter(
            const std::string &messagePattern)
            : MessageFormatter(messagePattern)
        {
        }

        std::string DefaultMessageFormatter::format(const Message &msg) const
        {
#ifdef __QNX__
            return ::format(get_pattern().c_str(),
                            arg("lvl", to_string(msg.lvl)),
                            arg("name", msg.loggerName),
                            arg("message", msg.userMessage));
#else
    return af::format(get_pattern().c_str(),
                      af::fmt::arg("lvl", msg.lvl.to_string()),
                      af::fmt::arg("name", msg.loggerName),
                      af::fmt::arg("message", msg.userMessage));
#endif
        }

#ifndef __QNX__
    } // namespace formatters
} // namespace logging
} // namespace acore
#endif