/**
 * @file default_path_formatter.h
 * @author bduminyuk (bduminyuk@lan.aommz.com)
 * @brief Файл описывает класс DefaultPathFormatter.
 * @version 1.0
 * @date 2021-01-28
 *
 * @copyright Copyright (c) 2021
 *
 */
#ifndef __ACORE_LOGGING_FORMATTERS_DEFAULT_PATH_FORMATTER_H__
#define __ACORE_LOGGING_FORMATTERS_DEFAULT_PATH_FORMATTER_H__

#include "path_formatter.h"

#ifndef __QNX__
namespace acore
{
namespace logging
{
    namespace formatters
    {
#endif

        /**
         * @brief Класс DefaultPathFormatter.
         *
         * Содержит реализацию метода `format()` по умолчанию.
         */
        class DefaultPathFormatter : public PathFormatter
        {
        public:
            DefaultPathFormatter(const std::string &pathPattern);

            /**
             * @brief Форматирует pathPattern из конструктора при помощи
             * `acore::format::format()` без аргументов.
             *
             * Подробнее см. описание метода `acore::format::format()`.
             *
             * @return std::string отформатированное значение, соответствующее
             *                     шаблону pathPattern из конструктора.
             */
            std::string format() const ACORE_OVERRIDE;
        };

#ifndef __QNX__
    } // namespace formatters
} // namespace logging
} // namespace acore
#endif

#endif // __ACORE_LOGGING_FORMATTERS_DEFAULT_PATH_FORMATTER_H__