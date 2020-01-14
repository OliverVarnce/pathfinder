#include "pathfinder.h"

void mx_sort_fifo1(t_allpaths *paths) {

    for (t_allpaths *i = paths; i->next; i = i->next)
        for (t_allpaths *j = i->next; j; j = j->next)
                if (i->count < j->count && i->path[i->count - 1] == j->path[j->count - 1]
                    && i->path[0] == j->path[0]) { //сотируем по дине путей
                    mx_swap_int(&i->number, &j->number);
                    mx_swap_int(&i->count, &j->count);
                    mx_swap_int(&i->distance, &j->distance);
                    mx_swap_arr(&i->path, &j->path);
                }
}

void mx_sort_fifo2(t_allpaths *paths) {

    for (t_allpaths *i = paths; i->next; i = i->next)
        for (t_allpaths *j = i->next; j; j = j->next)
            if (i->path[i->count - 1] > j->path[j->count - 1]
               && i->path[0] == j->path[0]) { //сотируем по длине путей
                mx_swap_int(&i->number, &j->number);
                mx_swap_int(&i->count, &j->count);
                mx_swap_int(&i->distance, &j->distance);
                mx_swap_arr(&i->path, &j->path);
            }
}

void mx_sort_fifo3(t_allpaths *paths) {

    for (t_allpaths *i = paths; i->next; i = i->next)
        for (t_allpaths *j = i->next; j; j = j->next) {
            if (i->path[i->count - 1] == j->path[j->count - 1] && i->path[0] == j->path[0]){
                int k = 0;

                while (i->path[k] == j->path[k]) {
                    k++;
                }
                if (i->path[k] > j->path[k]) { //сортировка по точкам
                    mx_swap_int(&i->number, &j->number);
                    mx_swap_int(&i->count, &j->count);
                    mx_swap_int(&i->distance, &j->distance);
                    mx_swap_arr(&i->path, &j->path);
                }
            }
        }
}
