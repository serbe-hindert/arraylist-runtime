#ifndef ARRAYLIST_LIBRARY_H
#define ARRAYLIST_LIBRARY_H

#include <stdlib.h>
#include <string.h>

struct ArrayList {
    unsigned int size;
    unsigned int count;
    size_t datatypeSize;
    void* get;
};

_Bool ArrayList_init(struct ArrayList* list, unsigned int initialSize, size_t datatypeSize);
void ArrayList_free(struct ArrayList* list);
_Bool ArrayList_add(struct ArrayList* list, void *value);
void *ArrayList_get(struct ArrayList* list, unsigned int index);

#endif //ARRAYLIST_LIBRARY_H
