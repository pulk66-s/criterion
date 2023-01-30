#include <stdio.h>
#include "config.h"
#include "launcher/get_files.h"
#include "types/files.h"

void launch_tests()
{
    const char *folder_name = get_test_folder();
    files_list **files = get_files(folder_name);
    dump_files(files);
    free_files(files);
    free(files);
    printf("Launching tests from folder: %s\n", folder_name);
}