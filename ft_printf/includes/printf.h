/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damerica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 17:41:56 by damerica          #+#    #+#             */
/*   Updated: 2019/12/15 17:05:39 by damerica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//# include "libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct  s_spec
{
    int left;
    int minus;
    int plus;
    int probel;
    int nul;
    int field;
    int precision;
    char *m;
    char t;
    int negative;
    int len;
    int it_nul;
    int lat;
}               t_spec;

typedef struct s_float
{
    long long int_value;
    long double float_value;
    char *int_val_str;
    int plus_1;
    char *float_val_str;
}               t_float;

void	ft_putchar(char c);
void	ft_putstr(char const *s);
int	ft_strcmp(const char *s1, const char *s2);
size_t	ft_strlen(const char *str);
char	*ft_itoa(long long n, t_spec *el);
int	ft_intlen(long long n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *str, int ch);
char	*ft_strnew(size_t size);
void va_arg_t(t_spec *el, va_list ap, long long *numb);
void check_size_and_negative_float1(t_spec **el, int *size, t_float **numb);
void check_size_and_negative_float(t_spec **el, int *size, t_float **numb);
void write_right_prec_float(int *size, t_float *numb, char **result, t_spec *el);
void write_left_prec_float(char **result, int *size, t_float *numb, t_spec *el);
void check_precision_float(char **result, int *size, t_spec *el, t_float *numb);
void write_left_float_cont(int *len_int, int *i, int *len_float, t_float *numb);
void write_left_float(char **result, int *size, t_float *numb, t_spec *el);
void write_right_float(int *size, t_float *numb, char **result, t_spec *el);
void write_float_el(t_spec *el, t_float *numb);
void conver_float_in_str_2(t_float **numb, int i);
void conver_float_in_str_1(t_spec *el, t_float **numb, int *copy_precision);
void conver_float_in_str_3(t_spec *el, t_float **numb, int *copy_precision);
void conver_float_in_str(t_spec *el, t_float **numb);
void va_arg_t_for_float(long double *num, va_list ap, t_spec *el);
void convert_float(t_spec *el, va_list ap);
void check_size_str(t_spec **el, int *size, char **str);
void write_right_prec_str(int *size, char *str, char **result, t_spec *el);
void write_left_prec_str(char **result, int *size, char *str, t_spec *el);
void check_precision_str(char **result, int *size, t_spec *el, char *str);
void write_right_str(int *size, char *str, char **result, t_spec *el);
void write_left_str(char **result, int *size, char *str, t_spec *el);
void write_str_el(t_spec *el, va_list ap);
void write_nul_or_probel(char **result, char set, t_spec *el);
void write_letter_A(int mod, char **new_numb, int k);
void write_letter_a(int mod, char **new_numb, int k);
void check_size_16(t_spec **el, int *size, char **numb);
void write_right_prec_16(int *size, char *numb, char **result, t_spec *el);
void write_left_prec_16(char **result, int *size, char *numb, t_spec *el);
void check_precision_16(char **result, int *size, t_spec *el, char *numb);
void write_right_16(int *size, char *numb, char **result, t_spec *el);
void where_num_16_1(t_spec *el, char **result, int k, int i);
void where_num_16(t_spec *el, char **result, char *numb);
void write_left_16(char **result, int *size, char *numb, t_spec *el);
void write_16_el_1(t_spec *el, char *numb, char **result, int *size);
void write_16_el(t_spec *el, char *numb);
void convert_numb_1(t_spec *el, long long copy_numb, char *new_numb, int k);
void convert_numb(t_spec *el, va_list ap);
void write_point_el_1(long long copy_numb, char *new_numb, int k);
void write_point_el(t_spec *el, va_list ap);
void write_right(int *size, char *numb, char **result, t_spec *el);
int write_left(char **result, int *size, char *numb, t_spec *el);
void write_right_prec(int *size, char *numb, char **result, t_spec *el);
void write_left_prec_1(char **result, char *numb, int i, int *i1);
void write_left_prec(char **result, int *size, char *numb, t_spec *el);
void check_precision(char **result, int *size, t_spec *el, char *numb);
void where_num(char **result, t_spec *el);
void check_size_and_negative_int(t_spec **el, int *size, long long *numb);
void write_nul_or_probel(char **result, char set, t_spec *el);
void write_int_el_1(t_spec *el, char **result, int size, char *str_numb);
void write_int_el(t_spec *el, va_list ap);
void ft_create_str(t_spec *el, va_list ap);
void parametres(t_spec **el);
void write_nul_or_probel_percent(char **result, char set);
void write_right_percent(int *size, char **result);
void write_left_percent(char **result, int *size);
void check_size_percent(t_spec **el, int *size);
void write_two_percent(t_spec *el);
int check_two_percent(const char *format, t_spec *el, int start, int end);
void ft_create_el_4(const char *format, int *start, t_spec **el);
void ft_create_el_3(const char *format, int *start, t_spec **el, va_list ap);
void ft_create_el_2(const char *format, int *start, t_spec **el, va_list ap);
void ft_create_el_1(const char *format, int *start, t_spec **el);
void ft_create_el_5(int *result, t_spec **el);
int ft_create_el(const char *format, int start, int end, va_list ap);
int ft_printf(const char *format, ...);