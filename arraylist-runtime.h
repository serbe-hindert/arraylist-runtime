#ifndef ArrayList_LIBRARY_H
#define ArrayList_LIBRARY_H

typedef struct RArrayList {
    unsigned int size;
    unsigned int count;
    unsigned int datatype;
    void* content;
} RArrayList;

_Bool RArrayList_create(RArrayList* restrict list, const unsigned int initialSize, const unsigned int datatypeSize);
_Bool RArrayList_from(RArrayList* restrict list, const RArrayList* restrict from);
void RArrayList_destroy(RArrayList* list);
_Bool RArrayList_add(RArrayList* restrict list, const void* restrict value);
_Bool RArrayList_set(RArrayList* restrict list, const unsigned int index, const void* restrict value);
void* RArrayList_get(const RArrayList* restrict list, const unsigned int index);
_Bool RArrayList_continuousDelete(RArrayList* restrict list, const unsigned int index);
_Bool RArrayList_fastDelete(RArrayList* restrict list, const unsigned int index);
_Bool RArrayList_contains(const RArrayList* restrict list, const void *value);

#endif //ArrayList_LIBRARY_H
