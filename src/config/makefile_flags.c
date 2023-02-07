#include "config/makefile_flags.h"
#include "lib/string/split.h"
#include "lib/arr.h"
#include <string.h>

static struct linked_list *makefile_flags = NULL;

void add_makefile_flag(const char *flag)
{
    linked_list_add(&makefile_flags, strdup(flag));
}

void add_makefile_flags_str(const char *flags)
{
    char **splitted = split(flags, " ");

    reverse_str_array(splitted);
    for (size_t i = 0; splitted[i]; i++) {
        add_makefile_flag(splitted[i]);
    }
}

struct linked_list *get_makefile_flags(void)
{
    return makefile_flags;
}