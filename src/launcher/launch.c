#include <stdio.h>
#include "launcher/config.h"

void launch_tests()
{
    const char *folder_name = get_test_folder();
    printf("Launching tests from folder: %s\n", folder_name);
}