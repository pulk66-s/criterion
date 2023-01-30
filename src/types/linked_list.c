#include "types/linked_list.h"
#include <stdlib.h>

void linked_list_add(struct linked_list **list, void *data)
{
    struct linked_list *new = malloc(sizeof(struct linked_list));
    new->data = data;
    new->next = *list;
    *list = new;
}

void linked_list_free(struct linked_list **list)
{
    struct linked_list *current = *list;
    while (current != NULL) {
        struct linked_list *next = current->next;
        free(current->data);
        free(current);
        current = next;
    }
    *list = NULL;
}

void linked_list_foreach(struct linked_list **list, void (*callback)(void *))
{
    struct linked_list *current = *list;
    while (current != NULL) {
        callback(current->data);
        current = current->next;
    }
}