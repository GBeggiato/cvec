#include <stdio.h>

#include "cvec.h"

// some user-defined struct
typedef struct {
    double x, y;
} Point;

void Point_printf(Point* p){
    printf("(%lf, %lf)\n", p->x, p->y);
}

// create the methods here
// (TypeOfElement, NameOfContainer + Prefix)
CVEC_IMPL_DA(Point, Points)

int main(void) {
    // get a container
    Points points = Points_new();
    for (int i = 0; i < 50; ++i){
        // append
        Point p = (Point){.x = (double)i, .y = (double)i};
        Points_append(&points, p);
        // access single elements
        if (i < 5) {
            if (i & 1) printf("%d) x: %lf\n", i+1, CVEC_DA_AT(&points, i).x);
            else printf("%d) y: %lf\n", i+1, CVEC_DA_LAST(&points).y);
        }
        if (i == 14 || i == 33)
            printf("%d elements were added and capacity is: %zu\n", i + 1, points.capacity);
    }

    // don't forget to free
    Points_free(&points);
}

