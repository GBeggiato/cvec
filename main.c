
#include "cvec.h"

CV_IMPL_DA(int, Ints)

int main(void) {
    Ints ints = Ints_new();
    for (size_t i = 0; i < 6; ++i){
        Ints_append(&ints, i * 8);
        printf("%d\n", ints.values[i]);
    }
}
