#include "filters.h"

namespace acore
{
namespace logging
{
    namespace filter
    {
        bool if_previous_equal(const Message &msg)
        {
            static Message previous;

            bool filtrated = previous == msg;
            previous = msg;

            return filtrated;
        }

        bool if_level_undefined(const Message &msg)
        {
            return msg.lvl == level_t::Undefined;
        }

        base_level_filter::base_level_filter(level_t lvl)
            : lvl_(lvl)
        {
        }

        only::only(level_t lvl)
            : base_level_filter(lvl)
        {
        }

        bool only::operator()(const Message &msg) const
        {
            return msg.lvl == lvl_;
        }

        greater_than::greater_than(level_t lvl)
            : base_level_filter(lvl)
        {
        }

        bool greater_than::operator()(const Message &msg) const
        {
            return msg.lvl > lvl_;
        }

        less_than::less_than(level_t lvl)
            : base_level_filter(lvl)
        {
        }

        bool less_than::operator()(const Message &msg) const
        {
            return msg.lvl < lvl_;
        }

        group::group(std::initializer_list<Prototype> initlist)
        {
            for (auto it = initlist.begin(); it != initlist.end(); it++)
            {
                filters_.push_back(*it);
            }
        }

        bool group::operator()(const Message &msg) const
        {
            for (auto it = filters_.cbegin(); it != filters_.cend(); it++)
            {
                if ((*it)(msg))
                {
                    return true;
                }
            }

            return false;
        }

    } // namespace filter
} // namespace logging
} // namespace acore