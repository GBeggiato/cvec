#include <stdio.h>

#include "cvec.h"

// you can just create the struct
CVEC_STRUCT(int, Nums)

// or get the "new" and "append" functions implemented as well
CVEC_IMPL_DA(float, Reals)

int main(void) {

    // in this case you have to 0-initialize and use the macros
    Nums nums = {0};
    CVEC_APPEND(&nums, 2);
    CVEC_APPEND(&nums, 4);
    CVEC_APPEND(&nums, 3);
    for (int i = 0; i < 3; ++i) printf("%d) %d\n", i, CVEC_DA_AT(&nums, i));
    CVEC_FREE(&nums);

    // you can use the specifi functions in the second case
    Reals reals = Reals_new();
    for (int i = 1; i < 4; ++i) {
        Reals_append(&reals, 1.1 * i);
        printf("%d) %f\n", i, CVEC_DA_LAST(&reals));
    }
    // free is a macro anyway, as you should use it only once
    CVEC_FREE(&reals);

}

