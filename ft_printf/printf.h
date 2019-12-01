/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damerica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 17:41:56 by damerica          #+#    #+#             */
/*   Updated: 2019/11/27 17:42:00 by damerica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>

typedef struct  s_spec
{
    int left;
    int minus;
    int plus;
    int probel;
    int nul;
    int field;
    int precision;
    char *modif;
    char conv_type;
}               t_spec;