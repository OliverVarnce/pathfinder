#include "pathfinder.h"

static void print_ends();
static void print_path(t_allpaths *paths, char **arr_islands);
static void print_route(t_allpaths *paths, char **arr_islands);
static void print_distance(t_allpaths *paths, int **matrix);

void mx_printpaths(t_allpaths *paths, int **matrix, char **arr_islands) {
    mx_sort_fifo2(paths);
    mx_sort_fifo1(paths);
    mx_sort_fifo3(paths);
    t_allpaths *z = paths;

    if (paths != NULL) {
        for (; z != NULL; z = z->next) {
            print_ends();
            print_path(z, arr_islands);
            print_route(z, arr_islands);
            print_distance(z, matrix);
            print_ends();
        }
    }
    else {
        mx_printstr("paths == 0 (NULL)\n");
    }
}

static void print_ends() {
    for (int k = 0; k < 40; k++)
        mx_printchar('=');
    mx_printchar('\n');
}

static void print_path(t_allpaths *paths, char **arr_islands) {
    mx_printstr("Path: ");
    mx_printstr(arr_islands[paths->path[0]]);
    mx_printstr(" -> ");
    mx_printstr(arr_islands[paths->path[paths->count - 1]]);
    mx_printchar('\n');
}

static void print_route(t_allpaths *paths, char **arr_islands) {
    mx_printstr("Route: ");
    for (int i = 0; i < paths->count; i++) {
        mx_printstr(arr_islands[paths->path[i]]);
        if (i == paths->count - 1)
            break;
        mx_printstr(" -> ");
    }
    mx_printchar('\n');
}

static void print_distance(t_allpaths *paths, int **matrix) {
    int j = 1;
    mx_printstr("Distance: ");
    if (paths->count > 2) {
        while (j < paths->count) {
            mx_printint(matrix[paths->path[j - 1]][paths->path[j]]);
            if (j == paths->count - 1) break;
            mx_printstr(" + ");
            j++;
        }
        mx_printstr(" = ");
    }
    mx_printint(paths->distance);
    mx_printchar('\n');
}
