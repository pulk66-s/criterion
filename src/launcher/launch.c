#include <stdio.h>
#include <string.h>
#include "config.h"
#include "launcher/get_files.h"
#include "launcher/makefile.h"
#include "types/files.h"
#include "lib/string/join.h"

static void launch_coverage(files_list **files)
{
    char **files_array = files_to_array(files);
    char *files_str = join(files_array, " ");
    size_t size = strlen(files_str) + 5;
    char *command = malloc(sizeof(char) * (size));
    memset(command, 0, sizeof(char) * (size));

    sprintf(command, "gcov %s", files_str);
    if (launch_program(command) < 0) {
        printf("Error while launching coverage\n");
        return;
    }
    free(command);
    free(files_str);
    free(files_array);
}

void launch_tests()
{
    const char *folder_name = get_test_folder();
    files_list **files = get_files(folder_name);

    create_makefile(files, "compiledSourceMakefile", "./tmp");
    if (launch_makefile("compiledSourceMakefile", "./tmp") < 0) {
        printf("Error while compiling tests\n");
        return;
    }
    if (launch_program("./tmp/criterion_compiled_sources") < 0) {
        printf("Error while launching tests\n");
        return;
    }
    launch_coverage(get_files(folder_name));
    free_files(files);
    free(files);
}