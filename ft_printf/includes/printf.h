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
    char *modif;
    char conv_type;
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
char	*ft_itoa(long long n, t_spec *elem);
int	ft_intlen(long long n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *str, int ch);
char	*ft_strnew(size_t size);