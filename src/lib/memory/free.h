#ifndef __CRITERION_LIB_MEMORY_FREE_H__
    #define __CRITERION_LIB_MEMORY_FREE_H__

void my_free(void *ptr);

    #define free(ptr) my_free(ptr)

#endif