# Compiler
CC = gcc

# Compiler Flags
CFLAGS = -Wall -Werror -Wextra -pedantic

# Source Files
SOURCES = main.c simple_shell.c execute.c tokenize.c builtins.c path.c error_handler.c getline_custom.c utility_functions.c

# Object Files
OBJECTS = $(SOURCES:.c=.o)

# Executable Name
EXEC = hsh

# Targets
all: $(SOURCES) $(EXEC)

$(EXEC): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXEC)

