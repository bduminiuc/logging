#ifndef __ACORE_LOGGING_SINKS_DETAILS_COLOR_H__
#define __ACORE_LOGGING_SINKS_DETAILS_COLOR_H__

#include "acore/format.h"
#include "acore/logging/level_t.h"

namespace acore
{
namespace logging
{
    namespace sinks
    {
        namespace details
        {
            struct message
            {
                std::string head;
                std::string colored;
                std::string tail;
            };

            acore::format::Color color_from_lvl(level_t lvl);

            message split(const std::string &s);

            void print(std::FILE *f,
                       acore::format::Color c,
                       const message &msg);

        } // namespace details
    }     // namespace sinks
} // namespace logging
} // namespace acore

#endif // __ACORE_LOGGING_SINKS_DETAILS_COLOR_H__
