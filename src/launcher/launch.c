#include <stdio.h>
#include <string.h>
#include "config.h"
#include "launcher/get_files.h"
#include "launcher/files_utils.h"
#include "launcher/makefile.h"
#include "types/files.h"
#include "lib/string/join.h"

static files_list **filter_compiled_files(files_list **files)
{
    files_list **compiled_files = malloc(sizeof(files_list *));
    *compiled_files = NULL;

    for (files_list *tmp = *files; tmp; tmp = tmp->next) {
        struct file *data = get_file_data(tmp);
        if (file_is_compiled(data->path)) {
            add_file(compiled_files, *data);
        }
    }
    return compiled_files;
}

static files_list **filter_non_compiled_files(files_list **files)
{
    files_list **non_compiled_files = malloc(sizeof(files_list *));
    *non_compiled_files = NULL;

    for (files_list *tmp = *files; tmp; tmp = tmp->next) {
        struct file *data = get_file_data(tmp);
        if (!file_is_compiled(data->path)) {
            add_file(non_compiled_files, *data);
        }
    }
    return non_compiled_files;
}

static void print_non_compiled_files(files_list **files)
{
    for (files_list *tmp = *files; tmp; tmp = tmp->next) {
        struct file *data = get_file_data(tmp);
        printf("File %s is not tested\n", data->path);
    }
}

static void launch_coverage(files_list **files)
{
    files_list **compiled_files = filter_compiled_files(files);
    files_list **non_compiled_files = filter_non_compiled_files(files);
    char **files_array = files_to_array(compiled_files);
    char *files_str = join(files_array, " ");
    size_t size = strlen(files_str) + 6;
    char *command = malloc(sizeof(char) * (size));
    memset(command, 0, sizeof(char) * (size));

    sprintf(command, "gcov %s", files_str);
    if (launch_program(command) >= 0)
        print_non_compiled_files(non_compiled_files);
    else
        printf("Error while launching coverage\n");

    free(command);
    free(files_str);

    for (size_t i = 0; files_array[i]; i++)
        free(files_array[i]);
    free(files_array);

    free_files(compiled_files);
    free(compiled_files);

    free_files(non_compiled_files);
    free(non_compiled_files);
}

void launch_tests()
{
    const char *folder_name = get_test_folder();
    files_list **files = get_files(folder_name);

    create_makefile(files, "compiledSourceMakefile", "./tmp");
    if (launch_makefile("compiledSourceMakefile", "./tmp") < 0) {
        printf("Error while compiling tests\n");
        goto launch_tests_free_files;
    }
    if (launch_program("./tmp/criterion_compiled_sources") < 0) {
        printf("Error while launching tests\n");
        goto launch_tests_free_files;
    }
    files_list **tmp = get_files(folder_name);
    launch_coverage(tmp);

launch_tests_free_files:
    free_files(files);
    free(files);
}