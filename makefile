.SECONDEXPANSION:
.PHONY: all clean install

override CFLAGS += 

BUILD_DIR := build

ACORE_DIR = /ASUTP_SRC/LIB/acore

INCLUDE = -I$(ACORE_DIR)

HDR_EXTERN=/ASUTP_SRC/hdr_extern
LIB_EXTERN=/ASUTP_SRC/lib_extern


all: logging

# build all targets in BUILD_DIR
logging:
	cc -c $(CFLAGS) \
	message.cpp \
	default.cpp \
	logger.cpp \
	level_t.cpp \
	formatters/path_formatter.cpp \
	formatters/message_formatter.cpp \
	formatters/default_path_formatter.cpp \
	formatters/default_message_formatter.cpp \
	sinks/sink.cpp \
	sinks/null_sink.cpp \
	sinks/console_sink.cpp \
	sinks/file_sink.cpp \
	sinks/stdout_sink.cpp \
	sinks/stderr_sink.cpp \
	ext/sink_decorator.cpp \
	ext/history_decorator.cpp \
	$(INCLUDE)

	wlib -n -b acore_logging.lib *.o
	rm *.o

main:
	cc $(CFLAGS) main.cpp -o main $(INCLUDE) -lacore_logging
	 

clean:
	rm -rf $(BUILD_DIR)

install:
	cp -r ../std $(HDR_EXTERN)/acore

	cp ../format/format.h ../format/qnx_format.hpp $(HDR_EXTERN)/acore/format
	cp ../format.h $(HDR_EXTERN)/acore/format.h
	
	cp *.h $(HDR_EXTERN)/acore/logging
	cp ext/*.h $(HDR_EXTERN)/acore/logging/ext
	cp formatters/*.h $(HDR_EXTERN)/acore/logging/formatters
	cp sinks/*.h $(HDR_EXTERN)/acore/logging/sinks

	cp acore_logging.lib $(LIB_EXTERN)/acore


