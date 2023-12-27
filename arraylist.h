#ifndef ARRAYLIST_LIBRARY_H
#define ARRAYLIST_LIBRARY_H

struct ArrayList {
    unsigned int size;
    unsigned int count;
    unsigned int datatypeSize;
    void* content;
};

_Bool ArrayList_init(struct ArrayList* restrict list, const unsigned int initialSize, const unsigned int datatypeSize);
_Bool ArrayList_from(struct ArrayList* list, const struct ArrayList* restrict from);
void ArrayList_free(struct ArrayList* list);
_Bool ArrayList_add(struct ArrayList* list, const void *value);
void *ArrayList_get(const struct ArrayList* restrict list, const unsigned int index);
_Bool ArrayList_continuousDelete(struct ArrayList* list, const unsigned int index);
_Bool ArrayList_fastDelete(struct ArrayList* list, const unsigned int index);
_Bool ArrayList_contains(const struct ArrayList* list, const void *value);

#endif //ARRAYLIST_LIBRARY_H
