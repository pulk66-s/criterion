CC				= gcc
INCLUDES		= -Isrc/
CFLAGS			= -W -Wall -Wextra -g3 $(INCLUDES)
SRC				= src/main.c \
				src/config/folder.c \
				src/config/makefile_flags.c \
				src/launcher/launch.c \
				src/launcher/get_files.c \
				src/launcher/makefile.c \
				src/launcher/files_utils.c \
				src/types/linked_list.c \
				src/types/files.c \
				src/lib/string/join.c \
				src/lib/string/split.c \
				src/lib/arr/reverse.c \
				src/lib/arr/size.c \
				src/args/args.c \
				src/args/flags_list.c \
				src/args/help.c

OBJ				= $(SRC:.c=.o)
GCNO			= $(SRC:.c=.gcno)
NAME			= criterion

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	make -f tmp/compiledSourceMakefile clean
	$(RM) $(OBJ)
	$(RM) $(GCNO)
	$(RM) *.gcov

fclean: clean
	make -f tmp/compiledSourceMakefile fclean
	$(RM) $(NAME)

re: fclean all

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: all clean fclean re
