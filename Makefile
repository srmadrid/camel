# Detect the platform (Linux/Windows)
OS := $(shell uname -s)
ifeq ($(OS),Linux)
    TARGET = bin/linux/camel.so
    TEST_TARGET = test/bin/linux/test
    EXT = so
    CFLAGS = -Wall -Iinclude -fPIC
    LDFLAGS = -shared -lm
    LIB_LINK = -Lbin/linux -lcamel -lm
else
    TARGET = bin/win/camel.dll
    TEST_TARGET = test/bin/win/test.exe
    EXT = dll
    CFLAGS = -Wall -Iinclude
    LDFLAGS = -shared
    LIB_LINK = -Lbin/win -lcamel -lm
endif

# Compiler settings
CC = gcc
SRC_DIRS = src
SOURCES = $(shell find $(SRC_DIRS) -type f -name '*.c')
OBJECTS = $(SOURCES:%.c=%.o)
HDR_DIRS = include
HEADERS = $(shell find $(HDR_DIRS) -type f -name '*.h')

# Test settings
TEST_SRC_DIRS = test
TEST_SOURCES = $(shell find $(TEST_SRC_DIRS) -type f -name '*.c')
TEST_OBJECTS = $(TEST_SOURCES:%.c=%.o)


# Default rule (only library)
$(TARGET): $(OBJECTS)
	@echo "Linking: $@"
	@$(CC) $(LDFLAGS) -o $@ $^
	@echo "Cleaning up..."
	@$(RM) $(OBJECTS)
	@echo "Build complete."

# All rule
all: $(TARGET) $(TEST_TARGET)

# Rule for test executable
test: $(TEST_TARGET)

$(TEST_TARGET): $(TEST_OBJECTS)
	@echo "Linking: $@"
	@$(CC) $(LIB_LINK) -o $@ $^
	@echo "Cleaning up..."
	@$(RM) $(TEST_OBJECTS)
	@echo "Test build complete."

# Rule for object files
%.o: %.c $(HEADERS)
	@echo "Compiling: $<"
	@$(CC) $(CFLAGS) -c $< -o $@

# Clean rule
clean:
	@echo "Cleaning..."
	@$(RM) $(OBJECTS) $(TARGET)
	@echo "Clean complete."

clean-test:
	@echo "Cleaning test..."
	@$(RM) $(TEST_OBJECTS) $(TEST_TARGET)
	@echo "Test clean complete."

clean-all: clean clean-test

.PHONY: all clean clean-test clean-all test