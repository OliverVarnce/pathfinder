#include "libmx.h"

int mx_count_substr(const char *str, const char *sub) {
    int count = 0;
    int s = mx_strlen(sub);
    int len = mx_strlen(str)/s;
    
    if (!str || !sub)
        return -1;
    for (int i = 0; i < len; i++) {
        if (mx_strstr(str, sub)) {
            count++;
            str = mx_strstr(str, sub) + s;
        }
    }
    return count;
}
