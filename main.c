#include <stdio.h>

#include "cvec.h"

CVEC_IMPL_DA(float, Reals)

int main(void) {
    Reals reals = Reals_new();
    for (int i = 1; i < 4; ++i) {
        Reals_append(&reals, 1.1 * i);
        printf("%d) %f\n", i, CVEC_DA_LAST(&reals));
    }
    CVEC_FREE(&reals);
}
