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
	int copy_pre_str;
	int len_num;
	int len;

	if (str == NULL)
		str = "(null)";
	len_num = ft_strlen(str);
	copy_pre_str = el->pre;
	len = len_num;
	while ((*size) != 0)
	{
		if (len_num != 0 && copy_pre_str != 0
		&& (int)ft_strlen(str) < el->pre)
		{
			(*result)[(*size) - 1] = str[len - 1];
			copy_pre_str--;
			len_num--;
			len--;
		}
		else if (len_num != 0 && copy_pre_str != 0
		&& (int)ft_strlen(str) >= el->pre)
		{
			(*result)[(*size) - 1] = str[copy_pre_str - 1];
			copy_pre_str--;
			len_num--;
		}
		(*size)--;
	}
}

void	write_left_prec_str(char **result, int *size, char *str, t_spec *el)
{
	int i;
	int copy_pre_str;
	int len_str;
	int i1;

	if (str == NULL)
		str = "(null)";
	i1 = 0;
	len_str = ft_strlen(str);
	copy_pre_str = el->pre;
	i = 0;
	while (i != (*size))
	{
		if (copy_pre_str != 0 && len_str != 0)
		{
			(*result)[i] = str[i];
			copy_pre_str--;
			len_str--;
		}
		i++;
	}
}

void	check_pre_str(char **result, int *size, t_spec *el, char *str)
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
		if ((*el)->pre >= 6)
			*size = 6;
		else if ((*el)->field > 0 && (*el)->pre != -1)
			*size = (*el)->field;
		else if ((*el)->pre > 0)
			*size = (*el)->pre;
		else
			*size = 6;
	}
	else
		*size = ft_strlen(*str);
	if ((*el)->field > (*size) || (*el)->pre == 0)
		(*size) = (*el)->field;
	else if ((*el)->pre > 0 && (*el)->field != 0
	&& (*el)->pre < (*el)->field)
		(*size) = (*el)->field;
	else if ((*el)->pre > 0 && (*el)->pre < (int)ft_strlen(*str))
		(*size) = (*el)->pre;
	else if ((*el)->pre == 0 && (*el)->field == 0)
		(*size) = 0;
}
