#ifndef __TYPES_CHAINED_LIST_H__
    #define __TYPES_CHAINED_LIST_H__

struct chained_list {
    void *data;
    struct chained_list *next;
};

void chained_list_add(struct chained_list **list, void *data);
void chained_list_free(struct chained_list **list);
void chained_list_foreach(struct chained_list *list, void (*callback)(void *));

#endif