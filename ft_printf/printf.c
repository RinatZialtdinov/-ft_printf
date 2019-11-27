/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damerica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 17:20:17 by damerica          #+#    #+#             */
/*   Updated: 2019/11/27 17:20:24 by damerica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void create(const char *format, int start, int end, va_list ap)
{
    t_spec *elem;
    int i;
    int size;
    char *str;

    size = 1;
    elem = (t_spec *)malloc(sizeof(t_spec));
    elem->flag = (char *)malloc(sizeof(char) * size);
    elem->flag[0] = '\0';
    elem->field = 0;
    elem->precision = 0;
    i = 0;
    while (start <= end)
    {
        /*while (format[start] == '+' || format[start] == '-' || format[start] == ' ')
        {
            if (ft_strchr(elem->flag, format[start]) == NULL)
            {
                if (ft_strlen(elem->flag) == 0)
                    elem->flag = ft_strjoin(elem->flag, format[start]);
                else
                {   
                    free(elem->flag);
                }
                
                size++;
            }
            start++;
        }*/
        // ^^^ Не закончил данную часть ^^^
        if (format[start] == '#')
        {
            elem->conv_type = (char)malloc(sizeof(char) * 1);
            elem->conv_type = format[start + 1];
            break;
        }
        while (format[start] >= '0' && format[start] <= '9')
        {
            elem->field = 10 * elem->field + (format[start] - 48);
            start++;
        }
        if (format[start] == '.')
        {
            start++;
            while (format[start] >= '0' && format[start] <= '9')
            {
                elem->precision = 10 * elem->precision + (format[start] - 48);
                start++;
            }
        }
        /*if (format[start] == 'h' || format[start] == 'l' || format[start] == 'L')
        {
            elem->modif = (char *)malloc(sizeof(char) * 3);
            if (format[start + 1] == 'h' || format[start + 1] == 'l')
            {
                
            }
            elem->modif = format[start];
            start++;
        }*/
        // ^^^ Не закончил данную часть ^^^
        elem->conv_type = (char)malloc(sizeof(char) * 2);
        elem->conv_type = format[end];
        start++;
    }
}

int ft_printf(const char *format, ...)
{
    va_list ap;
    int i;
    int k;

    i = 0;
    va_start(ap, format);
    while (format[i] != '\0')
    {
        if (format[i] == '%')
        {
            k = i;
            while (format[i] != 'c' || format[i] != 's' || format[i] != 'p' 
            || format[i] != 'd' || format[i] != 'i' || format[i] != 'o' || 
            format[i] != 'u' || format[i] != 'x' || format[i] != 'X' || format[i] != 'f')
            {
                i++;
            }
            create(format, k + 1, i, ap);
        }
        else
        {
            ft_putchar(format[i]);
        }
        i++;
    }
    ft_putchar('\n');
    va_end(ap);
    return (i);
}

int main()
{
    int a;

    a = 4;
    ft_printf("Hello World %i", a);
    return (0);
}