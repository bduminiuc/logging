/**
 * @file default.h
 * @author bduminyuk (bduminyuk@lan.aommz.com)
 * @brief Файл описывает работу логгера по умолчанию и предоставляет
 * возможность работать с реестром логов.
 * @version 1.0
 * @date 2020-10-23
 *
 * @copyright Copyright (c) 2020
 *
 */
#ifndef __ACORE_LOGGING_DEFAULT_H__
#define __ACORE_LOGGING_DEFAULT_H__

#include "acore/format.h"
#include "message.h"

#ifndef __QNX__
namespace acore
{
namespace logging
{
#endif

    class Logger;
    class Sink;

#ifndef __QNX__
    /**
     * @brief Создает сообщение из строки формата и переданных аргументов,
     * и записывает это сообщение с типом level_t::Debug в логгер по умолчанию.
     *
     * Логгер по умолчанию должен быть предварительно настроен. Изначально
     * из соображений производительности логгер по умолчанию не установлен.
     *
     * Для работы этих методов необходимо создать свой объект класса Logger, а
     * затем установить его при помощи метода `set_default()`.
     *
     * При попытке использовать "неустановленный логгер" будет выброшено
     * исключение std::runtime_error.
     *
     * Пример:
     *
     * ```cpp
     * acore::logging::LoggerPtr loggerPtr(new acore::Logging::Logger(
     *     "defaultLogger",
     *     acore::logging::sinks::make_sink<acore::logging::sinks::FileSink>("example.txt")
     * ));
     *
     * acore::logging::set_default(loggerPtr);
     *
     * // теперь работают функции
     * acore::logging::debug("Some message");
     * acore::logging::info("Other message");
     * ```
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
     * и записывает это сообщение с типом level_t::Info в логгер по умолчанию.
     *
     * Подробное описание см. в описании функции `acore::logging::debug()`.
     *
     * @param format_str строка форматирования
     * @param args аргументы форматирования
     */
    void info(const std::string &format_str, acore::format::ArgList args);

    /**
     * @brief Создает сообщение из строки формата и переданных аргументов,
     * и записывает это сообщение с типом level_t::Warning в логгер по
     * умолчанию.
     *
     * Подробное описание см. в описании функции `acore::logging::debug()`.
     *
     * @param format_str строка форматирования
     * @param args аргументы форматирования
     */
    void warning(const std::string &format_str, acore::format::ArgList args);

    /**
     * @brief Создает сообщение из строки формата и переданных аргументов,
     * и записывает это сообщение с типом level_t::Error в логгер по умолчанию.
     *
     * Подробное описание см. в описании функции `acore::logging::debug()`.
     *
     * @param format_str строка форматирования
     * @param args аргументы форматирования
     */
    void error(const std::string &format_str, acore::format::ArgList args);

    /**
     * @brief Создает сообщение из строки формата и переданных аргументов,
     * и записывает это сообщение с типом level_t::Critical в логгер по
     * умолчанию.
     *
     * Подробное описание см. в описании функции `acore::logging::debug()`.
     *
     * @param format_str строка форматирования
     * @param args аргументы форматирования
     */
    void critical(const std::string &format_str, acore::format::ArgList args);

    void append(const std::string &path,
                const std::string &format_str,
                acore::format::ArgList args);

    FMT_VARIADIC(void, debug, const std::string &);
    FMT_VARIADIC(void, info, const std::string &);
    FMT_VARIADIC(void, warning, const std::string &);
    FMT_VARIADIC(void, error, const std::string &);
    FMT_VARIADIC(void, critical, const std::string &);
    FMT_VARIADIC(void, append, const std::string &, const std::string &);

#else

void debug(const std::string &message);
void info(const std::string &message);
void warning(const std::string &message);
void error(const std::string &message);
void critical(const std::string &message);
void append(const std::string &path, const std::string &message);

#endif

    /**
     * @brief Устанавливает логгер по умолчанию для использования
     * функциями `debug()`, `info()`, `warning()`, `critical()`.
     *
     * @param lptr умный указатель на логгер
     */
    void set_default(LoggerPtr lptr);

    /**
     * @brief Регистрирует lptr в реестре логгеров.
     *
     * @param lptr умный указатель на логгер
     */
    void register_logger(LoggerPtr lptr);

    /**
     * @brief Возвращает умный указатель на логгер, чье имя равно name.
     *
     * Бросает исключение, если не найден логгер с именем name.
     *
     * @param name имя логгреа в реестре
     * @return LoggerPtr умный указатель на логгер
     */
    LoggerPtr get(const std::string &name);

    /**
     * @brief Возвращает указатель на логгер по умолчанию.
     *
     * @return LoggerPtr указатель на логгер по умолчанию
     */
    LoggerPtr get_default();

    /**
     * @brief Удаляет из реестра логгеров логгер с указанным name.
     *
     * Если логгер с именем name не зарегистрирован, выходит из функции,
     * ничего не изменяя.
     *
     * @param name имя логгера для удаления.
     */
    void drop(const std::string &name);

    /**
     * @brief Очищает реестр логгеров.
     */
    void drop_all();

#ifndef __QNX__
} // namespace logging
} // namespace acore
#endif

#endif // __ACORE_LOGGING_DEFAULT_H__