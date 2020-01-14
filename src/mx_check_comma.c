#include "pathfinder.h"

int mx_check_comma(char **strarr, int i) {
    int get_char = 0;
    int count_comma = 0;

    for (int j = 0; strarr[i][j] && count_comma < 2; j++) {
        get_char = mx_get_char_index(&strarr[i][j], ',');
            if (get_char != -1) {
                count_comma += 1;
                j += get_char;
            }
            else 
                break;
    }
    return count_comma;
}
