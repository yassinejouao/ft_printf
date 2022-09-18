/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perc_proc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouazao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 18:23:11 by jbouazao          #+#    #+#             */
/*   Updated: 2019/08/07 18:23:12 by jbouazao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	perc_proc(const char *frm, va_list ap, int *i, int *sz)
{
	int		indx;
	t_flags	flgs;

	indx = *i;
	(void)ap;
	while (frm[indx] != '%')
		indx++;
	get_flgs(frm, &flgs, i, '%');
	if (flgs.mi)
	{
		*sz += write(1, "%", 1);
		*sz += put_space(flgs.wd - 1);
	}
	else
	{
		*sz += (flgs.zero) ? put_zero(flgs.wd - 1) : put_space(flgs.wd - 1);
		*sz += write(1, "%", 1);
	}
}
