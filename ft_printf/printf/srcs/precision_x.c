/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file8.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damerica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 18:34:40 by damerica          #+#    #+#             */
/*   Updated: 2020/01/23 18:34:42 by damerica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	write_right_prec_16(int *size, char *numb, char **result, t_spec *el)
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

void	write_left_prec_16(char **result, int *size, char *numb, t_spec *el)
{
	int i;
	int copy_pre_16;
	int len_num;
	int i1;

	i1 = 0;
	len_num = ft_strlen(numb);
	copy_pre_16 = el->pre;
	i = -1;
	while (++i != (*size))
	{
		if (copy_pre_16 > len_num)
		{
			copy_pre_16--;
			(*result)[i] = '0';
		}
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

void	check_pre_16(char **result, int *size, t_spec *el, char *numb)
{
	if (el->left == 1)
	{
		write_left_prec_16(result, size, numb, el);
	}
	else
	{
		write_right_prec_16(size, numb, result, el);
	}
}
