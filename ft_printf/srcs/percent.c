/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damerica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 18:19:55 by damerica          #+#    #+#             */
/*   Updated: 2020/01/23 18:19:58 by damerica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	write_nul_or_spc_percent(char **result, char set)
{
	int i;

	i = 0;
	while ((*result)[i] != '\0')
	{
		if ((*result)[i] != '%')
			(*result)[i] = set;
		i++;
	}
}

void	write_right_percent(int *size, char **result)
{
	int i;
	int len;

	len = 1;
	i = 0;
	while ((*size) != i)
	{
		if (len != 0)
		{
			(*result)[(*size) - 1] = '%';
			len--;
		}
		(*size)--;
	}
}

void	write_left_percent(char **result, int *size)
{
	int len;
	int i;

	i = 0;
	len = 1;
	while (i != (*size))
	{
		if (len != 0)
		{
			(*result)[i] = '%';
			len--;
		}
		i++;
	}
}

void	check_size_percent(t_spec **el, int *size)
{
	*size = 1;
	if ((*el)->field != 0)
	{
		(*size) = (*el)->field;
	}
}

void	write_two_percent(t_spec *el)
{
	int		size;
	char	*result;
	int		i;

	i = -1;
	check_size_percent(&el, &size);
	result = (char *)malloc(sizeof(char) * (size + 1));
	result[size] = '\0';
	while (++i != size)
		result[i] = ' ';
	if (el->minus == 1)
		el->left = 1;
	if (el->left == 1)
		write_left_percent(&result, &size);
	else
		write_right_percent(&size, &result);
	if (el->nul == 1 && el->pre <= 0 && el->minus == 0)
		write_nul_or_spc_percent(&result, '0');
	el->len = ft_strlen(result);
	ft_putstr(result);
	free(result);
}
