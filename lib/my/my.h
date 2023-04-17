/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** header file that contains the prototypes of all the function in libmy.a
*/

#ifndef MY_H_
    #define MY_H_

void my_putchar(char c);
int my_putstr(char *str);
int my_isneg(int n);
char *my_revstr(char *str);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strcpy(char *dest, char const *src);
int my_compute_power_rec(int nb, int p);
int my_compute_square_root(int nb);
int my_find_prime_sup(int nb);
int my_getnbr(char const *str);
int my_is_prime(int nb);
int my_put_nbr(int nb);
int my_showmem(char const *str, int size);
int my_showstr(char const *str);
void my_sort_int_array(int *array, int size);
char *my_strcapitalize(char *str);
int my_strcmp(char const *s1, char const *s2);
int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int my_str_isnum(char const *str);
int my_str_isprintable(char const *str);
int my_str_isupper(char const *str);
int my_strlen(char const *str);
char *my_strlowcase(char *str);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strstr(char *str, char const *to_find);
char *my_strupcase(char *str);
void my_swap(int *a, int *b);
int print_the_nbr(int number);
char *my_strdup(char const *src);
char *my_memset(char *str, int i, char fill);
int convert_base(int number, int base);
int my_revnbr(int nbr, int is_zero_to_add_base_2);
int my_arraylen(void *array);
void my_putcharerror(char c);
int my_putstrerror(char *str);

#endif
