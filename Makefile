# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -std=c11

# Source files
SRC = vk.c cmds.c userVar.c

# Output binary
OUT = vk

# Default target
all: $(OUT)

# Link object files
$(OUT): $(SRC)
	$(CC) $(CFLAGS) -o $(OUT) $(SRC)

# Clean up build files
clean:
	rm -f $(OUT)

# To compile to .exe for windows:
# gcc -Wall -Wextra -std=c11 -o vk vk.c cmds.c userVar.c