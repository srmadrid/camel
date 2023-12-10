# Detect the platform (Linux/Windows)
OS := $(shell uname -s)
ifeq ($(OS),Linux)
    TARGET = bin/linux/camel.so
    EXT = so
    CFLAGS = -Wall -Iinclude -fPIC
    LDFLAGS = -shared -lm
else
    TARGET = bin/win/camel.dll
    EXT = dll
    CFLAGS = -Wall -Iinclude
    LDFLAGS = -shared
endif

# Compiler settings
CC = gcc
SRC_DIRS = src
SOURCES = $(shell find $(SRC_DIRS) -type f -name '*.c')
OBJECTS = $(SOURCES:%.c=%.o)
HDR_DIRS = include
HEADERS = $(shell find $(HDR_DIRS) -type f -name '*.h')

# Default rule
all: $(TARGET)

# Rule for shared library
$(TARGET): $(OBJECTS)
	@echo "Linking: $@"
	@$(CC) $(LDFLAGS) -o $@ $^
	@echo "Cleaning up..."
	@$(RM) $(OBJECTS)
	@echo "Build complete."

# Rule for object files
%.o: %.c $(HEADERS)
	@echo "Compiling: $<"
	@$(CC) $(CFLAGS) -c $< -o $@

# Clean rule
clean:
	@echo "Cleaning..."
	@$(RM) $(OBJECTS) $(TARGET)
	@echo "Clean complete."

.PHONY: all clean
