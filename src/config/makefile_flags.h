#ifndef __CRITERION_CONFIG_MAKEFILE_FLAGS_H__
    #define __CRITERION_CONFIG_MAKEFILE_FLAGS_H__

    #include "types/linked_list.h"

void add_makefile_flag(const char *flag);
void add_makefile_flags_str(const char *flags);
struct linked_list *get_makefile_flags(void);

#endif