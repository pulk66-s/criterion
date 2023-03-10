#include "launcher/makefile.h"
#include "launcher/files_utils.h"
#include "config.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>

static char *makefile_lines[] = {
    "CC = gcc",
    "INCLUDES = -I./src",
    "COV_FLAGS = -lgcov --coverage -fprofile-arcs -ftest-coverage",
    "CFLAGS += -W -Wall -Wextra $(COV_FLAGS) $(INCLUDES) -g3",
    "NAME = ./tmp/criterion_compiled_sources",
    "OBJ = $(SRC:.c=.o)",
    "GCNO = $(SRC:.c=.gcno)",
    "GCDA = $(SRC:.c=.gcda)",
    "",
    "all: $(NAME)",
    "",
    "$(NAME): $(OBJ)",
    "\t@$(CC) $(COV_FLAGS) -o $(NAME) $(OBJ)",
    "",
    "clean:",
    "\t@$(RM) $(OBJ)",
    "\t@$(RM) $(GCNO)",
    "\t@$(RM) $(GCDA)",
    "",
    "fclean: clean",
    "\t@$(RM) $(NAME)",
    "",
    "re: fclean all",
    "",
    ".PHONY: all clean fclean re",
    "",
    "%.o: %.c",
    "\t@$(CC) -o $@ -c $< $(CFLAGS)",
    NULL
};

static char *additionnal_sources[] = {
    "src/types/tests.c",
    "src/types/linked_list.c",
    "src/types/memory_leak.c",
    "src/lib/launch/main.c",
    "src/lib/env/results.c",
    "src/lib/tests/tests.c",
    "src/lib/tests/memory.c",
    "src/lib/memory/malloc.c",
    "src/lib/memory/free.c",
    "src/lib/memory/datas.c",
    "src/lib/asserts/asserts.c",
    "src/lib/asserts/string.c",
    "src/lib/asserts/io.c",
    NULL
};

static void write_files_list(files_list **files, FILE *makefile)
{
    fprintf(makefile, "SRC = ");
    for (files_list *tmp = *files; tmp; tmp = tmp->next) {
        struct file *file = tmp->data;
        fprintf(makefile, "\t%s \\\n", file->path);
    }
    fprintf(makefile, "\n");
}

static void fill_additionnal_sources(files_list **files)
{
    for (size_t i = 0; additionnal_sources[i]; i++) {
        add_file(files, (struct file) { .path = strdup(additionnal_sources[i]) });
    }
}

static void fill_additionnal_flags(FILE *makefile)
{
    struct linked_list *flags = get_makefile_flags();

    fprintf(makefile, "CFLAGS = ");
    for (struct linked_list *tmp = flags; tmp; tmp = tmp->next) {
        fprintf(makefile, "%s ", (char *) tmp->data);
    }
    fprintf(makefile, "\n");
}

static void fill_makefile(files_list **files, FILE *makefile)
{
    fill_additionnal_sources(files);
    fill_additionnal_flags(makefile);
    write_files_list(files, makefile);
    for (size_t i = 0; makefile_lines[i]; i++)
        fprintf(makefile, "%s\n", makefile_lines[i]);
}

void create_makefile(files_list **files, const char *name, const char *dir)
{
    if (file_exist(name, dir))
        rm_file(name, dir);
    FILE *makefile = create_file(name, dir);

    if (!makefile)
        return;
    fill_makefile(files, makefile);
    fclose(makefile);
}

int launch_program(const char *path)
{
    if (system(path) != 0) {
        return -1;
    }
    return 0;
}

int launch_makefile(const char *name, const char *dir)
{
    char *base_cmd = "make re -f ";
    size_t base_cmd_size = strlen(base_cmd);
    char *file_path = build_file_path(dir, name);
    size_t cmd_size = base_cmd_size + strlen(file_path) + 1;
    char *cmd = malloc(sizeof(char) * cmd_size);

    memset(cmd, 0, cmd_size);
    strcat(cmd, base_cmd);
    strcat(cmd, file_path);
    if (system(cmd) != 0) {
        free(file_path);
        free(cmd);
        return -1;
    }
    free(cmd);
    free(file_path);
    return 0;
}
