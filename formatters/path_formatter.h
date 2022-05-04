/**
 * @file path_formatter.h
 * @author bduminyuk (bduminyuk@lan.aommz.com)
 * @brief Файл описывает класс PathFormatter
 * @version 1.0
 * @date 2021-01-28
 *
 * @copyright Copyright (c) 2021
 *
 */
#ifndef __ACORE_LOGGING_FORMATTERS_PATH_FORMATTER_H__
#define __ACORE_LOGGING_FORMATTERS_PATH_FORMATTER_H__

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
         * @brief Класс PathFormatter.
         *
         * Используется некоторыми синками для формирования пути в
         * файловой системе, по которому нужно записать сообщение.
         *
         * Если нужно каким-то особым образом формировать путь к файлу,
         * то необходимо унаследоваться от этого класса и определить
         * метод `format()`, а затем передать созданный класс в нужный синк.
         *
         * Подробнее см. пример examples/logging/logging_path_customization.
         */
        class PathFormatter
        {
        public:
            /**
             * @brief Конструктор PathFormatter.
             *
             * @param pathPattern шаблон пути
             */
            PathFormatter(const std::string &pathPattern);

            virtual ~PathFormatter();

            /**
             * @brief Возвращает готовый отформатированный путь.
             *
             * @return std::string путь к файлу
             */
            virtual std::string format() const = 0;

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

#endif // __ACORE_LOGGING_FORMATTERS_PATH_FORMATTER_H__