#include "types/files.h"
#include <stdio.h>

void add_file(files_list **files, struct file file)
{
    struct file *new_file = malloc(sizeof(struct file));
    *new_file = file;
    chained_list_add(files, new_file);
}

void dump_file(struct file file)
{
    printf("File: %s\n", file.path);
}

static void dump_file_ptr(void *file)
{
    dump_file(*(struct file *)file);
}

void dump_files(files_list **files)
{
    chained_list_foreach(*files, &dump_file_ptr);
}
