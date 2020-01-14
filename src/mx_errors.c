#include "pathfinder.h"

static void INVLD_LINE_ASCII(char **strarr);
static void INVLD_LINE_INPUT(char **strarr);
static void INVLD_LINE1_DIGIT(char *strarr);
static void INVLD_FILE(char *argv[]);

void mx_errors(int argc, char *argv[]) {
    if (argc != 2) {
        mx_printerr("usage: ./pathfinder [filename]\n");
        exit(1);
    }
    INVLD_FILE(argv);
    char *str = mx_file_to_str(argv[1]);
    mx_empty_lines(str);
    char **strarr = mx_strsplit(str, '\n');
    INVLD_LINE1_DIGIT(strarr[0]);
    INVLD_LINE_INPUT(strarr);
    INVLD_LINE_ASCII(strarr);

    mx_strdel(&str); // clean all leaks
    mx_del_strarr(&strarr);
}

static void INVLD_FILE(char *argv[]) {
    int file = open(argv[1], O_RDONLY);
    if (file < 0) {
        mx_printerr("error: file ");
        mx_printerr(argv[1]);
        mx_printerr(" does not exist\n");
        exit(1);
    }
    char buf[1];
    int n = read(file, buf, sizeof(buf));
    if (n <= 0) {
        mx_printerr("error: file ");
        mx_printerr(argv[1]);
        mx_printerr(" is empty\n");
        exit(1);
    }
    if (buf[0] == '\n') {
        mx_printerr_line(0);
        exit(1);
    }
    close(file);
}

static void INVLD_LINE1_DIGIT(char *strarr) {
    for (int i = 1; i < mx_strlen(strarr); i++) {
        if (!mx_isdigit(strarr[i])) {
            mx_printerr("error: line 1 is not valid\n");
            exit(1);
        }
    }
}

static void INVLD_LINE_INPUT(char **strarr) {
        int count_space;
        int count_comma;

    for (int i = 1; strarr[i]; i++) {
        count_space = mx_check_minus(strarr, i);
        count_comma = mx_check_comma(strarr, i);
        mx_err_check(count_comma, count_space, i);
    }
}

static void INVLD_LINE_ASCII(char **strarr) {
    char **tmp = NULL;
    for (int i = 1; strarr[i]; i++) {
        tmp = mx_path_split(strarr[i]);
        if (tmp[0][0] == '\0' || tmp[1][0] == '\0' || tmp[2][0] == '\0')
            mx_printerr_line(i);
        for (int j = 0; j < mx_strlen(tmp[0]); j++) {
            if (!mx_isalpha(tmp[0][j]))
                mx_printerr_line(i);
        }
        for (int j = 0; j < mx_strlen(tmp[1]); j++) {
            if (!mx_isalpha(tmp[1][j]))
                mx_printerr_line(i);
        }
        for (int j = 0; j < mx_strlen(tmp[2]); j++) {
            if (!mx_isdigit(tmp[2][j]))
                mx_printerr_line(i);
        }
        mx_del_strarr(&tmp);
    }
}
