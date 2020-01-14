#include "pathfinder.h"

int mx_check_minus(char **strarr, int i) {
    int get_char = 0;
    int count_space = 0;

    for (int j = 0; strarr[i][j] && count_space < 2; j++) {
            get_char = mx_get_char_index(&strarr[i][j], '-');
            if (get_char != -1) {
                count_space += 1;
                j += get_char;
                
            }
            else 
                break;
    }
    return count_space;
}
