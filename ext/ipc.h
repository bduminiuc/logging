/**
 * @file ipc.h
 * @author bduminyuk (bduminyuk@lan.aommz.com)
 * @brief Файл описывает структуры и константы, используемые для
 * передачи лог сообщений при межпроцессном взаимодействии
 * @version 1.0
 * @date 2021-01-29
 *
 * @copyright Copyright (c) 2021
 *
 */
#ifndef __ACORE_LOGGING_EXT_IPC_H__
#define __ACORE_LOGGING_EXT_IPC_H__

namespace acore
{
namespace logging
{
    namespace ipc
    {

#define ACORE_IPC_LOGGING_MAX_PATH_LENGTH    128
#define ACORE_IPC_LOGGING_MAX_MESSAGE_LENGTH 255

        /**
         * @brief Структура описывает сообщение, передаваемое
         * синками при межпроцессном взаимодействии.
         */
        struct Message
        {
            /**
             * @brief Готовый путь, куда нужно записать сообщение.
             */
            char path[ACORE_IPC_LOGGING_MAX_PATH_LENGTH];

            /**
             * @brief Готовое отформатированное сообщение.
             */
            char message[ACORE_IPC_LOGGING_MAX_MESSAGE_LENGTH];
        };

        const size_t MAX_PATH_LENGTH = ACORE_IPC_LOGGING_MAX_PATH_LENGTH;
        const size_t MAX_MESSAGE_LENGTH = ACORE_IPC_LOGGING_MAX_MESSAGE_LENGTH;

#undef ACORE_IPC_LOGGING_MAX_PATH_LENGTH
#undef ACORE_IPC_LOGGING_MAX_MESSAGE_LENGTH

    } // namespace ipc
} // namespace logging
} // namespace acore

#endif // __ACORE_LOGGING_EXT_IPC_H__