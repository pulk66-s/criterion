CC		= gcc
SRC		= src/strlen.c \
		src/strcmp.c
OBJ		= $(SRC:.c=.o)
NAME	= libbasic_libc.a
CFLAGS	= -Wall -Wextra -Werror -I./

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
