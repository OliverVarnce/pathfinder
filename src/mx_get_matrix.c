#include "pathfinder.h"

static t_mtrx return_x_y(int g, char **tmp, char **arr_islands);

int **mx_get_matrix(int g, char *str, char **arr_islands) {
    int **matrix = mx_create_matrix(g, 0);
    char **strarr = mx_strsplit(str, '\n');
    t_mtrx mtrx;

    for (int i = 0; strarr[i]; i++) {
       char **tmp = mx_path_split(strarr[i]);

        mtrx = return_x_y(g,tmp,arr_islands);
        matrix[mtrx.mx][mtrx.my] = mx_atoi(tmp[2]);
        matrix[mtrx.my][mtrx.mx] = mx_atoi(tmp[2]);
        mx_del_strarr(&tmp);
    }
    mx_del_strarr(&strarr);
    return matrix;
}

static t_mtrx return_x_y(int g, char **tmp, char **arr_islands){
    t_mtrx mtrx;
    int mx = 0;
    int my = 0;

    for (int j = 0; j < g; j++) {
        if (mx_strcmp(arr_islands[j], tmp[0]) == 0)
            mx = j;
        if (mx_strcmp(arr_islands[j], tmp[1]) == 0)
            my = j;
    }
    mtrx.mx = mx;
    mtrx.my = my;
    return mtrx;
}
