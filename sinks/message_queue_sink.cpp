#ifndef __QNX__

#include "message_queue_sink.h"
#include "acore/logging/ext/ipc.h"
#include "acore/logging/formatters/default_path_formatter.h"

#include <cstring>
#include <stdexcept>

namespace acore
{
namespace logging
{
    namespace sinks
    {

        MessageQueueSink::MessageQueueSink(const std::string &pattern,
                                           MQPtr_t mq)
            : Sink()
            , m_pathFormatter(
                  std::make_unique<formatters::DefaultPathFormatter>(pattern))
            , m_mq(mq)
        {
        }

        MessageQueueSink::MessageQueueSink(PathFormatterPtr pathFormatter,
                                           MQPtr_t mq)
            : Sink()
            , m_pathFormatter(pathFormatter)
            , m_mq(mq)
        {
        }

        MessageQueueSink::MessageQueueSink(const std::string &pattern,
                                           MessageFormatterPtr messageFormatter,
                                           MQPtr_t mq)
            : Sink(messageFormatter)
            , m_pathFormatter(
                  std::make_unique<formatters::DefaultPathFormatter>(pattern))
            , m_mq(mq)
        {
        }

        MessageQueueSink::MessageQueueSink(PathFormatterPtr pathFormatter,
                                           MessageFormatterPtr messageFormatter,
                                           MQPtr_t mq)
            : Sink(messageFormatter)
            , m_pathFormatter(pathFormatter)
            , m_mq(mq)
        {
        }

        void MessageQueueSink::log(const std::string &message, level_t lvl)
        {
            logging::ipc::Message msg;
            memset(&msg, 0, sizeof(logging::ipc::Message));

            // создаем временные переменные, т.к. std::min возвращает ссылку
            size_t maxPathLength = logging::ipc::MAX_PATH_LENGTH - 1;
            size_t maxMessageLength = logging::ipc::MAX_MESSAGE_LENGTH - 1;

            std::string path = m_pathFormatter->format();

            std::strncpy(
                msg.path, path.c_str(), std::min(maxPathLength, path.size()));

            std::strncpy(msg.message,
                         message.c_str(),
                         std::min(maxMessageLength, message.size()));

            if (!m_mq->send(&msg, sizeof(msg), 0))
            {
                throw std::runtime_error("MessageQueueSink sending error: "
                                         + m_mq->get_error());
            }
        }

        void MessageQueueSink::flush()
        {
        }

    } // namespace sinks
} // namespace logging
} // namespace acore

#endif // ifndef __QNX__