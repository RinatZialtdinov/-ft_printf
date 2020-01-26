/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damerica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 14:15:49 by damerica          #+#    #+#             */
/*   Updated: 2020/01/26 14:15:50 by damerica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

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
