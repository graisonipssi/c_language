CC=gcc
CFLAGS=-fno-stack-protector -z execstack -no-pie
TARGET=ret2win
SOURCES=ret2win.c

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES)
	@if [ $$(id -u) -eq 0 ]; then \
		echo "Root detected: Setting SUID and owner"; \
		chown root:root $(TARGET); \
		chmod 4755 $(TARGET); \
	else \
		echo "Note: Not running as root. SUID bit (4755) not set."; \
	fi

debug: $(SOURCES)
	$(CC) $(CFLAGS) -g -o $(TARGET)_debug $(SOURCES)

clean:
	rm -f $(TARGET) $(TARGET)_debug core

build:
	zip -r $(TARGET).zip .

.PHONY: clean debug
