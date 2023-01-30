#ifndef __CRITERION_LAUNCHER_MAKEFILE_H__
    #define __CRITERION_LAUNCHER_MAKEFILE_H__

    #include "types/files.h"

void create_makefile(files_list **files, const char *name, const char *dir);
int launch_makefile(const char *name, const char *dir);
int launch_program(const char *path);

#endif