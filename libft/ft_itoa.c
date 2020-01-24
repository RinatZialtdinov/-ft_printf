/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorrige <dmorrige@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:24:17 by kturnips          #+#    #+#             */
/*   Updated: 2020/01/24 17:17:40 by dmorrige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	memo(int n)
{
	size_t	i;

	i = 2;
	if (n < 0)
		++i;
	while (n / 10 != 0)
	{
		++i;
		n /= 10;
	}
	return (i);
}

static char	*add_digits(char *new, int i, unsigned int bn, int n)
{
	int	flag;

	flag = 1;
	while ((n / 10) != 0)
	{
		flag = flag * 10;
		n /= 10;
	}
	while (flag >= 1)
	{
		new[i++] = (bn / flag + '0');
		bn = bn - (bn / flag) * flag;
		flag = flag / 10;
	}
	new[i] = '\0';
	return (new);
}

char		*ft_itoa(int n)
{
	char			*new;
	size_t			i;
	unsigned int	bn;

	new = (char *)(malloc(sizeof(char) * memo(n)));
	if (new)
	{
		i = 0;
		bn = n;
		if (n < 0)
		{
			bn = -n;
			new[i++] = '-';
		}
		new = add_digits(new, i, bn, n);
		return (new);
	}
	return (NULL);
}
