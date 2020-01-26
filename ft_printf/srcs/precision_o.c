/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damerica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 14:17:09 by damerica          #+#    #+#             */
/*   Updated: 2020/01/26 14:17:11 by damerica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	write_right_prec_8(int *size, char *numb, char **result, t_spec *el)
{
	int copy_pre_16;
	int len_num;

	len_num = ft_strlen(numb);
	copy_pre_16 = el->pre;
	while ((*size) != 0)
	{
		if (len_num != 0)
		{
			(*result)[(*size) - 1] = numb[len_num - 1];
			copy_pre_16--;
			len_num--;
		}
		else if (copy_pre_16 > 0)
		{
			(*result)[(*size) - 1] = '0';
			copy_pre_16--;
		}
		(*size)--;
	}
}

void	write_left_prec_8(char **result, int *size, char *numb, t_spec *el)
{
	int i;
	int copy_pre_16;
	int len_num;
	int i1;

	i1 = 0;
	len_num = ft_strlen(numb);
	copy_pre_16 = el->pre + 1;
	i = -1;
	if (el->lat == 1 && el->lat + (int)ft_strlen(numb) >= el->pre)
		i++;
	while (++i != (*size))
	{
		if (--copy_pre_16 > len_num)
			(*result)[i] = '0';
		else
		{
			if (i1 != len_num)
			{
				(*result)[i] = numb[i1];
				i1++;
			}
		}
	}
}

void	check_pre_8(char **result, int *size, t_spec *el, char *numb)
{
	if (el->left == 1)
	{
		write_left_prec_8(result, size, numb, el);
	}
	else
	{
		write_right_prec_8(size, numb, result, el);
	}
}
