/**
 * @file file_sink.h
 * @author bduminyuk (bduminyuk@lan.aommz.com)
 * @brief Файл описывает класс FileSink.
 * @version 1.0
 * @date 2020-10-23
 *
 * @copyright Copyright (c) 2020
 *
 */
#ifndef __ACORE_LOGGING_FILE_SINK_H__
#define __ACORE_LOGGING_FILE_SINK_H__

#include "sink.h"

#ifndef __QNX__
namespace acore
{
namespace logging
{
    namespace sinks
    {
#endif
        /**
         * @brief Класс FileSink
         * Осуществляет запись сообщения в файл. Путь к файлу вычисляется при
         * помощи класса PathFormatter (или его наследников).
         *
         * Т.к. поле m_pathFormatter объявлено как protected, наследники класса
         * FileSink могут изменять его для указания пути, по которому
         * должно быть записано сообщение.
         */
        class FileSink : public Sink
        {
        public:
            FileSink();
            FileSink(const std::string &pattern);
            FileSink(PathFormatterPtr pathFormatter);
            FileSink(const std::string &pattern,
                     MessageFormatterPtr messageFormatter);
            FileSink(PathFormatterPtr pathFormatter,
                     MessageFormatterPtr messageFormatter);

            void log(const std::string &message, level_t lvl) ACORE_OVERRIDE;
            void flush() ACORE_OVERRIDE;

        protected:
            PathFormatterPtr m_pathFormatter;
        };

#ifndef __QNX__
    } // namespace acore
} // namespace logging
} // namespace sinks
#endif

#endif // __ACORE_LOGGING_FILE_SINK_H__