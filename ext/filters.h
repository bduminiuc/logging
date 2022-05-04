/**
 * @file filters.h
 * @author bduminyuk (bduminyuk@lan.aommz.com)
 * @brief Файл описывает встроенные функции и объекты, позволяющие фильтровать
 * сообщения, попадаемые в лог. Передаются в метод Sink::set_filter.
 * @version 1.0
 * @date 2021-04-06
 *
 * @copyright Copyright (c) 2021
 *
 */
#ifndef __ACORE_LOGGING_EXT_FILTERS_H__
#define __ACORE_LOGGING_EXT_FILTERS_H__

#include "acore/logging/message.h"
#include "acore/std/memory.h"
#include <vector>
#include <functional>

namespace acore
{
namespace logging
{
    namespace filter
    {
        typedef std::function<bool(const Message &)> Prototype;

        /**
         * @brief Фильтрует сообщение msg, если предыдущее сообщение равно msg.
         *
         * @param msg сообщение, которое проверяется
         * @return true сообщение будет отфильтровано
         * @return false сообщение не будет отфильтровано
         */
        bool if_previous_equal(const Message &msg);

        /**
         * @brief Фильтрует сообщение msg, если его уровень является
         * level_t::Undefined.
         *
         * @param msg сообщение, которое проверяется
         * @return true сообщение будет отфильтровано
         * @return false сообщение не будет отфильтровано
         */
        bool if_level_undefined(const Message &msg);

        /**
         * @brief Интерфейст для классов-функторов фильтров.
         */
        class IFilter
        {
        public:
            virtual bool operator()(const Message &msg) const = 0;
            virtual ~IFilter() = default;
        };

        /**
         * @brief Базовый класс для функторов, фильтрующих по уровню
         * логирования.
         */
        class base_level_filter : public IFilter
        {
        public:
            base_level_filter(level_t lvl);

        protected:
            level_t lvl_;
        };

        /**
         * @brief Функтор only фильтрует сообщения, уровень которых совпадает
         * с заданным уровнем.
         */
        class only : public base_level_filter
        {
        public:
            only(level_t lvl);
            bool operator()(const Message &msg) const ACORE_OVERRIDE;
        };

        /**
         * @brief Функтор greater_than фильтрует сообщения, уровень которых
         * больше заданного.
         */
        class greater_than : public base_level_filter
        {
        public:
            greater_than(level_t lvl);
            bool operator()(const Message &msg) const ACORE_OVERRIDE;
        };

        /**
         * @brief Функтор less_than фильтрует сообщения, уровень которых меньше
         * заданного.
         *
         * Использование этого фильтра эквивалентно установке уровня логирования
         * для синка. Например, следующие строки равны:
         *
         * \code{.cpp}
         * sink->set_filter(al::filter::less_than(al::level_t::Warning));
         * sink->set_level(al::level_t::Warning);
         * \endcode
         *
         * Применение: использование в группе фильтров (см. al::filter::group).
         */
        class less_than : public base_level_filter
        {
        public:
            less_than(level_t lvl);
            bool operator()(const Message &msg) const ACORE_OVERRIDE;
        };

        /**
         * @brief Функтор group объединяет несколько фильтров в себе.
         *
         * Сообщение фильтруется, если хотя бы один из переданных фильтров
         * вернул true.
         *
         * \code{.cpp}
         * // создадим группу, фильтрующую все сообщения, кроме
         * // сообщений с уровнями Info и Warning
         * al::filter::group group {
         *     al::filter::greater_than(al::level_t::Warning),
         *     al::filter::less_than(al::level_t::Info)
         * };
         *
         * // установим группу в качестве фильтра
         * sink->set_filter(group);
         * \endcode
         */
        class group : public IFilter
        {
        public:
            group(std::initializer_list<Prototype> initlist);

            bool operator()(const Message &msg) const ACORE_OVERRIDE;

        private:
            std::vector<Prototype> filters_;
        };

    } // namespace filter
} // namespace logging
} // namespace acore

#endif // __ACORE_LOGGING_EXT_FILTERS_H__
