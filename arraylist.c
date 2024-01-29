#include "arraylist.h"

#include <stdlib.h>
#include <string.h>

_Bool ArrayList_create(ArrayList* restrict list, const unsigned int initialSize, const unsigned int datatypeSize) {
    list = malloc(sizeof(ArrayList));
    if (list == NULL) {
        return 0;
    }
    list->count = 0;
    list->size = initialSize;
    list->datatype = datatypeSize;
    list->content = malloc(initialSize * datatypeSize);
    if (list->content == NULL) {
        free(list);
        return 0;
    }
    return 1;
}

_Bool ArrayList_from(ArrayList* restrict list, const ArrayList* restrict from) {
    list = malloc(sizeof(ArrayList));
    memcpy(list, from, sizeof(ArrayList));
    return list->content != NULL;
}

void ArrayList_destroy(ArrayList* list) {
    list->count = 0;
    list->size = 0;
    list->datatype = 0;
    free(list->content);
    free(list);
}

_Bool ArrayList_add(ArrayList* restrict list, const void* restrict value) {
    if (list->count == list->size) {
        list->size *= 2;
        list->content = realloc(list->content, list->size * sizeof(list->datatype));
        if (list->content == NULL) {
            return 0;
        }
    }

    memcpy((char *)list->content + list->count * list->datatype, value, list->datatype);

    list->count++;
    return 1;
}

_Bool ArrayList_set(ArrayList* restrict list, const unsigned int index, const void* restrict value) {
    if (index >= list->count) {
        return 0;
    }
    memcpy(list->content + index * list->datatype, value, list->datatype);
    return 1;
}

void *ArrayList_get(const ArrayList* restrict list, const unsigned int index) {
    if (index >= list->count) {
        return NULL;
    }
    return (char *)list->content + index * list->datatype;
}

_Bool ArrayList_continuousDelete(ArrayList* restrict list, const unsigned int index) {
    if (index >= list->count) {
        return 0;
    }

    memmove(list->content + index * list->datatype, list->content + (index + 1) * list->datatype, list->datatype);
    list->count--;
    return 1;
}

_Bool ArrayList_fastDelete(ArrayList* restrict list, const unsigned int index) {
    if (index >= list->count) {
        return 0;
    }

    memcpy((char *)list->content + index * list->datatype, (char*)list->content + (list->count - 1) * list->datatype, list->datatype);
    list->count--;

    return 1;
}

_Bool ArrayList_contains(const ArrayList* restrict list, const void *value) {
    for (int i = 0; i < list->count; i++) {
        if (memcmp((char *)list->content + i * list->datatype, value, list->datatype) == 0) {
            return 1;
        }
    }
    return 0;
}