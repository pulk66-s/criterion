#include "launcher.h"
#include "types/files.h"
#include <stdio.h>

int main(void)
{
    files_list *files = NULL;
    struct file file = {
        .path = "test.c",
    };
    add_file(&files, file);
    file.path = "test2.c";
    add_file(&files, file);
    file.path = "test3.c";
    add_file(&files, file);
    launch_tests();
    dump_files(&files);
    return 0;
}
