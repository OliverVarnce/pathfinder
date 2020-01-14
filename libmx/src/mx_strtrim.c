#include "libmx.h"

char *mx_strtrim(const char *str) {
    char *newStr = 0;
    int startTr = 0;
    int endTr = 0;
    int i = 0;
    int len = mx_strlen(str);
    
    while(mx_isspace(str[i]) == 1) {
        i++;
        startTr++;
    }
    i = len - 1;
    while(mx_isspace(str[i]) == 1) {
        i--;
        endTr++;
    }
    newStr = (char*) malloc (sizeof(char) * len + 1 - startTr - endTr);
    newStr = mx_strncpy(newStr, &str[startTr], len - startTr - endTr);
    return newStr;
}
