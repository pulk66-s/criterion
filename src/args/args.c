#include "args/args.h"
#include "args/flags_list.h"
#include "args/help.h"
#include "config.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static void extract_command(char **command, char *arg)
{
    if (*command)
        free(*command);
    *command = strdup(arg);
}

static int parse_arg(char *command, char *arg)
{
    if (!command)
        return 0;
    printf("Parsing arg: %s %s\n", command, arg);
    if (is_makefile_flag(command)) {
        printf("Adding makefile flag:\n");
        add_makefile_flags_str(arg);
    }
    if (is_folder_flag(command))
        set_test_folder(arg);
    return 0;
}

static int command_loop(int ac, char **av)
{
    char *command = NULL;

    for (int i = 1; i < ac; ++i) {
        if (av[i][0] == '-') {
            extract_command(&command, av[i]);
            if (is_help_flag(command)) {
                print_help();
                return HELP_RETURN_CODE;
            }
            if (i < ac - 1) {
                int res = parse_arg(command, av[i + 1]);

                if (res)
                    return res;
            }
        }
    }
    return 0;
}

int criterion_handle_args(int ac, char **av)
{
    if (ac < 2)
        return 0;

    int res = command_loop(ac, av);

    if (res)
        return res;
    return 0;
}