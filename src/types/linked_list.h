#ifndef __TYPES_linked_LIST_H__
    #define __TYPES_linked_LIST_H__

struct linked_list {
    void *data;
    struct linked_list *next;
};

void linked_list_add(struct linked_list **list, void *data);
void linked_list_free(struct linked_list **list);
void linked_list_foreach(struct linked_list **list, void (*callback)(void *));

#endif