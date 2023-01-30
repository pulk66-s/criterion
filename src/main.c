#include "launcher.h"
#include "types/files.h"
#include "config.h"
#include <stdio.h>

static void config_criterion(int ac, char **av)
{
    if (ac < 2)
        return;
    set_test_folder(av[1]);
}

int main(int ac, char **av)
{
    config_criterion(ac, av);
    launch_tests();
    return 0;
}
