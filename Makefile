# Detect the platform (Linux/Windows)
OS := $(shell uname -s)
ifeq ($(OS),Linux)
    TARGET = bin/linux/libcamel.so
    TEST_TARGET = test/bin/linux/test
    EXT = so
    CFLAGS = -pedantic -Wall -Wextra -Werror -Iinclude -fPIC -msse3 # -g #(to debug if something like a segfault occurs)
    LDFLAGS = -shared -lm
    LIB_LINK = -Lbin/linux -Wl,-rpath,'$$ORIGIN/../../../bin/linux' -lcamel -lm
else
    TARGET = bin/windows/camel.dll
    TEST_TARGET = test/bin/windows/test.exe
    EXT = dll
    CFLAGS = -pedantic -Wall -Wextra -Werror -Iinclude
    LDFLAGS = -shared -lm
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

# Install settings
ifeq ($(PREFIX),)
	PREFIX := /usr/local
endif

# Default rule (only library)
lib: $(TARGET)

$(TARGET): $(OBJECTS)
	@echo "Linking: $@"
	@$(CC) $(LDFLAGS) -o $@ $^
	@echo "Cleaning up..."
	@$(RM) $(OBJECTS)
	@echo "Build complete."

# All rule
all: lib $(TEST_TARGET)

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

# Install rule
install: lib
	@echo "Installing..."
	install -d $(DESTDIR)$(PREFIX)/lib/
	install -m 644 $(TARGET) $(DESTDIR)$(PREFIX)/lib/
	install -d $(DESTDIR)$(PREFIX)/include/camel/
	cp -R $(HDR_DIRS)/* $(DESTDIR)$(PREFIX)/include/camel/
	@echo "Install complete."

# Uninstall rule
uninstall:
	@echo "Uninstalling..."
	@rm -f $(DESTDIR)$(PREFIX)/lib/$(TARGET)
	@rm -rf $(DESTDIR)$(PREFIX)/include/camel/
	@echo "Uninstall complete."

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

.PHONY: all clean clean-test clean-all test lib install