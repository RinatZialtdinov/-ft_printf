/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damerica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 17:20:17 by damerica          #+#    #+#             */
/*   Updated: 2020/01/23 19:07:33 by damerica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	ft_create_str(t_spec *el, va_list ap)
{
	if (el->t == 'd' || el->t == 'i' || el->t == 'u')
		write_int_el(el, ap);
	else if (el->t == 'o')
	{
		convert_numb_8(el, ap);
	}
	else if (el->t == 'x' || el->t == 'X')
		convert_numb(el, ap);
	else if (el->t == 'c')
	{
		;
	}
	else if (el->t == 's')
		write_str_el(el, ap);
	else if (el->t == 'p')
	{
		write_point_el(el, ap);
	}
	else if (el->t == 'f')
		convert_float(el, ap);
}

void	parametres(t_spec **el)
{
	(*el) = (t_spec *)malloc(sizeof(t_spec));
	(*el)->minus = 0;
	(*el)->plus = 0;
	(*el)->spc = 0;
	(*el)->nul = 0;
	(*el)->field = 0;
	(*el)->pre = -1;
	(*el)->left = 0;
	(*el)->negative = 0;
	(*el)->it_nul = 0;
	(*el)->lat = 0;
	(*el)->len = 0;
	(*el)->m = ft_strnew(3);
}

int		check_two_percent(const char *format, t_spec *el, int start, int end)
{
	while (start <= end)
	{
		if (format[start] == '%')
		{
			write_two_percent(el);
			return (1);
		}
		start++;
	}
	if (!(el->t))
	{
		return (1);
	}
	return (0);
}

int		ft_create_el(const char *format, int start, int end, va_list ap)
{
	t_spec	*el;
	int		i;
	int		size;
	int		result;

	size = 1;
	parametres(&el);
	i = start;
	while (start <= end)
	{
		ft_create_el_1(format, &start, &el);
		ft_create_el_3(format, &start, &el, ap);
		ft_create_el_2(format, &start, &el, ap);
		ft_create_el_4(format, &start, &el);
		el->t = format[end];
		start++;
	}
	if (check_two_percent(format, el, i, end))
	{
		ft_create_el_5(&result, &el);
		return (result);
	}
	ft_create_str(el, ap);
	ft_create_el_5(&result, &el);
	return (result);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		k;
	int		z;
	int		count;

	count = 0;
	z = -1;
	i = 0;
	k = 0;
	va_start(ap, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			z = i;
			i++;
			while (format[i] != 'c' && format[i] != 's' && format[i] != 'p'
			&& format[i] != 'd' && format[i] != 'i' && format[i] != 'o' &&
			format[i] != 'u' && format[i] != 'x' && format[i] != 'X'
			&& format[i] != 'f' && format[i] != '%'
			&& format[i + 1] != '\0')
			{
				i++;
			}
			k = k + ft_create_el(format, z + 1, i, ap);
			count++;
		}
		else
		{
			ft_putchar(format[i]);
		}
		i++;
		k++;
	}
	va_end(ap);
	if (count == 0)
		return (k);
	return (k - count);
}

// int main()
// {
// 	//#define DBL_MIN    2.2250738585072014E-308
// 	//static char *s_hidden = "hi low\0don't print me lol\0";
// 	//unsigned long k = -42;
// 	ft_printf("@moulitest: %#.o %#.0o|\n", 0, 0);
// 	printf("@moulitest: %#.o %#.0o|\n", 0, 0);
// 	//printf(" <-i  -  %i\n", ft_printf("%f|\n", 12.2));
// 	//printf(" <-i  -  %i\n", printf("%f|\n", 12.2));
//  return (0);
// }
