#include "libmx.h" 

static int  count_words(char const *s, char c) {
    int  count;

    count = 0;
    while (*s) {
        while (*s && (*s == c))
            s++;
        if (*s && (*s != c)) {
            count++;
            while (*s && (*s != c))
                s++;
        }
    }
    return (count);
}

static char  *full_word(char const *s, char c) {
    char *str;
    int  count;

    count = 0;
    while (s[count] && (s[count] != c))
        count++;
    str = (char*)malloc(sizeof(char) * count + 1);
    if (!str)
        return (NULL);
    count = 0;
    while (s[count] && (s[count] != c)) {
        str[count] = s[count];
        count++;
    }
    str[count] = '\0';
    return (str);
}

char   **mx_strsplit(char const *s, char c) {
    char **str;
    int  countwords;
    int  i;

    if (!s)
        return (NULL);
    i = 0;
    countwords = count_words(s, c);
    str = (char **)malloc(sizeof(char*) * (countwords + 1));
    if (!str)
        return (NULL);
    while (*s) {
        while (*s && (*s == c))
            s++;
        if (*s && (*s != c))
            str[i++] = full_word(s, c);
        while (*s && (*s != c))
            s++;
    }
    str[i] = NULL;
    return (str);
}
