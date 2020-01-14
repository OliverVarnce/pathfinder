#include "pathfinder.h"

void mx_empty_lines(char *str) {
    int k = 0;

    for (int i = 0; i < mx_strlen(str) - 1; i++) {
        if (str[i] == '\n') {
            k++;
            if (str[i] == str[i + 1]) {
                mx_printerr_line(k);
                exit(1);
            }
        }
    }
    // if (str[mx_strlen(str) - 1] == '\n') {
    //     mx_printerr_line(k);
    //     exit(1);
    // }
}
