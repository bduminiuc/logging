#include "color.h"

namespace acore
{
namespace logging
{
    namespace sinks
    {
        namespace details
        {
            acore::format::Color color_from_lvl(level_t lvl)
            {
                switch (lvl.to_int())
                {
                case level_t::Debug:
                    return acore::format::Color::CYAN;

                case level_t::Info:
                    return acore::format::Color::GREEN;

                case level_t::Warning:
                    return acore::format::Color::YELLOW;

                case level_t::Error:
                    return acore::format::Color::RED;

                case level_t::Critical:
                    return acore::format::Color::MAGENTA;

                default:
                    return acore::format::Color::WHITE;
                }
            }

            message split(const std::string &s)
            {
                static const char START_COLOR_SYMBOL[] = "%^";
                static const char END_COLOR_SYMBOL[] = "%$";

                size_t start_pos = s.find(START_COLOR_SYMBOL);
                size_t end_pos = s.find(END_COLOR_SYMBOL);

                if (start_pos == std::string::npos
                    || end_pos == std::string::npos)
                {
                    throw acore::format::fmt::FormatError(
                        "acore::logging::sinks::details::split(const "
                        "std::string &): символы парсинга строки для цветного "
                        "вывода на консоль не найдены");
                }

                message msg;

                msg.head = s.substr(0, start_pos);
                msg.colored = s.substr(start_pos + 2, end_pos - start_pos - 2);
                msg.tail = s.substr(end_pos + 2) + "\n";

                return msg;
            }

            void print(std::FILE *f, acore::format::Color c, const message &msg)
            {
                format::print(f, msg.head.c_str());
                format::print(f, c, msg.colored.c_str());
                format::print(f, msg.tail.c_str());
            }

        } // namespace details
    }     // namespace sinks
} // namespace logging
} // namespace acore