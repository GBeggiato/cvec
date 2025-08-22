#include <assert.h>
#include <stddef.h>
#include <stdlib.h>

#ifndef CVEC_H_
#define CVEC_H_


// implements the dynamic array, the "new", "append", "realloc", "free"
// functions for the provided type (elem_type) and assigns a struct name / prefix
// to all of them (struct_name)
#define CVEC_IMPL_DA(elem_type, struct_name) \
 \
typedef struct { \
    size_t capacity; \
    size_t length; \
    elem_type *values; \
} (struct_name); \
 \
struct_name struct_name##_new() { \
    const size_t CVEC_INITIAL_CAPACITY = 32; \
    return (struct_name){ \
        .capacity = CVEC_INITIAL_CAPACITY, \
        .length = 0, \
        .values = malloc(CVEC_INITIAL_CAPACITY * sizeof(elem_type)) \
    }; \
} \
 \
void struct_name##_realloc(struct_name *v) { \
    assert(v->capacity > 0); \
    size_t new_cap = v->capacity * 2; \
    v->values = realloc(v->values, new_cap * sizeof(elem_type)); \
    assert(v->values != NULL); \
    v->capacity = new_cap; \
} \
 \
void struct_name##_append(struct_name *v, elem_type n) { \
    if (v->capacity == v->length) struct_name##_realloc(v); \
    v->values[v->length++] = n; \
} \
 \
void struct_name##_free(struct_name *v) { \
    free(v->values); \
} \

// python index notation: negative numbers go back from the end of the array
#define CVEC_DA_AT(vec, i) (vec)->values[ \
    assert((vec)->length > 0), \
    (i) < 0 ? ((vec)->length+(i)) : (size_t)(i) \
] \

#define CVEC_DA_LAST(vec) CVEC_DA_AT(vec, -1)

#endif // CVEC_H_
