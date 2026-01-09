CC=gcc
CFLAGS=-fno-stack-protector -z execstack -no-pie
TARGET=grimoire

all: $(TARGET)

# cible: dépendances
$(TARGET): grimoire.c
	$(CC) $(CFLAGS) -o $@ $^
	sudo chown root:root $(TARGET)
	sudo chmod u+s $(TARGET)

debug: grimoire.c
	$(CC) $(CFLAGS) -g -o $(TARGET)_debug $^

clean:
	rm -f $(TARGET) $(TARGET)_debug

.PHONY: all clean debug
