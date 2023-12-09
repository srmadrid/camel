CC=gcc
CFLAGS=-Wall -Wextra -fPIC
LDFLAGS=-shared
SOURCES=$(shell find src -name '*.c')
OBJECTS=$(SOURCES:.c=.o)
OUTDIR=bin
TARGET_LINUX=$(OUTDIR)/linux/camel.so
TARGET_WINDOWS=$(OUTDIR)/windows/camel.dll

.PHONY: all clean linux windows

all: linux windows

linux: $(TARGET_LINUX)

windows: $(TARGET_WINDOWS)

$(TARGET_LINUX): $(OBJECTS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(OBJECTS)

$(TARGET_WINDOWS): $(OBJECTS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $(OBJECTS) -Wl,--out-implib,$(OUTDIR)/windows/libcamel.a

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET_LINUX) $(TARGET_WINDOWS) $(OUTDIR)/windows/libcamel.a
