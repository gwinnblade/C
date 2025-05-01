#include <stdio.h>
#include "operation.h"

int main() {

    printf("Sum: %.2f\n", main_sum(4, 2, 4, 6, 8));
    printf("Max: %.2f\n", main_max(4, 2, 4, 6, 8));
    printf("Min: %.2f\n", main_min(4, 2, 4, 6, 8));
    printf("Avg: %.2f\n", main_avg(4, 2, 4, 6, 8));

    return 0;
}

