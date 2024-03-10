#include "arraylist-runtime.h"

#include <stdlib.h>
#include <string.h>

bool RArrayList_create(RArrayList* restrict list, const unsigned int initialSize, const unsigned int datatypeSize) {
    list = malloc(sizeof(RArrayList));
    if (list == NULL) {
        return false;
    }
    list->count = 0;
    list->size = initialSize;
    list->datatype = datatypeSize;
    list->content = malloc(initialSize * datatypeSize);
    if (list->content == NULL) {
        free(list);
        return false;
    }
    return true;
}

bool RArrayList_from(RArrayList* restrict list, const RArrayList* restrict from) {
    list = malloc(sizeof(RArrayList));
    memcpy(list, from, sizeof(RArrayList));
    return list->content != NULL;
}

void RArrayList_destroy(RArrayList* list) {
    list->count = 0;
    list->size = 0;
    list->datatype = 0;
    free(list->content);
    free(list);
}

bool RArrayList_add(RArrayList* restrict list, const void* restrict value) {
    if (list->count == list->size) {
        list->size *= 2;
        list->content = realloc(list->content, list->size * sizeof(list->datatype));
        if (list->content == NULL) {
            return false;
        }
    }

    memcpy((char *)list->content + list->count * list->datatype, value, list->datatype);

    list->count++;
    return true;
}

bool RArrayList_set(RArrayList* restrict list, const unsigned int index, const void* restrict value) {
    if (index >= list->count) {
        return false;
    }
    memcpy(list->content + index * list->datatype, value, list->datatype);
    return true;
}

void* RArrayList_get(const RArrayList* restrict list, const unsigned int index) {
    if (index >= list->count) {
        return NULL;
    }
    return (char *)list->content + index * list->datatype;
}

bool RArrayList_continuousDelete(RArrayList* restrict list, const unsigned int index) {
    if (index >= list->count) {
        return false;
    }

    memmove(list->content + index * list->datatype, list->content + (index + 1) * list->datatype, list->datatype);
    list->count--;
    return true;
}

bool RArrayList_fastDelete(RArrayList* restrict list, const unsigned int index) {
    if (index >= list->count) {
        return false;
    }

    memcpy((char *)list->content + index * list->datatype, (char*)list->content + (list->count - 1) * list->datatype, list->datatype);
    list->count--;

    return true;
}

bool RArrayList_contains(const RArrayList* restrict list, const void *value) {
    for (int i = 0; i < list->count; i++) {
        if (memcmp((char *)list->content + i * list->datatype, value, list->datatype) == 0) {
            return true;
        }
    }
    return false;
}