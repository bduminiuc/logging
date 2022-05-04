/**
 * @file level_t.h
 * @author bduminyuk (bduminyuk@lan.aommz.com)
 * @brief Файл описывает класс level_t
 * @version 1.0
 * @date 2021-01-28
 *
 * @copyright Copyright (c) 2021
 *
 */
#ifndef __ACORE_LOGGING_level_tt_H__
#define __ACORE_LOGGING_level_tt_H__

#include "acore/std/string.h"

#ifndef __QNX__
namespace acore
{
namespace logging
{
#endif

    /**
     * @brief Класс level_t представляет собой уровень логирования.
     *
     */
    class level_t
    {
    public:
        enum InternalEnum
        {
            Undefined,
            Debug,
            Info,
            Warning,
            Error,
            Critical
        };

        level_t();
        level_t(InternalEnum lvl);

        level_t &operator=(InternalEnum lvl);

        /**
         * @brief Преобразует уровень логирования в строку.
         *
         * Соответствия:
         * Undefined - ""
         * Debug - "debug"
         * Info - "info"
         * Warning - "warning"
         * Critical - "critical"
         *
         * @return std::string строковое представление уровня логирования
         */
        std::string to_string() const;

        /**
         * @brief Преобразует объект класса в значение int.
         *
         * @return int значение, соответствующее установленному уровню
         */
        int to_int() const;

        /**
         * @brief Преобразует строковое представление уровня логирования
         * в значение level_t.
         *
         * @param s строка, содержащая строковое представление уровня
         * логирования
         * @return level_t значение enum, соответствующее строковому
         * представлению
         */
        static level_t from_string(std::string lvl);

        /**
         * @brief Возвращает уровень по умолчанию.
         *
         * @return level_t уровень по умолчанию
         */
        static level_t get_default();

        friend bool operator==(const level_t &lhs, const level_t &rhs);
        friend bool operator!=(const level_t &lhs, const level_t &rhs);
        friend bool operator<(const level_t &lhs, const level_t &rhs);
        friend bool operator>(const level_t &lhs, const level_t &rhs);
        friend bool operator<=(const level_t &lhs, const level_t &rhs);
        friend bool operator>=(const level_t &lhs, const level_t &rhs);

        friend std::ostream &operator<<(std::ostream &os, const level_t &lvl);
        friend std::ostream &operator<<(std::ostream &os,
                                        const InternalEnum &lvl);

    private:
        InternalEnum m_lvl;
    };

#ifndef __QNX__
} // namespace logging
} // namespace acore
#endif

#endif // __ACORE_LOGGING_level_tt_H__