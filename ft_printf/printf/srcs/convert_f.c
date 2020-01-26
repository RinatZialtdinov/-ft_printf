/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file11.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damerica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 18:41:17 by damerica          #+#    #+#             */
/*   Updated: 2020/01/23 18:41:18 by damerica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	conver_float_in_str_2(t_float **numb, int i, t_spec *el)
{
	int mod;

	mod = (*numb)->float_value * 10;
	mod = mod % 10;
	if (el->pre == 10 && ft_strcmp(el->m, "L") == 0 && (*numb)->int_value == 0)
		mod++;
	if (mod >= 5)
	{
		while (1)
		{
			if ((*numb)->float_val_str[i] == '.')
			{
				(*numb)->plus_1 = 1;
				break ;
			}
			if ((*numb)->float_val_str[i] < '9')
			{
				(*numb)->float_val_str[i]++;
				break ;
			}
			else
				(*numb)->float_val_str[i] = '0';
			i--;
		}
	}
}

void	conver_float_in_str_1(t_spec *el, t_float **numb, int *copy_pre)
{
	int z;

	z = 0;
	if (el->pre == -1)
	{
		(*numb)->float_val_str = (char *)malloc(sizeof(char) * 7);
		(*numb)->float_val_str[7] = '\0';
		while (z != 7)
		{
			(*numb)->float_val_str[z] = ' ';
			z++;
		}
		*copy_pre = 6;
	}
	else if (el->pre > 0)
	{
		(*numb)->float_val_str = (char *)malloc(sizeof(char) * (el->pre));
		(*numb)->float_val_str[el->pre] = '\0';
		while (z != el->pre)
		{
			(*numb)->float_val_str[z] = ' ';
			z++;
		}
	}
}

void	conver_float_in_str_3(t_spec *el, t_float **numb, int *copy_pre)
{
	int mod;
	int i;

	i = 1;
	while (*copy_pre != 0 && el->pre != 0)
	{
		mod = (*numb)->float_value * 10;
		mod = mod % 10;
		(*numb)->float_val_str[i] = mod + 48;
		i++;
		(*numb)->float_value = (*numb)->float_value * 10 - mod;
		(*copy_pre)--;
		if (*copy_pre == 0)
			conver_float_in_str_2(numb, i - 1, el);
	}
	if (el->pre == 0)
	{
		mod = (*numb)->float_value * 10;
		if (mod >= 5)
			(*numb)->plus_1 = 1;
	}
}

void	conver_float_in_str(t_spec *el, t_float **numb)
{
	int			copy_pre;
	long long	mod;
	int			i;
	int			z;

	z = 0;
	i = 1;
	copy_pre = el->pre;
	conver_float_in_str_1(el, numb, &copy_pre);
	if (el->pre != 0)
		(*numb)->float_val_str[0] = '.';
	conver_float_in_str_3(el, numb, &copy_pre);
	mod = ft_strlen((*numb)->float_val_str);
	(*numb)->int_val_str = ft_itoa((*numb)->int_value + (*numb)->plus_1, el);
	if ((size_t)mod != ft_strlen((*numb)->float_val_str))
		(*numb)->plus_1 = 7;
}

void	convert_float(t_spec *el, va_list ap)
{
	t_float		*numb;
	long double	num;

	numb = (t_float *)malloc(sizeof(t_float));
	va_arg_t_for_float(&num, ap, el);
	numb->plus_1 = 0;
	numb->int_value = num / 1;
	numb->float_value = num - numb->int_value;
	if (numb->int_value < 0 || numb->float_value < 0)
	{
		numb->float_value = -1 * numb->float_value;
		numb->int_value = -1 * numb->int_value;
		el->negative = 1;
	}
	conver_float_in_str(el, &numb);
	write_float_el(el, numb);
	if (el->pre != 0)
		free(numb->float_val_str);
	free(numb->int_val_str);
	free(numb);
}
