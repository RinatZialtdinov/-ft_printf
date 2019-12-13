/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damerica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 17:41:56 by damerica          #+#    #+#             */
/*   Updated: 2019/12/12 20:30:45 by damerica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>

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
}               t_spec;

void	ft_putchar(char c);
int	ft_intlen(int n);
void	ft_putstr(char const *s);
int	ft_strcmp(const char *s1, const char *s2);
size_t	ft_strlen(const char *str);