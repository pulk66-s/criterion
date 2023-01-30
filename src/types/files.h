#ifndef __CRITERION_TYPES_FILES_H__
    #define __CRITERION_TYPES_FILES_H__

    #include <stdlib.h>
    #include "types/linked_list.h"

typedef struct linked_list files_list;

struct file {
    char *path;
};

void add_file(files_list **files, struct file file);
void dump_files(files_list **files);
void dump_file(struct file file);
void free_files(files_list **files);

#endif