#include "pathfinder.h"

int main(int argc, char *argv[]) {
    int **matrix = 0;
    t_main *main = malloc(sizeof(t_main));
    t_allpaths *paths;

    mx_errors(argc, argv);
    main->str = mx_file_to_str(argv[1]);
    main->strarr = mx_strsplit(main->str, '\n');
    main->g = mx_atoi(main->str);
    main->arr_islands = mx_get_arr_islands(main->g, main->strarr);
    main->e_matrix = mx_get_matrix(main->g, main->str, main->arr_islands);
    matrix = mx_create_isl_matrix(main->e_matrix, main->g);
    paths = mx_get_allpaths(matrix, main->g);
    mx_printpaths(paths, matrix, main->arr_islands);
    return 0;
}



