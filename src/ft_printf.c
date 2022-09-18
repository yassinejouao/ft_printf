/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjouaoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 11:54:15 by yjouaoud          #+#    #+#             */
/*   Updated: 2019/07/13 19:11:40 by yjouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_params(const char *frm, va_list ap, int *i, int *sz)
{
	int		tt;
	int		indx;
	t_types	v_tps;

	v_tps = get_types();
	indx = *i;
	while (frm[*i])
	{
		tt = 0;
		while (tt < 11)
		{
			if (frm[*i] == v_tps.types[tt])
			{
				v_tps.t[tt](frm, ap, &indx, sz);
				return ;
			}
			tt++;
		}
		(*i)++;
	}
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int		sz;
	int		i;

	i = 0;
	sz = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			get_params(format, ap, &i, &sz);
		}
		else
		{
			write(1, &format[i], 1);
			sz++;
		}
		i++;
	}
	return (sz);
}
