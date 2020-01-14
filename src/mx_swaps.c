#include "pathfinder.h"

void mx_swap_arr(int **a, int **b) {
    int *tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

void mx_swap_int(int *a, int *b) {
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}
