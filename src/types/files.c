#include "types/files.h"
#include <stdio.h>
#include <string.h>

void add_file(files_list **files, struct file file)
{
    struct file *new_file = malloc(sizeof(struct file));
    *new_file = file;
    linked_list_add(files, new_file);
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
    if (!files)
        return;
    linked_list_foreach(files, &dump_file_ptr);
}

static void free_file(void *ptr)
{
    struct file *file = ptr;

    free(file->path);
}

void free_files(files_list **files)
{
    linked_list_foreach(files, free_file);
    linked_list_free(files);
}

size_t files_list_size(files_list **files)
{
    return linked_list_size(files);
}

char **files_to_array(files_list **files)
{
    files_list *tmp = *files;
    size_t size = files_list_size(files);
    char **array = malloc(sizeof(char *) * (size + 1));

    memset(array, 0, sizeof(char *) * (size + 1));
    for (size_t i = 0; i < size; i++) {
        array[i] = strdup(((struct file *)tmp->data)->path);
        tmp = tmp->next;
    }
    return array;
}