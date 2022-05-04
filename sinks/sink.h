/**
 * @file sink.h
 * @author bduminyuk (bduminyuk@lan.aommz.com)
 * @brief Файл описывает базовый Sink, интерфейс которого
 * наследуют другие синки.
 *
 * Синки (англ.  sink - "сточная труба", "слив") это объекты,
 * которые непосредственно осуществляют запись лога в конкретное
 * место. Каждый синк отвечает только за свою (одну) цель.
 *
 * @version 1.0
 * @date 2020-10-23
 *
 * @copyright Copyright (c) 2020
 *
 */

#ifndef __ACORE_LOGGING_SINKS_SINK_H__
#define __ACORE_LOGGING_SINKS_SINK_H__

#include "acore/logging/common.h"
#include "acore/logging/level_t.h"

#include <functional>

#ifndef __QNX__

namespace acore
{
namespace logging
{
    namespace sinks
    {

#else
#include "acore/logging/formatters/message_formatter.h"
#include "acore/logging/logger.h"
#endif

        /**
         * @brief Абстрактный класс Sink.
         */
        class Sink
        {
        public:
#ifndef __QNX__
            typedef std::function<bool(const Message &)> CustomFilter;
#else
    typedef bool (*CustomFilter)(const Message &);
#endif

            /**
             * @brief Создает объект класса Sink с форматтером сообщения по
             * умолчанию.
             */
            Sink();

            /**
             * @brief Создает объект класса Sink с указанным форматтером
             * сообщения.
             */
            Sink(MessageFormatterPtr formatter);

            virtual ~Sink();

            /**
             * @brief Записывает сообщение message в конкретную цель.
             *
             * @param message текущее сообщение
             * @param lvl уровень текущего сообщения
             */
            virtual void log(const std::string &message, level_t lvl) = 0;

            /**
             * @brief Записывает все незаписанные данные по конкретному синку.
             */
            virtual void flush() = 0;

            /**
             * @brief Проверяет, должно ли быть отфильтровано сообщение msg.
             *
             * @param msg сообщение, которое проверяется
             * @return true если сообщение должно быть отфильтровано
             * @return false в противном случае
             */
            virtual bool should_be_filtered(const Message &msg) const;

            /**
             * @brief Устанавливает уровень логирования для текущего синка.
             *
             * @param lvl новый уровень логирования
             */
            void set_level(level_t lvl);

            /**
             * @brief Устанавливает шаблон сообщения для текущего синка.
             *
             * По умолчанию не определен. Если не был задан, то используется
             * стандартный шаблон сообщения.
             *
             * Для задания шаблона сообщения можно использовать ключевые слова:
             * - из acore::format для установки даты/времени
             * - {lvl} выводит текущий уровень сообщения (debug, info и т.д.)
             * - {name} имя логгера
             * - {message} пользовательское сообщение
             *
             * Для синков, обрабатывающих цвет, дополнительно нужно указать:
             * - `%^` - начало выделения цветом
             * - `%$` - конец выделения цветом.
             *
             * Синки, не использующие выделение цветом, эти символы не
             * обрабатывают.
             *
             * @param pattern новый шаблон сообщения
             */
            void set_pattern(const std::string &pattern);

            /**
             * @brief Устанавливает форматтер для текущего синка.
             *
             * @param f форматтер
             */
            void set_message_formatter(MessageFormatterPtr f);

            /**
             * @brief Устанавливает пользовательский фильтр сообщений для синка.
             *
             * Если не установлен, используется фильтр по умолчанию.
             *
             * @param filter пользовательский фильтр
             */
            void set_filter(const CustomFilter &filter);

#ifndef __QNX__
            friend class acore::logging::Logger;
#else
    friend class Logger;
#endif

        private:
            void _m_log_(const Message &message);

            level_t m_lvl;
            MessageFormatterPtr m_formatter;

            CustomFilter m_customFilter;
        };

#ifndef __QNX__

    } // namespace sinks
} // namespace logging
} // namespace acore

#endif

#endif // __ACORE_LOGGING_SINKS_SINK_H__
