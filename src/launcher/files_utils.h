#ifndef __CRITERION_LAUNCHER_FILES_UTILS_H__
    #define __CRITERION_LAUNCHER_FILES_UTILS_H__

    #include <stdio.h>

char *build_file_path(const char *dir, const char *file);
int file_exist(const char *name, const char *dir);
void rm_file(const char *name, const char *dir);
FILE *create_file(const char *name, const char *dir);
int file_is_compiled(char *path);

#endif