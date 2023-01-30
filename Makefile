CC				= gcc
CFLAGS			= -W -Wall -Wextra -g3
SRC				= src/main.c
OBJ				= $(SRC:.c=.o)
NAME			= criterion

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: all clean fclean re
