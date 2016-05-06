#ifndef GENERIC_DARRAY_H
#define GENERIC_DARRAY_H

#include <stdlib.h>

#define darray_type_header(T)\
typedef struct {\
    T *data;\
    int len;\
    int cap;\
} Darray_##T;\
Darray_##T *new_darray_##T (int initial_count);\
int darray_expand_##T (Darray_##T *arr);\
int darray_set_##T (Darray_##T *arr, T data, int index);\
int darray_append_##T (Darray_##T *arr, T data);\
T darray_get_##T (Darray_##T *arr, int index);\
void free_darray_##T (Darray_##T *arr);


#define darray_type(T)\
Darray_##T *new_darray_##T (int initial_count) {\
    Darray_##T *arr = calloc (sizeof (Darray_##T), 1);\
    arr->len = 0;\
    arr->cap = initial_count;\
    arr->data = calloc (sizeof(T), initial_count*2);\
    if (arr->data != NULL) {\
        return arr;\
    }\
    return NULL;\
}\
\
int darray_expand_##T (Darray_##T *arr) {\
    void *temp = realloc (arr->data, arr->cap*2*sizeof(T));\
    if (temp != NULL) {\
        arr->data = temp;\
        return 0;\
    }\
    return -1;\
}\
\
int darray_set_##T (Darray_##T *arr, T data, int index) {\
    if (index > arr->cap) {\
        return -1;\
    }\
    arr->data[index] = data;\
    return 0;\
}\
\
int darray_append_##T (Darray_##T *arr, T data) {\
    if (arr->len >= arr->cap) {\
        if (darray_expand_##T (arr)) {\
            return -1;\
        }\
    }\
    if (darray_set_##T (arr, data, arr->len)) {\
        return -1;\
    }\
    arr->len++;\
    return 0;\
}\
\
T get_darray_##T (Darray_##T *arr, int index) {\
    return arr->data[index];\
}\
void free_darray_##T (Darray_##T *arr) {\
    free (arr->data);\
    free (arr);\
}

#endif
