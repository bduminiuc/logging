#include "message.h"

#ifndef __QNX__
namespace acore
{
namespace logging
{
#else
#include "acore/logging/formatters/path_formatter.h"
#include "acore/logging/logger.h"
#endif

    Message::Message()
    {
    }

    Message::Message(level_t lvl)
        : lvl(lvl)
    {
    }

    Message::Message(level_t lvl,
                     const std::string &lgrName,
                     const std::string &usrmsg)
        : lvl(lvl)
        , loggerName(lgrName)
        , userMessage(usrmsg)
    {
    }

    bool operator==(const Message &lhs, const Message &rhs)
    {
        return lhs.lvl == rhs.lvl && lhs.loggerName == rhs.loggerName
               && lhs.userMessage == rhs.userMessage;
    }

    bool operator!=(const Message &lhs, const Message &rhs)
    {
        return !(lhs == rhs);
    }

#ifndef __QNX__
} // namespace logging
} // namespace acore
#endif