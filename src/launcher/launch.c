#include <stdio.h>
#include "config.h"
#include "launcher/get_files.h"
#include "launcher/makefile.h"
#include "types/files.h"

void launch_tests()
{
    const char *folder_name = get_test_folder();
    files_list **files = get_files(folder_name);

    dump_files(files);
    create_makefile(files, "compiledSourceMakefile", "./tmp");
    if (launch_makefile("compiledSourceMakefile", "./tmp") < 0) {
        printf("Error while compiling tests\n");
        return;
    }
    if (launch_program("./tmp/criterion_compiled_sources") < 0) {
        printf("Error while launching tests\n");
        return;
    }
    free_files(files);
    free(files);
    printf("Launching tests from folder: %s\n", folder_name);
}