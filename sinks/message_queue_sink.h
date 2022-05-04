/**
 * @file message_queue_sink.h
 * @author bduminyuk (bduminyuk@lan.aommz.com)
 * @brief Файл содержит описание класса MessageQueueSink.
 * @version 1.0
 * @date 2021-01-28
 *
 * @copyright Copyright (c) 2021
 *
 */
#ifndef __ACORE_LOGGING_MESSAGE_QUEUE_SINK_H__
#define __ACORE_LOGGING_MESSAGE_QUEUE_SINK_H__

#include "acore/interprocess/message_queue.h"
#include "sink.h"

namespace acore
{
namespace logging
{
    namespace sinks
    {

        /**
         * @brief Класс MessageQueueSink
         * Осуществляет запись сообщения logging::ipc::Message в очередь.
         *
         * Очередь должна быть предварительно открыта.
         */
        class MessageQueueSink : public Sink
        {
        public:
            typedef std::shared_ptr<acore::ipc::message_queue::MessageQueue>
                MQPtr_t;

            /**
             * @brief Создает MessageQueueSink с форматтером пути по умолчанию
             * на основе значения pattern и с форматтером сообщения по
             * умолчанию.
             *
             * @param pattern шаблон пути
             * @param mq очередь сообщений
             */
            MessageQueueSink(const std::string &pattern, MQPtr_t mq);

            /**
             * @brief Создает MessageQueueSink с форматтером пути pathFormatter
             * и с форматтером сообщения по умолчанию.
             *
             * @param pathFormatter указанный форматтер пути
             * @param mq очередь сообщений
             */
            MessageQueueSink(PathFormatterPtr pathFormatter, MQPtr_t mq);

            /**
             * @brief Создает MessageQueueSink с форматтером пути по умолчанию
             * на основе значения pattern и с форматтером сообщения
             * messageFormatter.
             *
             * @param pattern шаблон пути
             * @param messageFormatter форматтер сообщения
             * @param mq очередь сообщений
             */
            MessageQueueSink(const std::string &pattern,
                             MessageFormatterPtr messageFormatter,
                             MQPtr_t mq);

            /**
             * @brief Создает MessageQueueSink с форматтером пути pathFormatter
             * и с форматтером сообщения messageFormatter.
             *
             * @param pathFormatter указанный форматтер пути
             * @param messageFormatter форматтер сообщения
             * @param mq очередь сообщений
             */
            MessageQueueSink(PathFormatterPtr pathFormatter,
                             MessageFormatterPtr messageFormatter,
                             MQPtr_t mq);

            void log(const std::string &message, level_t lvl) ACORE_OVERRIDE;
            void flush() ACORE_OVERRIDE;

        private:
            void initialize(
                acore::ipc::message_queue::MessageQueue::size_type maxmsg);

            PathFormatterPtr m_pathFormatter;
            MQPtr_t m_mq;
        };

    } // namespace sinks
} // namespace logging
} // namespace acore

#endif // __ACORE_LOGGING_MESSAGE_QUEUE_SINK_H__
