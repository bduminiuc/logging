/**
 * @file message.h
 * @author bduminyuk (bduminyuk@lan.aommz.com)
 * @brief Файл описывает структуру Message.
 * @version 1.0
 * @date 2020-10-27
 *
 * @copyright Copyright (c) 2020
 *
 */
#ifndef __ACORE_LOGGING_LOGMESSAGE_H__
#define __ACORE_LOGGING_LOGMESSAGE_H__

#include "acore/logging/level_t.h"
#include "common.h"

#ifndef __QNX__
namespace acore
{
namespace logging
{
#endif

    /**
     * @brief Структура Message представляет собой набор параметров,
     * необходимых форматтерам для превращения сообщения в строку.
     */
    struct Message
    {
        /**
         * @brief Уровень сообщения.
         */
        level_t lvl;

        /**
         * @brief Имя логгера, отправившего сообщение.
         */
        std::string loggerName;

        /**
         * @brief Готовое пользовательское сообщение.
         */
        std::string userMessage;

        Message();
        Message(level_t msg);
        Message(level_t lvl,
                const std::string &lgrName,
                const std::string &usrmsg);
    };

    bool operator==(const Message &lhs, const Message &rhs);
    bool operator!=(const Message &lhs, const Message &rhs);

#ifndef __QNX__
} // namespace logging
} // namespace acore
#endif

#endif // __ACORE_LOGGING_LOGMESSAGE_H__