#ifndef PATHFINDER_H
#define PATHFINDER_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <fcntl.h>
#include <malloc/malloc.h>

typedef const long INF;

typedef struct s_list {
    void *data;
    struct s_list *next;
} t_list;

typedef struct s_allpaths {
    int number;
    int count;
    int* path;
    int distance;
    struct s_allpaths *next;
} t_allpaths;

typedef struct s_main {
    char* str;
    char** strarr;
    int g;
    char** arr_islands;
    int** e_matrix;
} t_main;

typedef struct s_alg {
    int mindistance;
    int nextnode;
    int **pred;
    long INF;
    int **dex;
} t_alg;

typedef struct s_mtrx {
    int mx;
    int my;
} t_mtrx;

//-----pathfinder--------//

void mx_errors(int argc, char *argv[]);
void mx_printerr_line(int i);
char **mx_get_arr_islands(int G, char **strarr);
int **mx_get_matrix(int G, char *str, char **arr_islands);
char **mx_path_split(const char *s);
int **mx_create_isl_matrix(int **matrix, int g);
int **mx_alg_deijkstra(int **dex, int *distance, int g, int startnode);
t_allpaths *mx_get_allpaths(int **dex, int G);
void mx_printpaths(t_allpaths *paths, int **matrix, char **arr_islands);
void mx_empty_lines(char *str);
void mx_err_check(int count_comma, int count_space, int i);
int mx_check_minus(char **strarr, int i);
int mx_check_comma(char **strarr, int i);
void mx_swap_arr(int **a, int **b);
void mx_swap_int(int *a, int *b);
void mx_sort_fifo1(t_allpaths *paths);
void mx_sort_fifo2(t_allpaths *paths);
void mx_sort_fifo3(t_allpaths *paths);
void mx_sort_by_pathes(t_allpaths *paths, char **arr_islands);
//----- end pathfinder--------//

bool mx_isspace(char c);
bool mx_isdigit(int c);
bool mx_isalpha(int c);
bool mx_cmp(void *a, void *b);
int mx_count_words_isspace(const char *str, int *kwl);
int mx_strncmp(const char *s1, const char *s2, int n);
void mx_printerr(const char *s);
int mx_atoi(const char *str);
void mx_printlist(t_list *list);

int **mx_create_matrix(int G, int fillin);
void mx_del_arr_matrix_int(int ***arr);
void mx_del_matrix_int(int **str);
void mx_printarrint(int *arr, int G);

void mx_printchar(char c);
void mx_print_unicode(wchar_t c);
void mx_printstr(const char *s);
void mx_print_strarr(char **arr, const char *delim);
void mx_printint(int n);
double mx_pow(double n, unsigned int pow);
int mx_sqrt(int x);
char *mx_nbr_to_hex(unsigned long nbr);
unsigned long mx_hex_to_nbr(const char *hex);
char *mx_itoa(int number);
void mx_foreach(int *arr, int size, void (*f)(int));
int mx_binary_search(char **arr, int size, const char *s, int *count);
int mx_bubble_sort(char **arr, int size);
int mx_quicksort(char **arr, int left, int right);

int mx_strlen(const char *s);
void mx_swap_char(char *s1, char *s2);
void mx_str_reverse(char *s);
void mx_strdel(char **str);
void mx_del_strarr(char ***arr);
int mx_get_char_index(const char *str, char c);
char *mx_strdup(const char *s1);
char *mx_strndup(const char *s1, size_t n);
char *mx_strcpy(char *dst, const char *src);
char *mx_strncpy(char *dst, const char *src, int len);
int mx_strcmp(const char *s1, const char *s2);
char *mx_strcat(char *restrict s1, const char *restrict s2);
char *mx_strstr(const char *haystack, const char *needle);
int mx_get_substr_index(const char *str, const char *sub);
int mx_count_substr(const char *str, const char *sub);
int mx_count_words(const char *str, char c);
char *mx_strnew(const int size);
char *mx_strtrim(const char *str);
char *mx_del_extra_spaces(const char *str);
char **mx_strsplit(const char *s, char c);
char *mx_strjoin(const char *s1, const char *s2);
char *mx_file_to_str(const char *file);
int mx_read_line(char **lineptr, int buf_size, char delim, const int fd);
char *mx_replace_substr(const char *str, const char *sub, const char *replace);

void *mx_memset(void *b, int c, size_t len);
void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n);
void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n);
int mx_memcmp(const void *s1, const void *s2, size_t n);
void *mx_memchr(const void *s, int c, size_t n);
void *mx_memrchr(const void *s, int c, size_t n);
void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len);
void *mx_memmove(void *dst, const void *src, size_t len);
void *mx_realloc(void *ptr, size_t size);

t_list *mx_create_node(void *data);
void mx_push_front(t_list **list, void *data);
void mx_push_back(t_list **list, void *data);
void mx_pop_front(t_list **head);
void mx_pop_back(t_list **head);
int mx_list_size(t_list *list);
t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *));

#endif
