#include "arraylist.h"

_Bool ArrayList_init(struct ArrayList* list, const unsigned int initialSize, const size_t datatypeSize) {
    list->count = 0;
    list->size = initialSize;
    list->datatypeSize = datatypeSize;
    list->get = malloc(datatypeSize);
    return list->get != NULL;
}

_Bool ArrayList_from(struct ArrayList* list, struct ArrayList* from) {
    memcpy(list, from, sizeof(struct ArrayList));
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

void *ArrayList_get(struct ArrayList* list, const unsigned int index) {
    if (index >= list->count) {
        return NULL;
    }
    return (char *)list->get + index * list->datatypeSize;
}

_Bool ArrayList_delete(struct ArrayList* list, const unsigned int index) {
    if (index >= list->count) {
        return 0;
    }

    for (int i = index; i < list->count - 1; i++) {
        memcpy((char *)list->get + i * list->datatypeSize, (char *)list->get + (i + 1) * list->datatypeSize, list->datatypeSize);
    }

    list->count--;

    return 1;
}

_Bool ArrayList_fastDelete(struct ArrayList* list, const unsigned int index) {
    if (index >= list->count) {
        return 0;
    }

    memcpy((char *)list->get + index * list->datatypeSize, (char*)list->get + (list->count - 1) * list->datatypeSize, list->datatypeSize);
    list->count--;

    return 1;
}

_Bool ArrayList_contains(struct ArrayList* list, void *value) {
    for (int i = 0; i < list->count; i++) {
        if (memcmp((char *)list->get + i * list->datatypeSize, value, list->datatypeSize) == 0) {
            return 1;
        }
    }
    return 0;
}