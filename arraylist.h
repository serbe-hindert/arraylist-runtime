#ifndef ARRAYLIST_LIBRARY_H
#define ARRAYLIST_LIBRARY_H

typedef struct ArrayList {
    unsigned int size;
    unsigned int count;
    unsigned int datatype;
    void* content;
} ArrayList;

_Bool ArrayList_create(ArrayList* restrict list, const unsigned int initialSize, const unsigned int datatypeSize);
_Bool ArrayList_from(ArrayList* restrict list, const ArrayList* restrict from);
void ArrayList_destroy(ArrayList* list);
_Bool ArrayList_add(ArrayList* restrict list, const void* restrict value);
_Bool ArrayList_set(ArrayList* restrict list, const unsigned int index, const void* restrict value);
void *ArrayList_get(const ArrayList* restrict list, const unsigned int index);
_Bool ArrayList_continuousDelete(ArrayList* restrict list, const unsigned int index);
_Bool ArrayList_fastDelete(ArrayList* restrict list, const unsigned int index);
_Bool ArrayList_contains(const ArrayList* restrict list, const void *value);

#endif //ARRAYLIST_LIBRARY_H
