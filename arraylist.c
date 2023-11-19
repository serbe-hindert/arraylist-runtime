#include "arraylist.h"

_Bool ArrayList_init(struct ArrayList* list, unsigned int initialSize, size_t datatypeSize) {
    list->count = 0;
    list->size = initialSize;
    list->datatypeSize = datatypeSize;
    list->get = malloc(datatypeSize);
    return list->get != NULL;
}

void ArrayList_free(struct ArrayList* list) {
    list->count = 0;
    list->size = 0;
    list->datatypeSize = 0;
    free(list->get);
}

_Bool ArrayList_add(struct ArrayList* list, void *value) {
    if (list->count == list->size) {
        list->size *= 2;
        list->get = realloc(list->get, list->size * sizeof(list->datatypeSize));
        if (list->get == NULL) {
            return 0;
        }
    }

    memcpy((char *)list->get + list->count * list->datatypeSize, value, list->datatypeSize);

    list->count++;
    return 1;
}

void *ArrayList_get(struct ArrayList* list, unsigned int index) {
    if (index >= list->count) {
        return NULL;
    }
    return (char *)list->get + index * list->datatypeSize;
}
