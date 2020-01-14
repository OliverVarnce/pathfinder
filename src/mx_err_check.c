#include "pathfinder.h"

void mx_err_check(int count_comma, int count_space, int i) {
    if (count_comma != 1 || count_space != 1) {
            mx_printerr_line(i);
            exit(1);
    }
}
