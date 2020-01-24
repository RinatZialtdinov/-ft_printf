/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damerica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 15:22:12 by damerica          #+#    #+#             */
/*   Updated: 2019/09/18 17:53:37 by damerica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	if (!(str))
		return ((size_t)NULL);
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
