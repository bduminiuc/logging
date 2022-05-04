/**
 * @file logger.h
 * @author bduminyuk (bduminyuk@lan.aommz.com)
 * @brief Файл описывает класс Logger, используемый для клиентами модуля
 * acore::logging для записи сообщений.
 * @version 1.0
 * @date 2020-10-23
 *
 * @copyright Copyright (c) 2020
 *
 */
#ifndef __ACORE_LOGGING_LOGGER_H__
#define __ACORE_LOGGING_LOGGER_H__

#ifndef __QNX__
#include <vector>
#else
#include "acore/std/vector.hpp"
#endif

#include "acore/format.h"
#include "sinks/sink.h"

#ifndef __QNX__

namespace acore
{
namespace logging
{

#endif

    class Message;

    /**
     * @brief Класс логгера.
     *
     * Реализует запись в лог в зависимости от установленных в него синков.
     */
    class Logger
    {
    public:
#ifndef __QNX__
        /**
         * @brief Конструктор logger
         *
         * Создает объект класса по имени и списку синков.
         *
         * @tparam Args переменное кол-во объектов sinks::SinkPtr
         * @param name имя текущего объекта (используется в реестре логгеров)
         * @param args набор объектов SinkPtr
         */
        template <typename... Args>
        Logger(const std::string &name, Args &&...args)
            : m_name(name)
        {
            initialize(std::forward<Args>(args)...);
        }

        /**
         * @brief Конструктор logger
         *
         * Создает объект класса по имени, параметру verbose и списку синков.
         * Если verbose равен true, то добавляет к логгеру синк для вывода
         * сообщений на консоль (`ConsoleSink`).
         *
         * @tparam Args переменное кол-во объектов sinks::SinkPtr
         * @param name имя текущего объекта (используется в реестре логгеров)
         * @param verbose признак добавления синка для вывода на консоль
         * @param args набор объектов SinkPtr
         */
        template <typename... Args>
        Logger(const std::string &name, bool verbose, Args &&...args)
            : m_name(name)
        {
            initialize(verbose);
            initialize(std::forward<Args>(args)...);
        }

        /**
         * @brief Конструктор logger
         *
         * Создает объект класса по имени, с уровнем логирования lvl и
         * списком синков. Эквивалентен созданию логгера с последующим
         * вызовом метода `set_level(lvl)`.
         *
         * @tparam Args Args переменное кол-во объектов sinks::SinkPtr
         * @param name имя текущего объекта (используется в реестре логгеров)
         * @param lvl уровень, ниже которого ничего логироваться не будет
         * @param args набор объектов SinkPtr
         */
        template <typename... Args>
        Logger(const std::string &name, level_t lvl, Args &&...args)
            : m_name(name)
        {
            initialize(std::forward<Args>(args)...);

            if (lvl != level_t::Undefined)
            {
                set_level(lvl);
            }
        }

        /**
         * @brief Конструктор logger
         *
         * Создает объект класса по имени, c параметром verbose, с уровнем
         * логирования lvl и списком синков. Если verbose равен true, то
         * добавляет к логгеру синк для вывода сообщений на консоль
         * (`ConsoleSink`). Также устанавливает уровень логирования lvl при
         * помощи функции `set_level(lvl)`.
         *
         * @tparam Args Args переменное кол-во объектов sinks::SinkPtr
         * @param name имя текущего объекта (используется в реестре логгеров)
         * @param verbose признак добавления синка для вывода на консоль
         * @param lvl уровень, ниже которого ничего логироваться не будет
         * @param args набор объектов SinkPtr
         */
        template <typename... Args>
        Logger(const std::string &name,
               bool verbose,
               level_t lvl,
               Args &&...args)
            : m_name(name)
        {
            initialize(verbose);
            initialize(std::forward<Args>(args)...);

            if (lvl != level_t::Undefined)
            {
                set_level(lvl);
            }
        }

        /**
         * @brief Создает сообщение из строки формата и переданных аргументов,
         * и записывает это сообщение с типом level_t::Debug во все синки,
         * установленные для текущего объекта.
         *
         * Синтаксис строки формата соответствует синтаксису строк формата из
         * библиотеки fmt. Подробнее см. https://fmt.dev/4.1.0/syntax.html
         *
         * @param format_str строка форматирования
         * @param args аргументы форматирования
         */
        void debug(const std::string &format_str, acore::format::ArgList args);

        /**
         * @brief Создает сообщение из строки формата и переданных аргументов,
         * и записывает это сообщение с типом level_t::Info во все синки,
         * установленные для текущего объекта.
         *
         * Подробное описание см. в описании метода `Logger::debug()`.
         *
         * @param format_str строка форматирования
         * @param args аргументы форматирования
         */
        void info(const std::string &format_str, acore::format::ArgList args);

        /**
         * @brief Создает сообщение из строки формата и переданных аргументов,
         * и записывает это сообщение с типом level_t::Warning во все синки,
         * установленные для текущего объекта.
         *
         * Подробное описание см. в описании метода `Logger::debug()`.
         *
         * @param format_str строка форматирования
         * @param args аргументы форматирования
         */
        void warning(const std::string &format_str,
                     acore::format::ArgList args);

        /**
         * @brief Создает сообщение из строки формата и переданных аргументов,
         * и записывает это сообщение с типом level_t::Error во все синки,
         * установленные для текущего объекта.
         *
         * Подробное описание см. в описании метода `Logger::debug()`.
         *
         * @param format_str строка форматирования
         * @param args аргументы форматирования
         */
        void error(const std::string &format_str, acore::format::ArgList args);

        /**
         * @brief Создает сообщение из строки формата и переданных аргументов,
         * и записывает это сообщение с типом level_t::Critical во все синки,
         * установленные для текущего объекта.
         *
         * Подробное описание см. в описании метода `Logger::debug()`.
         *
         * @param format_str строка форматирования
         * @param args аргументы форматирования
         */
        void critical(const std::string &format_str,
                      acore::format::ArgList args);

        FMT_VARIADIC(void, debug, const std::string &);
        FMT_VARIADIC(void, info, const std::string &);
        FMT_VARIADIC(void, warning, const std::string &);
        FMT_VARIADIC(void, error, const std::string &);
        FMT_VARIADIC(void, critical, const std::string &);
#else
    Logger(const std::string &name);

    void debug(const std::string &message);
    void info(const std::string &message);
    void warning(const std::string &message);
    void error(const std::string &message);
    void critical(const std::string &message);
#endif

        /**
         * @brief Записывает сообщение msg во все синки, связанные с логгером.
         *
         * @param msg сообщение для записи в лог
         */
        void write(const Message &msg);

        /**
         * @brief Устанавливает шаблон сообщения pattern для всех синков,
         * установленных для текущего объекта.
         *
         * Подробное см. в описании метода `Sink::set_pattern(const std::string
         * &)`
         *
         * @param pattern новый шаблон сообщения
         */
        void set_pattern(const std::string &pattern);

        /**
         * @brief Записывает все незаписанные данные по каждому синку.
         */
        void flush();

        /**
         * @brief Добавляет синк к уже существующему и настроенному объекту
         * Logger.
         *
         * @param s синк
         */
        void add_sink(SinkPtr s);

        /**
         * @brief Устанавливает форматтер f для всех синков, принадлежащих
         * логгеру.
         *
         * @param f указатель на форматтер
         */
        void set_message_formatter(MessageFormatterPtr f);

        /**
         * @brief Устанавливает уровень логирования для всех синков,
         * установленных для текущего объекта.
         *
         * @param lvl уровень логирования
         */
        void set_level(level_t lvl);

        /**
         * @brief Возвращает текущее имя логгера.
         *
         * @return const std::string& ссылка на имя логгера
         */
        const std::string &get_name() const;

        /**
         * @brief Присоединяет синки логгера other к текущему
         */
        void join(const Logger &other);

        /**
         * @brief Устанавливает фильтр для всех синков, установленных для
         * текущего объекта.
         *
         * @param filter
         */
        void set_filter(const sinks::Sink::CustomFilter &filter);

    private:
        void m_write_to_sinks(const Message &msg);

#ifndef __QNX__
        template <typename T, typename... Args>
        void initialize(T &&t, Args &&...args)
        {
            m_sinks.push_back(std::forward<T>(t));
            initialize(std::forward<Args>(args)...);
        }

        void initialize();
#endif

        void initialize(bool verbose);

        std::string m_name;
        std::vector<SinkPtr> m_sinks;
    };

#ifndef __QNX__

} // namespace acore
} // namespace logging

#endif

#endif // __ACORE_LOGGING_LOGGER_H__