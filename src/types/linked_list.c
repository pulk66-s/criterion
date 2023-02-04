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
        if (current->data)
            callback(current->data);
        current = current->next;
    }
}

void linked_list_delete(struct linked_list **list, void *to_delete, int (*condition)(void *, void *))
{
    struct linked_list *current = *list;
    struct linked_list *previous = NULL;

    while (current != NULL) {
        if (condition(current->data, to_delete)) {
            if (previous == NULL) {
                *list = current->next;
            } else {
                previous->next = current->next;
            }
            free(current->data);
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

void *linked_list_get(struct linked_list **list, void *to_get, int (*condition)(void *, void *))
{
    struct linked_list *current = *list;

    while (current != NULL) {
        if (condition(current->data, to_get)) {
            return current->data;
        }
        current = current->next;
    }
    return NULL;
}

size_t linked_list_size(struct linked_list **list)
{
    struct linked_list *current = *list;
    size_t size = 0;

    while (current != NULL) {
        size++;
        current = current->next;
    }
    return size;
}