CC = gcc
CFLAGS = -fPIC -Iinc
LDFLAGS = -shared
BUILD_DIR = build

all: libmath.so main

libmath.so: src/mathlib.c
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c src/mathlib.c -o $(BUILD_DIR)/mathlib.o
	$(CC) $(LDFLAGS) -o $(BUILD_DIR)/libmath.so $(BUILD_DIR)/mathlib.o

main: src/main.c
	$(CC) -Iinc -L$(BUILD_DIR) src/main.c -lmath -o $(BUILD_DIR)/main

run:
	export LD_LIBRARY_PATH=$(BUILD_DIR):$$LD_LIBRARY_PATH && ./build/main

clean:
	rm -rf $(BUILD_DIR)

