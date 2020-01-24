/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file9.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damerica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 18:37:29 by damerica          #+#    #+#             */
/*   Updated: 2020/01/23 18:37:30 by damerica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	write_right_str(int *size, char *str, char **result, t_spec *el)
{
	int i;
	int len_int;

	if (str == NULL)
	{
		if (el->field != 0 && el->precision != -1)
			str = "\0";
		else
			str = "(null)";
	}
	len_int = ft_strlen(str);
	i = 0;
	while ((*size) != i)
	{
		if (len_int > 0 && el->precision != 0)
		{
			(*result)[(*size) - 1] = str[len_int - 1];
			len_int--;
		}
		(*size)--;
	}
}

void	write_left_str(char **result, int *size, char *str, t_spec *el)
{
	int i;
	int i1;
	int len_num;

	if (str == NULL)
	{
		if (el->field != 0 && el->precision != -1)
			str = "\0";
		else
			str = "(null)";
	}
	len_num = ft_strlen(str);
	i1 = 0;
	i = 0;
	while (i != (*size))
	{
		if (len_num != i1 && el->precision != 0)
		{
			(*result)[i] = str[i1];
			i1++;
		}
		i++;
	}
}

void	write_str_el(t_spec *el, va_list ap)
{
	char	*result;
	char	*str;
	int		size;
	int		i;

	i = 0;
	str = va_arg(ap, char *);
	check_size_str(&el, &size, &str);
	result = (char *)malloc(sizeof(char) * (size + 1));
	result[size] = '\0';
	while (i != size)
	{
		result[i] = ' ';
		i++;
	}
	if (el->precision > 0)
		check_precision_str(&result, &size, el, str);
	else
	{
		if (el->minus == 1)
			write_left_str(&result, &size, str, el);
		else
			write_right_str(&size, str, &result, el);
	}
	el->len = ft_strlen(result);
	ft_putstr(result);
}
