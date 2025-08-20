#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define CV_INITIAL_CAP 32

#define CV_IMPL_DA(elem_type, struct_name) \
\
typedef struct { \
    size_t capacity; \
    size_t length; \
    elem_type *values; \
} (struct_name) ; \
\
struct_name struct_name##_new() { \
    return (struct_name){ \
        .capacity = CV_INITIAL_CAP, \
        .length = 0, \
        .values = malloc(CV_INITIAL_CAP * sizeof(elem_type)) \
    }; \
} \
\
void struct_name##_realloc(struct_name *v) { \
    size_t new_cap = v->capacity == 0 ? CV_INITIAL_CAP : v->capacity * 2; \
    v->values = realloc(v->values, new_cap * sizeof(*v->values)); \
    assert(v->values != NULL); \
    v->capacity = new_cap; \
} \
\
void struct_name##_append(struct_name *v, elem_type n) { \
    if (v->capacity == v->length) struct_name##_realloc(v); \
    v->values[v->length++] = n; \
} \

CV_IMPL_DA(int, Ints)

int main(void) {
    Ints ints = Ints_new();
    for (size_t i = 0; i < 6; ++i){
        Ints_append(&ints, i * 8);
        printf("%d\n", ints.values[i]);
    }
}

