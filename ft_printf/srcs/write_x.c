/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file7.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damerica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 18:32:21 by damerica          #+#    #+#             */
/*   Updated: 2020/01/23 18:32:22 by damerica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	write_right_16(int *size, char *numb, char **result, t_spec *el)
{
	int i;
	int len_int;

	len_int = ft_strlen(numb);
	i = 0;
	while ((*size) != i)
	{
		if (len_int != 0 && el->precision == -1)
		{
			if (el->nul == 1 && el->minus == 0
			&& (numb[len_int - 1] == 'x' || numb[len_int - 1] == 'X'))
			{
				(*result)[(*size) - 1] = '0';
				len_int--;
			}
			else
			{
				(*result)[(*size) - 1] = numb[len_int - 1];
				len_int--;
			}
		}
		else if (el->nul == 1 && el->precision <= 0)
			(*result)[(*size) - 1] = '0';
		(*size)--;
	}
}

void	where_num_16_1(t_spec *el, char **result, int k, int i)
{
	if (el->minus == 1)
	{
		while ((*result)[k] != ' ')
			k++;
		k--;
		while (k != -1)
		{
			(*result)[k + 2] = (*result)[k];
			k--;
		}
		(*result)[0] = '0';
		if (el->t == 'x' || el->t == 'p')
			(*result)[1] = 'x';
		else
			(*result)[1] = 'X';
	}
	else
	{
		(*result)[i - 2] = '0';
		if (el->t == 'x' || el->t == 'p')
			(*result)[i - 1] = 'x';
		else
			(*result)[i - 1] = 'X';
	}
}

void	where_num_16(t_spec *el, char **result, char *numb)
{
	int i;
	int k;

	k = 0;
	i = 0;
	while ((*result)[i] == ' ' && (*result)[i] != '\0')
		i++;
	if (((*result)[i] == '\0' || numb[0] == '0') && (el->t != 'p'))
		return ;
	if (i == 0 && el->minus == 0)
	{
		(*result)[0] = '0';
		if (el->t == 'x' || el->t == 'p')
			(*result)[1] = 'x';
		else
			(*result)[1] = 'X';
		return ;
	}
	where_num_16_1(el, result, k, i);
}

void	write_left_16(char **result, int *size, char *numb, t_spec *el)
{
	int	i;
	int	i1;
	int	len_num;

	len_num = ft_strlen(numb);
	i1 = 0;
	i = 0;
	while (i != (*size))
	{
		if (len_num != i1 && el->precision == -1)
		{
			(*result)[i] = numb[i1];
			i1++;
		}
		i++;
	}
}
