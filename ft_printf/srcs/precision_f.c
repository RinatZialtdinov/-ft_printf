/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damerica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 18:43:34 by damerica          #+#    #+#             */
/*   Updated: 2020/01/23 18:43:35 by damerica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	write_right_prec_float(int *size, t_float *num, char **res, t_spec *el)
{
	int i;
	int len_float;
	int len_int;
	int copy_precision;

	copy_precision = el->precision;
	i = 2;
	len_float = ft_strlen(num->float_val_str);
	len_int = ft_strlen(num->int_val_str);
	if (num->plus_1 == 7)
		len_float--;
	while ((*size) != 0)
	{
		if (len_float != 0)
		{
			(*res)[(*size) - 1] = num->float_val_str[len_float - 1];
			len_float--;
		}
		else if (len_int != 0)
		{
			(*res)[(*size) - 1] = num->int_val_str[len_int - 1];
			len_int--;
		}
		(*size)--;
	}
}

void	write_left_prec_float(char **res, int *size, t_float *numb, t_spec *el)
{
	int i;
	int copy_precision;
	int i1;
	int i2;

	i2 = -1;
	i1 = -1;
	copy_precision = el->precision;
	i = 0;
	if (el->plus == 1 || el->negative == 1 || el->probel == 1)
	{
		i = 1;
	}
	while (i != (*size))
	{
		if (numb->int_val_str[++i1] != '\0')
			(*res)[i] = numb->int_val_str[i1];
		else if (numb->float_val_str[++i2] != '\0')
			(*res)[i] = numb->float_val_str[i2];
		i++;
	}
}

void	check_precision_float(char **res, int *size, t_spec *el, t_float *numb)
{
	if (el->minus == 1)
	{
		write_left_prec_float(res, size, numb, el);
	}
	else
	{
		write_right_prec_float(size, numb, res, el);
	}
}
