#include <string.h>
#include <stdlib.h>

static char *test_folder = "tests/";

const char *get_test_folder()
{
    return test_folder;
}

void set_test_folder(const char *folder)
{
    test_folder = strdup(folder);
}

static void __attribute__((destructor)) free_test_folder()
{
    free(test_folder);
}