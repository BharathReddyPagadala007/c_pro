# Compiler
CC = gcc

# Archiver
AR = ar

# Compiler Flags
CFLAGS = -Wall -Wextra -c

# Library Name
LIB_NAME = libmymath.a

# Object Files
OBJS = mymath.o

# Build the static library
all: $(LIB_NAME) main

$(LIB_NAME): $(OBJS)
	$(AR) rcs $(LIB_NAME) $(OBJS)

# Compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

# compile main program with static library we craeted

main: main.c $(LIB_NAME)
	$(CC) main.c -L. -lmymath -o main

# Clean up generated files
clean:
	rm -f $(OBJS) $(LIB_NAME) main

