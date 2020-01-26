/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damerica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 14:18:21 by damerica          #+#    #+#             */
/*   Updated: 2020/01/26 14:18:24 by damerica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	write_right_8(int *size, char *numb, char **result, t_spec *el)
{
	int len_int;

	len_int = ft_strlen(numb);
	//printf("sad|%s|\n", numb);
	while ((*size) != 0)
	{
		//printf("|%s|\n", *result);
		if ((len_int != 0 && el->pre <= 0 && el->it_nul != 1) || (el->it_nul == 1 && el->pre == -1))
		{
			if (el->nul == 1 && el->minus == 0 && (numb[len_int - 1] == 'x'))
			{
				(*result)[(*size) - 1] = '0';
				len_int--;
			}
			else
			{
				(*result)[(*size) - 1] = numb[len_int - 1];
				len_int--;
				if (el->it_nul == 1)
					return;
			}
		}
		else if (el->it_nul == 1 && el->pre == 0 && el->lat == 1)
		{
			(*result)[(*size) - 1] = '0';
			if (el->it_nul == 1)
					return;
		}
		(*size)--;
	}
}

void	where_num_8_1(t_spec *el, char **result, int k, int i)
{
	if (el->minus == 1)
	{
		while ((*result)[k] != ' ' && (*result)[k] != '\0')
			k++;
		k--;
		while (k != -1 && k != el->pre - 1)
		{
			(*result)[k + 2] = (*result)[k];
			k--;
		}
		(*result)[0] = '0';
	}
	else
	{
		if ((*result)[(int)ft_strlen(*result) - el->pre] == '0')
			;
		else
			(*result)[i - 1] = '0';
	}
}

void	where_num_8(t_spec *el, char **result, char *numb)
{
	int i;
	int k;

	k = 0;
	i = 0;
	while ((*result)[i] == ' ' && (*result)[i] != '\0')
		i++;
	if (((*result)[i] == '\0' || numb[0] == '0'))
		return ;
	if (i == 0 && el->minus == 0)
	{
		(*result)[0] = '0';
		return ;
	}
	where_num_8_1(el, result, k, i);
}

void	write_left_8(char **result, int *size, char *numb, t_spec *el)
{
	int	i;
	int	i1;
	int	len_num;

	len_num = ft_strlen(numb);
	i1 = 0;
	i = 0;
	if (el->lat == 1 && el->it_nul == 0)
		i++;
	while (i != (*size))
	{
		if ((el->it_nul == 1 && el->pre != 0) ||
		(el->it_nul == 1 && el->lat == 1))
		{
			(*result)[i] = '0';
			return ;
		}
		if (len_num != i1 && el->pre == -1)
		{
			(*result)[i] = numb[i1];
			i1++;
		}
		i++;
	}
}
