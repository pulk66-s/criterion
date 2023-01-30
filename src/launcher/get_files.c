#include "launcher/get_files.h"
#include "launcher/files_utils.h"
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

static int is_file(const char *name)
{
    struct stat path;

    stat(name, &path);
    return S_ISREG(path.st_mode);
}

static int is_cfile(const char *name)
{
    size_t name_size = strlen(name);

    return name[name_size - 1] == 'c' && name[name_size - 2] == '.';
}


static int is_builtin_folder(const char *file_name)
{
    size_t file_name_size = strlen(file_name);

    return file_name[file_name_size - 1] == '.';
}

static void fill_files(const char *folder_name, files_list **files)
{
    struct dirent *dir;
    char *file_path = NULL;
    DIR *d = opendir(folder_name);

    if (!d)
        return;
    while ((dir = readdir(d)) != NULL) {
        file_path = build_file_path(folder_name, dir->d_name);
        if (is_builtin_folder(file_path))
            goto end_loop;
        if (is_file(file_path) && is_cfile(file_path)) {
            add_file(files, (struct file) {
                .path = strdup(file_path)
            });
        } else {
            fill_files(file_path, files);
        }
end_loop:
        free(file_path);
    }
    closedir(d);
}

files_list **get_files(const char *folder_name)
{
    files_list **files = malloc(sizeof(files_list *));

    *files = NULL;
    fill_files(folder_name, files);
    return files;
}