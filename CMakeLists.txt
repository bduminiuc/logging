add_library(acore_logging
    logger.cpp
    default.cpp
    message.cpp
    level_t.cpp
    formatters/path_formatter.cpp
    formatters/default_path_formatter.cpp
    formatters/message_formatter.cpp
    formatters/default_message_formatter.cpp    
    sinks/sink.cpp
    sinks/file_sink.cpp 
    sinks/stdout_sink.cpp 
    sinks/stderr_sink.cpp 
    sinks/stdout_color_sink.cpp
    sinks/stderr_color_sink.cpp
    sinks/console_sink.cpp
    sinks/console_color_sink.cpp
    sinks/message_queue_sink.cpp
    sinks/null_sink.cpp
    sinks/details/color.cpp
    ext/sink_decorator.cpp
    ext/history_decorator.cpp
    ext/filters.cpp
)

acore_configure_target(acore_logging)

target_link_libraries(acore_logging 
    PUBLIC acore_format acore_interprocess acore_std
)
