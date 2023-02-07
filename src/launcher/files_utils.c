#include "launcher/files_utils.h"
#include "lib/string/split.h"
#include "lib/string/is_in.h"
#include <stdlib.h>
#include <string.h>

char *build_file_path(const char *folder_name, const char *file_name)
{
    char *file_path = NULL;
    size_t file_name_size = strlen(file_name);
    size_t folder_name_size = strlen(folder_name);
    size_t file_path_size = file_name_size + folder_name_size + 1;

    if (folder_name[folder_name_size - 1] != '/')
        file_path_size++;
    file_path = malloc(sizeof(char) * file_path_size);
    memset(file_path, 0, file_path_size);
    strcat(file_path, folder_name);
    if (folder_name[folder_name_size - 1] != '/')
        strcat(file_path, "/");
    strcat(file_path, file_name);
    return file_path;
}

int file_exist(const char *name, const char *dir)
{
    char *file_path = build_file_path(dir, name);
    FILE *file = fopen(file_path, "r");

    if (!file) {
        free(file_path);
        return 0;
    }
    free(file_path);
    fclose(file);
    return 1;
}

void rm_file(const char *name, const char *dir)
{
    char *file_path = build_file_path(dir, name);

    if (remove(file_path) == -1)
        printf("Error: Can't remove file %s\n", file_path);
    free(file_path);
}

FILE *create_file(const char *name, const char *dir)
{
    char *file_path = build_file_path(dir, name);
    FILE *file = fopen(file_path, "w");

    if (!file) {
        printf("Error: Can't create file %s\n", file_path);
        free(file_path);
        return NULL;
    }
    free(file_path);
    return file;
}

static char *get_file_name(char *path)
{
    char **splitted_path = split(path, ".");
    char *base = splitted_path[0];
    size_t res_size = strlen(base) + 6;
    char *res = malloc(sizeof(char) * (res_size));

    memset(res, 0, sizeof(char) * (res_size));
    strcat(res, base);
    strcat(res, ".gcda");
    for (size_t i = 0; splitted_path[i]; i++)
        free(splitted_path[i]);
    free(splitted_path);
    return res;
}

int file_is_compiled(char *path)
{
    if (!is_in('.', path))
        return 0;
    char *file_name = get_file_name(path);
    return file_exist(file_name, "./");
}