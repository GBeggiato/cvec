
#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>


#define CV_INITIAL_CAP 32

#define CV_STRUCT(type, struct_name) \
typedef struct { \
    size_t capacity; \
    size_t length; \
    type *values; \
} (struct_name) ; \

#define CV_NEW(type, struct_name) \
struct_name struct_name##_new() { \
    return (struct_name){ \
        .capacity = CV_INITIAL_CAP, \
        .length = 0, \
        .values = malloc(CV_INITIAL_CAP * sizeof(type)) \
    }; \
} \

#define CV_REALLOC(struct_name) \
void struct_name##_realloc(struct_name *v) { \
    size_t new_cap = v->capacity == 0 ? CV_INITIAL_CAP : v->capacity * 2; \
    v->values = realloc(v->values, new_cap * sizeof(*v->values)); \
    assert(v->values != NULL); \
    v->capacity = new_cap; \
} \

#define CV_APPEND(type, struct_name) \
void struct_name##_append(struct_name *v, type n) { \
    if (v->capacity == v->length) struct_name##_realloc(v); \
    v->values[v->length++] = n; \
} \


#define CV_IMPL_DA(elem_type, struct_name) \
CV_STRUCT(elem_type, struct_name) \
CV_NEW(elem_type, struct_name) \
CV_REALLOC(struct_name) \
CV_APPEND(elem_type, struct_name) \


CV_IMPL_DA(int, Ints)


int main(void) {

    Ints ints = Ints_new();
    Ints_append(&ints, 10);
    Ints_append(&ints, 20);
    Ints_append(&ints, 30);
    Ints_append(&ints, 40);


    for (size_t i = 0; i < ints.length; ++i){
        printf("%d\n", ints.values[i]);
    }

    printf("\nend\n");
}

