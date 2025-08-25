#include <assert.h>
#include <stddef.h>
#include <stdlib.h>

#ifndef CVEC_H_
#define CVEC_H_

#define CVEC_INITIAL_CAPACITY 32

#define CVEC_STRUCT(elem_type, struct_name) \
typedef struct { \
    size_t capacity; \
    size_t length; \
    elem_type *values; \
} (struct_name); \

#define CVEC_REALLOC(v) { \
    size_t new_cap = (v)->capacity == 0 ? 32 : (v)->capacity * 2; \
    (v)->values = realloc((v)->values, new_cap * sizeof(*(v)->values)); \
    assert((v)->values != NULL); \
    (v)->capacity = new_cap; \
} \

#define CVEC_APPEND(v, n) \
if ((v)->capacity == (v)->length) CVEC_REALLOC((v)); \
(v)->values[(v)->length++] = (n); \

#define CVEC_FREE(v) free((v)->values);

#define CVEC_NEW(elem_type, struct_name) \
struct_name struct_name##_new() { \
    return (struct_name){ \
        .capacity = CVEC_INITIAL_CAPACITY, \
        .length = 0, \
        .values = malloc(CVEC_INITIAL_CAPACITY * sizeof(elem_type)) \
    }; \
} \

#define CVEC_IMPL_DA_APPEND(elem_type, struct_name) \
void struct_name##_append(struct_name *v, elem_type n) { CVEC_APPEND(v, n)} \

#define CVEC_IMPL_DA(elem_type, struct_name) \
CVEC_STRUCT(elem_type, struct_name) \
CVEC_NEW(elem_type, struct_name) \
CVEC_IMPL_DA_APPEND(elem_type, struct_name)

// python index notation: negative numbers go back from the end of the array
#define CVEC_DA_AT(vec, i) (vec)->values[ \
    assert((vec)->length > 0), \
    (i) < 0 ? ((vec)->length+(i)) : (size_t)(i) \
] \

#define CVEC_DA_LAST(vec) CVEC_DA_AT(vec, -1)

#endif // CVEC_H_
