#include "pathfinder.h"

void mx_printerr_line(int i) {
    mx_printerr("error: line ");
    mx_printerr(mx_itoa(i + 1));
    mx_printerr(" is not valid\n");
    exit(1);
}
