#include "libmx.h"

int mx_atoi(const char *str) {
    int i = 0;
    int sum = 0;
    int sign = 1;

    while (mx_isspace(str[i]) == true) {
        i++;
    }
    if (str[i] == '-' && mx_isdigit(str[i + 1])) {
        sign = -1;
        i++;
    }
    if (str[i] == '+' && mx_isdigit(str[i + 1]))
        i++;
    while (mx_isdigit(str[i]) == true) {
        sum = sum * 10 + (str[i] - '0');
        i++;
    }
    return sum * sign;
}
