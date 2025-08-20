
# CVEC

**basic** <generic> dynamic array in C

### NOTE
- it works but it's just an experiment
- surely there are blind corners that are waiting to bite back

## example

```c

#include <stdio.h>

#include "cvec.h"

// some user-defined struct
typedef struct {
    double x, y;
} Point;

// this creates the methods
// (TypeOfElement, NameOfContainer + Prefix)
CVEC_IMPL_DA(Point, Points)

int main(void) {
    // get a container
    Points points = Points_new();
    for (size_t i = 0; i < 50; ++i){
        // append
        Points_append(&points, (Point){.x = (double)i, .y = (double)i});
        // access single elements
        if (i < 5) {
            if (i & 1) printf("%zu) x: %lf\n", i+1, points.values[i].x);
            else printf("%zu) y: %lf\n", i+1, points.values[i].y);
        }
        if (i == 14 || i == 33)
          printf("%zu elements were added and capacity is: %zu\n", i + 1,
                 points.capacity);
    }
    // don't forget to free
    Points_free(&points);
}
```
