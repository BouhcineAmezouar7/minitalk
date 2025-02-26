# Source files
FUNCTIONS = ft_functions_utils.c ft_putstr.c 

SERVER = server.c
CLIENT = client.c
BONUS_SERVER = server_bonus.c
BONUS_CLIENT = client_bonus.c

# Compiler
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Object files
OBJECTS = $(FUNCTIONS:.c=.o)

# Executable names
EXEC_SERVER = server
EXEC_CLIENT = client
EXEC_BONUS_SERVER = server_bonus
EXEC_BONUS_CLIENT = client_bonus

# Clean command
RM = rm -f

# Default target
all: $(EXEC_SERVER) $(EXEC_CLIENT)

# Build targets
$(EXEC_SERVER): $(OBJECTS) $(SERVER)
	$(CC) $(CFLAGS) $(OBJECTS) $(SERVER) -o $(EXEC_SERVER)

$(EXEC_CLIENT): $(OBJECTS) $(CLIENT)
	$(CC) $(CFLAGS) $(OBJECTS) $(CLIENT) -o $(EXEC_CLIENT)

# Bonus target
bonus: $(EXEC_BONUS_SERVER) $(EXEC_BONUS_CLIENT)

$(EXEC_BONUS_SERVER): $(OBJECTS) $(BONUS_SERVER)
	$(CC) $(CFLAGS) $(OBJECTS) $(BONUS_SERVER) -o $(EXEC_BONUS_SERVER)

$(EXEC_BONUS_CLIENT): $(OBJECTS) $(BONUS_CLIENT)
	$(CC) $(CFLAGS) $(OBJECTS) $(BONUS_CLIENT) -o $(EXEC_BONUS_CLIENT)

# Rule for object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean targets
clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(EXEC_SERVER) $(EXEC_CLIENT) $(EXEC_BONUS_SERVER) $(EXEC_BONUS_CLIENT)

# Rebuild target
re: fclean all

# Phony targets
.PHONY: all clean fclean re bonus

.SECONDARY: $(OBJECTS)
