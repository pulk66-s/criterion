#include "lib/arr/size.h"

void reverse_str_array(char **arr)
{
    size_t size = str_arr_size(arr);
    size_t i = 0;
    size_t j = size - 1;
    char *tmp = NULL;

    while (i < j) {
        tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
        i++;
        j--;
    }
}