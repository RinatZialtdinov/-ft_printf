/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damerica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 18:32:08 by damerica          #+#    #+#             */
/*   Updated: 2020/01/25 18:32:10 by damerica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	write_right_8(int *size, char *numb, char **result, t_spec *el)
{
	int i;
	int len_int;

	len_int = ft_strlen(numb);
	i = 0;
	while ((*size) != i)
	{
		if (len_int != 0 && el->pre == -1)
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
		else if (el->it_nul == 1 && el->pre == 0 && el->lat == 1)
		{
			(*result)[(*size) - 1] = '0';
			el->it_nul = 0;
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
	copy_pre_16 = el->pre;
	i = -1;
	if (el->lat == 1 && el->lat + (int)ft_strlen(numb) >= el->pre)
	{
		i++;
	}
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

void	write_8_el_1(t_spec *el, char *numb, char **result, int *size)
{
	if (el->minus == 1)
		el->left = 1;
	if (el->pre > 0)
		check_pre_8(result, size, el, numb);
	else
	{
		if (el->left == 1)
			write_left_8(result, size, numb, el);
		else
			write_right_8(size, numb, result, el);
	}
}

void	check_size_8(t_spec **el, int *size, char **numb)
{
	*size = 0;
	if ((*el)->pre > (int)ft_strlen(*numb) - 1)
		(*size) = (*size) + (*el)->pre;
	else if ((*el)->pre != 0 && numb != 0)
		(*size) = (*size) + (int)ft_strlen(*numb);
	if ((*el)->field > (*size))
		(*size) = (*el)->field;
	if ((*el)->lat == 1 && (int)ft_strlen(*numb) + 1 >
	(*el)->pre && *numb[0] != '0' && (*el)->field == 0)
		(*size) = *size + 1;
	if ((*el)->lat == 1 && (*el)->field == 0 && (*el)->field >
	(*el)->pre && (*el)->field < (int)ft_strlen(*numb))
		(*size) = (int)ft_strlen(*numb) + 1;
	if ((*numb)[0] == '0' && (*el)->pre <= 0 &&
	(*el)->lat == 1 && (*el)->field == 0)
		*size = 1;
	else if ((*el)->lat == 1 && (*el)->field == (int)ft_strlen(*numb))
		*size = *size + 1;
	else if ((*el)->lat == 1 && (*el)->field <
	(int)ft_strlen(*numb) && (*el)->pre <= (int)ft_strlen(*numb) + 1)
		*size = (int)ft_strlen(*numb) + 1;
}

void	write_8_el(t_spec *el, char *numb)
{
	int		size;
	char	*result;
	int		i;

	i = 0;
	check_size_8(&el, &size, &numb);
	result = (char *)malloc(sizeof(char) * (size + 1));
	result[size] = '\0';
	while (i != size)
	{
		result[i] = ' ';
		i++;
	}
	write_8_el_1(el, numb, &result, &size);
	//printf("%s\n", result);
	if (el->nul == 1 && el->pre <= 0)
		write_nul_or_spc(&result, '0', el);
	else
		write_nul_or_spc(&result, ' ', el);
	if (el->lat == 1)
		where_num_8(el, &result, numb);
	el->len = ft_strlen(result);
	ft_putstr(result);
	free(result);
}

void	convert_numb_8_1(long long copy_numb, char *new_numb, int k)
{
	int mod;

	while (copy_numb > 0)
	{
		mod = copy_numb % 8;
		new_numb[k - 1] = mod + 48;
		copy_numb = copy_numb / 8;
		k--;
	}
}

int		value_k_8(long long numb)
{
	int k;

	k = 0;
	while (numb > 0)
	{
		numb = numb / 8;
		k++;
	}
	return (k);
}

void	convert_numb_8(t_spec *el, va_list ap)
{
	long long	numb;
	long long	copy_numb;
	char		*new_numb;
	int			k;

	va_arg_t(el, ap, &numb);
	copy_numb = numb;
	k = value_k_8(numb);
	if (copy_numb == 0)
	{
		el->it_nul = 1;
		new_numb = "0\0";
		write_8_el(el, new_numb);
		return ;
	}
	else
	{
		new_numb = (char *)malloc(sizeof(char) * (k + 1));
		new_numb[k] = '\0';
	}
	convert_numb_8_1(copy_numb, new_numb, k);
	write_8_el(el, new_numb);
	free(new_numb);
}
