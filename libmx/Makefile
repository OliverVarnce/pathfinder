
NAME	=	libmx.a

CFLG	=	-std=c11 -Wall -Wextra -Werror -Wpedantic -g
COMP 	= 	clang

SRCD	=	src
INCD	=	inc
OBJD	=	obj

INC		=	libmx.h
INCS	=	$(addprefix $(INCD)/, $(INC))

SRC		= 	mx_atoi.o mx_binary_search.o mx_bubble_sort.o mx_count_substr.o mx_count_words.o mx_create_dex_matrix.o \
            mx_create_matrix.o mx_create_node.o mx_del_arr_matrix_int.o mx_del_extra_spaces.o mx_del_matrix_int.o \
            mx_del_strarr.o mx_file_to_str.o mx_foreach.o mx_get_char_index.o mx_get_substr_index.o mx_hex_to_nbr.o \
            mx_isalpha.o mx_isdigit.o mx_isspace.o mx_itoa.o mx_list_size.o mx_memccpy.o mx_memchr.o mx_memcmp.o \
            mx_memcpy.o mx_memmem.o mx_memmove.o mx_memrchr.o mx_memset.o mx_nbr_to_hex.o mx_pop_back.o mx_pop_front.o \
            mx_pow.o mx_print_strarr.o mx_print_unicode.o mx_printchar.o mx_printerr.o mx_printint.o mx_printstr.o \
            mx_push_back.o mx_push_front.o mx_quicksort.o mx_read_line.o mx_realloc.o mx_replace_substr.o mx_sort_list.o \
            mx_sqrt.o mx_str_reverse.o mx_strcat.o mx_strcmp.o mx_strcpy.o mx_strdel.o mx_strdup.o mx_strjoin.o mx_strlen.o \
            mx_strncpy.o mx_strndup.o mx_strnew.o mx_strsplit.o mx_strstr.o mx_strtrim.o mx_swap_char.o


SRCS	=	$(addprefix $(SRCD)/, $(SRC))
OBJS	=	$(addprefix $(OBJD)/, $(SRC:%.c=%.o))

all: install

install: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $@ $^

$(OBJD)/%.o: $(SRCD)/%.c $(INCS)
	@$(COMP) $(CFLG) -c $< -o $@ -I$(INCD)

$(OBJS): | $(OBJD)

$(OBJD):
	@mkdir -p $@

clean:
	@rm -rf $(OBJD)

uninstall: clean
	@rm -rf $(NAME)

reinstall: uninstall install

start:
	clang -std=c11 -Wall -Wextra -Werror -Wpedantic main.c libmx.a && ./a.out