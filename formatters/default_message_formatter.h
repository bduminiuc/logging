/**
 * @file default_message_formatter.h
 * @author bduminyuk (bduminyuk@lan.aommz.com)
 * @brief Файл содержит объявление класса DefaultMessageFormatter.
 * @version 1.0
 * @date 2021-01-28
 *
 * @copyright Copyright (c) 2021
 *
 */
#ifndef __ACORE_LOGGING_FORMATTERS_DEFAULT_MESSAGE_FORMATTER_H__
#define __ACORE_LOGGING_FORMATTERS_DEFAULT_MESSAGE_FORMATTER_H__

#include "message_formatter.h"

#ifndef __QNX__
namespace acore
{
namespace logging
{
    namespace formatters
    {
#endif

        /**
         * @brief Класс DefaultMessageFormatter.
         *
         * Содержит реализацию метода `format(const Message &msg)` пол
         * умолчанию.
         */
        class DefaultMessageFormatter : public MessageFormatter
        {
        public:
            /**
             * @brief Конструктор DefaultMessageFormatter.
             *
             * Создает экземпляр класса с шаблоном по умолчанию.
             */
            DefaultMessageFormatter();

            /**
             * @brief Конструктор DefaultMessageFormatter.
             *
             * Создает экземляр класса, устанавливая шаблон сообщения
             * равным messagePattern.
             *
             * @param messagePattern шаблон сообщения
             */
            DefaultMessageFormatter(const std::string &messagePattern);

            /**
             * @brief Форматирует сообщение msg в соответствии с хранимым
             * шаблоном.
             *
             * Реализует передачу в шаблон сообщения следующих ключевых слов:
             * - `lvl` - уровень сообщения
             * - `name` - имя логгера
             * - `message` - текст сообщения (который передается в методы
             * логгера).
             *
             * @param msg структура сообщения для форматирования
             * @return std::string готовое строковое представление сообщения msg
             */
            std::string format(const Message &msg) const ACORE_OVERRIDE;
        };

#ifndef __QNX__
    } // namespace formatters
} // namespace logging
} // namespace acore
#endif

#endif // __ACORE_LOGGING_FORMATTERS_DEFAULT_MESSAGE_FORMATTER_H__