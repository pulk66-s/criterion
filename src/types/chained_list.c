#include "types/chained_list.h"
#include <stdlib.h>

void chained_list_add(struct chained_list **list, void *data)
{
    struct chained_list *new = malloc(sizeof(struct chained_list));
    new->data = data;
    new->next = *list;
    *list = new;
}

void chained_list_free(struct chained_list **list)
{
    struct chained_list *current = *list;
    while (current != NULL) {
        struct chained_list *next = current->next;
        free(current);
        current = next;
    }
    *list = NULL;
}

void chained_list_foreach(struct chained_list *list, void (*callback)(void *))
{
    struct chained_list *current = list;
    while (current != NULL) {
        callback(current->data);
        current = current->next;
    }
}