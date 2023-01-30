#ifndef __LAUNCHER_GET_FILES_H__
    #define __LAUNCHER_GET_FILES_H__

    #include "types/files.h"

files_list **get_files(const char *folder);
char *build_file_path(const char *folder_name, const char *file_name);

#endif