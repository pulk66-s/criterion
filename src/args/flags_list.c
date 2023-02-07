#include <string.h>

int is_makefile_flag(const char *flag)
{
    return !strcmp(flag, "-mf") || !strcmp(flag, "--makefile-flags");
}

int is_help_flag(const char *flag)
{
    return !strcmp(flag, "-h") || !strcmp(flag, "--help");
}

int is_folder_flag(const char *flag)
{
    return !strcmp(flag, "-f") || !strcmp(flag, "--folder");
}