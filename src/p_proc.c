/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_proc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjouaoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 15:32:19 by yjouaoud          #+#    #+#             */
/*   Updated: 2019/07/29 15:32:23 by yjouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	p_proc(const char *frm, va_list ap, int *i, int *sz)
{
	unsigned long	p;
	char			*s;
	t_flags			flgs;

	p = (unsigned long)va_arg(ap, void*);
	get_flgs(frm, &flgs, i, 'p');
	s = itoa_base(p, 16);
	if (flgs.mi)
	{
		*sz += write(1, "0x", 2);
		ft_putstr(s);
		*sz += ft_strlen(s);
		*sz += put_space(flgs.wd - ft_strlen(s) - 2);
	}
	else
	{
		*sz += put_space(flgs.wd - ft_strlen(s) - 2);
		*sz += write(1, "0x", 2);
		ft_putstr(s);
		*sz += ft_strlen(s);
	}
	free(s);
}
