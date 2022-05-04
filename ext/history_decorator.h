/**
 * @file history_decorator.h
 * @author bduminyuk (bduminyuk@lan.aommz.com)
 * @brief Файл описывает класс HistoryDecorator.
 * @version 1.0
 * @date 2020-10-23
 *
 * @copyright Copyright (c) 2020
 *
 */
#ifndef __ACORE_LOGGING_HISTORY_DECORATOR_H__
#define __ACORE_LOGGING_HISTORY_DECORATOR_H__

#include "sink_decorator.h"

#ifndef __QNX__
namespace acore
{
namespace logging
{
    namespace ext
    {
#endif

        /**
         * @brief Класс HistoryDecorator.
         *
         * Описывает декоратор, осуществляющий накопление сообщений методом
         * `void log(..)` во внутреннем буфере до явного вызова метода
         * `flush()`.
         */
        class HistoryDecorator : public SinkDecorator
        {
        public:
            HistoryDecorator(SinkPtr s);
            HistoryDecorator(SinkPtr s, MessageFormatterPtr formatter);

            void log(const std::string &message, level_t lvl) ACORE_OVERRIDE;
            void flush() ACORE_OVERRIDE;

        private:
            std::string m_buffer;
        };

#ifndef __QNX__
    } // namespace sinks
} // namespace logging
} // namespace acore
#endif

#endif // __ACORE_LOGGING_HISTORY_DECORATOR_H__