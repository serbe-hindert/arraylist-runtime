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

_Bool ArrayList_init(struct ArrayList* list, const unsigned int initialSize, const size_t datatypeSize);
_Bool ArrayList_from(struct ArrayList* list, struct ArrayList* from);
void ArrayList_free(struct ArrayList* list);
_Bool ArrayList_add(struct ArrayList* list, void *value);
void *ArrayList_get(struct ArrayList* list, const unsigned int index);
_Bool ArrayList_delete(struct ArrayList* list, const unsigned int index);
_Bool ArrayList_fastDelete(struct ArrayList* list, const unsigned int index);
_Bool ArrayList_contains(struct ArrayList* list, void *value);

#endif //ARRAYLIST_LIBRARY_H
