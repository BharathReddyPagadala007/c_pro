CC     := gcc
CFLAGS := -Wall -Wextra -Iinclude
SRC    := src/main.c src/encode.c src/decode.c
OBJ    := $(SRC:src/%.c=build/%.o)
TARGET := build/app

all: $(TARGET)

build/%.o: src/%.c | build
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

build:
	mkdir -p build

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf build

.PHONY: all clean run

