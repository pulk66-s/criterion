#include "launcher.h"
#include "types/files.h"
#include "args/args.h"
#include <stdio.h>

int main(int ac, char **av)
{
    if (criterion_handle_args(ac, av) == HELP_RETURN_CODE)
        return 0;
    launch_tests();
    return 0;
}
