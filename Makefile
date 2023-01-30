CC				= gcc
INCLUDES		= -Isrc/
CFLAGS			= -W -Wall -Wextra -g3 $(INCLUDES)
SRC				= src/main.c \
				src/config/folder.c \
				src/launcher/launch.c \
				src/types/chained_list.c \
				src/types/files.c
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
