#include "lib/arr/size.h"

size_t str_arr_size(char **arr)
{
    size_t i = 0;

    for (; arr[i]; i++);
    return i;
}
