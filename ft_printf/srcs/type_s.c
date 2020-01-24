/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file10.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damerica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 18:39:39 by damerica          #+#    #+#             */
/*   Updated: 2020/01/23 18:39:40 by damerica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	write_right_prec_str(int *size, char *str, char **result, t_spec *el)
{
	int copy_precision_str;
	int len_num;
	int len;

	if (str == NULL)
		str = "(null)";
	len_num = ft_strlen(str);
	copy_precision_str = el->precision;
	len = len_num;
	while ((*size) != 0)
	{
		if (len_num != 0 && copy_precision_str != 0
		&& (int)ft_strlen(str) < el->precision)
		{
			(*result)[(*size) - 1] = str[len - 1];
			copy_precision_str--;
			len_num--;
			len--;
		}
		else if (len_num != 0 && copy_precision_str != 0
		&& (int)ft_strlen(str) >= el->precision)
		{
			(*result)[(*size) - 1] = str[copy_precision_str - 1];
			copy_precision_str--;
			len_num--;
		}
		(*size)--;
	}
}

void	write_left_prec_str(char **result, int *size, char *str, t_spec *el)
{
	int i;
	int copy_precision_str;
	int len_str;
	int i1;

	if (str == NULL)
		str = "(null)";
	i1 = 0;
	len_str = ft_strlen(str);
	copy_precision_str = el->precision;
	i = 0;
	while (i != (*size))
	{
		if (copy_precision_str != 0 && len_str != 0)
		{
			(*result)[i] = str[i];
			copy_precision_str--;
			len_str--;
		}
		i++;
	}
}

void	check_precision_str(char **result, int *size, t_spec *el, char *str)
{
	if (el->minus == 1)
	{
		write_left_prec_str(result, size, str, el);
	}
	else
	{
		write_right_prec_str(size, str, result, el);
	}
}

void	check_size_str(t_spec **el, int *size, char **str)
{
	if (*str == NULL)
	{
		if ((*el)->precision >= 6)
			*size = 6;
		else if ((*el)->field > 0 && (*el)->precision != -1)
			*size = (*el)->field;
		else if ((*el)->precision > 0)
			*size = (*el)->precision;
		else
			*size = 6;
	}
	else
		*size = ft_strlen(*str);
	if ((*el)->field > (*size) || (*el)->precision == 0)
		(*size) = (*el)->field;
	else if ((*el)->precision > 0 && (*el)->field != 0
	&& (*el)->precision < (*el)->field)
		(*size) = (*el)->field;
	else if ((*el)->precision > 0 && (*el)->precision < (int)ft_strlen(*str))
		(*size) = (*el)->precision;
	else if ((*el)->precision == 0 && (*el)->field == 0)
		(*size) = 0;
}
