/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file12.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damerica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 18:42:52 by damerica          #+#    #+#             */
/*   Updated: 2020/01/23 18:42:54 by damerica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	write_left_float_cont(int *len_int, int *i, int *len_f, t_float *numb)
{
	*len_f = 0;
	if (numb->float_val_str)
		*len_f = ft_strlen(numb->float_val_str);
	*len_int = ft_strlen(numb->int_val_str);
	*i = 0;
}

void	write_left_float(char **result, int *size, t_float *numb, t_spec *el)
{
	int len_float;
	int len_int;
	int i;
	int i1;
	int i2;

	write_left_float_cont(&len_int, &i, &len_float, numb);
	i2 = -1;
	i1 = -1;
	if (el->plus == 1 || el->negative == 1 || el->spc == 1)
		i = 1;
	while (i != (*size))
	{
		if (len_int != i1 + 1)
			(*result)[i] = numb->int_val_str[++i1];
		else if (len_float != i2 + 1)
			(*result)[i] = numb->float_val_str[++i2];
		else if (el->lat == 1 && el->pre == 0)
		{
			(*result)[i] = '.';
			el->lat = 0;
		}
		i++;
	}
}

void	write_right_float(int *size, t_float *numb, char **result, t_spec *el)
{
	int i;
	int len_float;
	int len_int;

	len_float = 0;
	if (el->pre != 0)
		len_float = ft_strlen(numb->float_val_str);
	len_int = ft_strlen(numb->int_val_str);
	i = 0;
	if (el->lat == 1 && el->pre == 0)
	{
		(*result)[(*size) - 1] = '.';
		(*size)--;
	}
	while ((*size) != 0)
	{
		if (len_float != 0)
			(*result)[(*size) - 1] = numb->float_val_str[--len_float];
		else if (len_int != 0)
			(*result)[(*size) - 1] = numb->int_val_str[--len_int];
		(*size)--;
	}
}

void	write_float_el(t_spec *el, t_float *numb)
{
	char	*result;
	int		size;
	int		z;

	z = -1;
	check_size_and_negative_float(&el, &size, &numb);
	result = (char *)malloc(sizeof(char) * (size + 1));
	while (z + 1 != size)
		result[++z] = ' ';
	if (el->pre > 0)
		check_pre_float(&result, &size, el, numb);
	else
	{
		if (el->minus == 1)
			write_left_float(&result, &size, numb, el);
		else
			write_right_float(&size, numb, &result, el);
	}
	if (el->nul == 1)
		write_nul_or_spc(&result, '0', el);
	if ((el->negative == 1 || el->plus == 1) || (el->spc == 1 && el->pre == 0))
		where_num(&result, el);
	el->len = ft_strlen(result);
	ft_putstr(result);
	free(result);
}
