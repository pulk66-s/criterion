#include "args/help.h"
#include <stdio.h>

void print_help(void)
{
    printf("Usage: ./criterion [FLAGS]\n");
    printf("Flags:\n");
    printf("\t-h, --help\t\tPrint this help message\n");
    printf("\t-f, --folder\t\tSpecify the folder containing the project\n");
    printf("\t-mf, --makefile-flags\tSpecify the flags to pass to the makefile\n");
}
