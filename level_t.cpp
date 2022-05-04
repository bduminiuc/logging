#include "level_t.h"

#ifdef __QNX__
#include <ctype.h>
#else
#include <cctype>

namespace acore
{
namespace logging
{
#endif

level_t::level_t()
    : m_lvl(Undefined)
{
}

level_t::level_t(InternalEnum lvl)
    : m_lvl(lvl)
{
}

level_t &level_t::operator=(InternalEnum lvl)
{
    m_lvl = lvl;
    return *this;
}

std::string level_t::to_string() const
{
    switch (m_lvl)
    {
    case Debug:
        return "debug";

    case Info:
        return "info";

    case Warning:
        return "warning";

    case Error:
        return "error";

    case Critical:
        return "critical";

    default:
        return "";
    }
}

int level_t::to_int() const
{
#ifdef __QNX__
    return (int)m_lvl;
#else
        return static_cast<int>(m_lvl);
#endif
}

level_t level_t::from_string(std::string lvl)
{
    for (int i = 0; i < lvl.size(); i++)
    {
        lvl[i] = std::tolower(lvl[i]);
    }

    if (lvl == "debug")
    {
        return Debug;
    }
    if (lvl == "info")
    {
        return Info;
    }
    if (lvl == "warning")
    {
        return Warning;
    }
    if (lvl == "error")
    {
        return Error;
    }
    if (lvl == "critical")
    {
        return Critical;
    }

    return Undefined;
}

level_t level_t::get_default()
{
    return Debug;
}

bool operator==(const level_t &lhs, const level_t &rhs)
{
    return lhs.m_lvl == rhs.m_lvl;
}

bool operator!=(const level_t &lhs, const level_t &rhs)
{
    return lhs.m_lvl != rhs.m_lvl;
}

bool operator<(const level_t &lhs, const level_t &rhs)
{
    return lhs.m_lvl < rhs.m_lvl;
}

bool operator>(const level_t &lhs, const level_t &rhs)
{
    return lhs.m_lvl > rhs.m_lvl;
}

bool operator<=(const level_t &lhs, const level_t &rhs)
{
    return lhs.m_lvl <= rhs.m_lvl;
}

bool operator>=(const level_t &lhs, const level_t &rhs)
{
    return lhs.m_lvl >= rhs.m_lvl;
}

std::ostream &operator<<(std::ostream &os, const level_t &lvl)
{
    return os << lvl.to_string();
}

std::ostream &operator<<(std::ostream &os, const level_t::InternalEnum &lvl)
{
    return os << level_t(lvl).to_string();
}

#ifndef __QNX__
} // namespace logging
} // namespace acore
#endif