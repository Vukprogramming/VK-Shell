# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -std=c11

# Source files
SRC = vk.c src/basic_cmds/cmds.c src/userVar.c src/calc_cmds/calc.c  src/file_cmds/file_io.c  src/user_cmds/user.c

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
# gcc -Wall -Wextra -std=c11 -o vk vk.c src/basic_cmds/cmds.c src/userVar.c src/calc_cmds/calc.c  src/file_cmds/file_io.c  src/user_cmds/user.c