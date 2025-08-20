
#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define CV_INITIAL_CAP 32

#define TYPE int
#define TYPE_NAME Vec

// --------------------------------------------------------------------
//
#define CV_CONCAT(a, b) a##b

typedef struct {
    size_t capacity;
    size_t length;
    TYPE *values;
} TYPE_NAME;

#define CV_NEW_DA(type, name) \
typedef struct { \
    size_t capacity; \
    size_t length; \
    type *values; \
} (name) ; \
\
(name) CV_CONCAT(name, _new) (size_t item_size) { \
    return (name){ \
        .capacity = CV_INITIAL_CAP, \
        .length = 0, \
        .values = malloc(CV_INITIAL_CAP * items_size) \
    }; \
} \

CV_NEW_DA(double, Nums)

// TYPE_NAME vec_new(size_t items_size) {
//     return (TYPE_NAME){
//         .capacity = CV_INITIAL_CAP,
//         .length = 0,
//         .values = malloc(CV_INITIAL_CAP * items_size)
//     };
// }
//
// void vec_realloc(TYPE_NAME *v) {
//     size_t new_cap = v->capacity * 2;
//     v->values = realloc(v->values, new_cap * sizeof(*v->values));
//     assert(v->values != NULL);
//     v->capacity = new_cap;
// }
//
// void vec_append(TYPE_NAME *v, TYPE n) {
//     if (v->capacity == v->length) {
//         vec_realloc(v);
//     }
//     v->values[v->length++] = n;
// }

// #define VEC_NEW_OF(x) vec_new(sizeof(x))
// Vec v = VEC_NEW_OF(TYPE);

// --------------------------------------------------------------------

int main(void) {
    // Vec v = vec_new(sizeof(TYPE));
    //
    // for (size_t i = 0; i < 6; ++i){
    //     vec_append(&v, i);
    //     printf("%4d, (%zu, %zu)\n", v.values[i], v.length, v.capacity);
    // }

    int CV_CONCAT(name, _new) = 4;
    printf("%d\n", name_new);



    printf("\nend\n");
}
