/**
 * @file sink_decorator.h
 * @author bduminyuk (bduminyuk@lan.aommz.com)
 * @brief Файл описывает класс SinkDecorator.
 * @version 1.0
 * @date 2020-10-23
 *
 * @copyright Copyright (c) 2020
 *
 */
#ifndef __ACORE_LOGGING_SINK_DECORATOR_H__
#define __ACORE_LOGGING_SINK_DECORATOR_H__

#include "acore/logging/sinks/sink.h"

#ifndef __QNX__
namespace acore
{
namespace logging
{
    namespace ext
    {
#endif
        /**
         * @brief Класс SinkDecorator.
         * Описывает базовый класс для паттерна "Декоратор".
         *
         * Используется для добавленя синкам какой-либо функциональности,
         * позволяя заворачивать синки в дополнительные обертки.
         */
        class SinkDecorator : public
#ifdef __QNX__
                              Sink
#else
                      sinks::Sink
#endif

        {
        public:
            SinkDecorator(SinkPtr s);
            SinkDecorator(SinkPtr s, MessageFormatterPtr formatter);

            void log(const std::string &message, level_t lvl) ACORE_OVERRIDE;
            void flush() ACORE_OVERRIDE;

            bool should_be_filtered(const Message &msg) const;

        private:
            SinkPtr wrapped;
        };

#ifndef __QNX__
    } // namespace sinks
} // namespace logging
} // namespace acore
#endif

#endif // __ACORE_LOGGING_SINK_DECORATOR_H__