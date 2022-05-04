/**
 * @file message_formatter.h
 * @author bduminyuk (bduminyuk@lan.aommz.com)
 * @brief Файл описывает класс MessageFormatter.
 * @version 1.0
 * @date 2021-01-28
 *
 * @copyright Copyright (c) 2021
 *
 */
#ifndef __ACORE_LOGGING_FORMATTERS_MESSAGE_FORMATTER_H__
#define __ACORE_LOGGING_FORMATTERS_MESSAGE_FORMATTER_H__

#include "acore/logging/common.h"

#ifndef __QNX__
namespace acore
{
namespace logging
{
    namespace formatters
    {
#endif

        /**
         * @brief Класс MessageFormatter.
         *
         * Используется всеми синками для формирования самого сообщения.
         *
         * Если нужно изменить способ формирования сообщения (например,
         * пробросить какие-то свои ключевые слова в сообщение), то нужно
         * унаследоваться от этого класса и определить метод `format(const
         * Message &msg)`.
         *
         * Подробнее см. пример examples/logging/logging_message_customization.
         */
        class MessageFormatter
        {
        public:
            /**
             * @brief Конструктор MessageFormatter.
             *
             * @param messagePattern шаблон сообщения
             */
            MessageFormatter(const std::string &messagePattern);

            virtual ~MessageFormatter();

            /**
             * @brief Форматирует сообщение msg и возвращает готовую строку,
             * содержащую сообщение, попадающее в лог.
             *
             * @param msg структура сообщения
             * @return std::string отформатированное строковое представление
             * сообщения msg
             */
            virtual std::string format(const Message &msg) const = 0;

            /**
             * @brief Устанавливает шаблон сообщения pattern.
             *
             * Позволяет обновить шаблон сообщения у уже существующего
             * экземпляра класса MessageFormatter.
             *
             * @param pattern новый шаблон сообщения
             */
            void set_pattern(const std::string &pattern);

        protected:
            const std::string &get_pattern() const;

        private:
            std::string m_pattern;
        };

#ifndef __QNX__
    } // namespace formatters
} // namespace logging
} // namespace acore
#endif

#endif // __ACORE_LOGGING_FORMATTERS_MESSAGE_FORMATTER_H__