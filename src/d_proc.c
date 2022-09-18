/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_proc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjouaoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 10:36:16 by yjouaoud          #+#    #+#             */
/*   Updated: 2019/07/16 10:36:19 by yjouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long	get_va_arg(va_list ap, t_flags flgs)
{
	if (flgs.h == 1)
		return (va_arg(ap, int));
	else if (flgs.h == 2)
		return (va_arg(ap, int));
	else if (flgs.l == 1)
		return (va_arg(ap, long));
	else if (flgs.l == 2)
		return (va_arg(ap, long long));
	else
		return (va_arg(ap, int));
}

static int	sub_w(t_flags flgs, long long d)
{
	int c;

	c = 0;
	c += (flgs.plus || flgs.space) ? 1 : 0;
	c += (flgs.pr > n_len(d)) ? flgs.pr : n_len(d);
	c -= (!flgs.pr && flgs.dot && !d) ? 1 : 0;
	return (c);
}

static void	no_m_d(long long d, t_flags *flgs, int *sz)
{
	flgs->wd -= sub_w(*flgs, d);
	*sz += (!flgs->zero || flgs->dot) ? put_space(flgs->wd) : 0;
	if (flgs->plus)
		*sz += write(1, &flgs->plus, 1);
	else if (flgs->space && d >= 0)
		*sz += write(1, " ", 1);
	*sz += (flgs->zero && !flgs->dot) ?
		put_zero(flgs->wd) : 0;
	*sz += (flgs->pr > n_len(d)) ? put_zero(flgs->pr - n_len(d)) : 0;
	*sz += (!flgs->pr && flgs->dot && !d) ? 0 : n_len(d);
	(!flgs->pr && flgs->dot && !d) ? 0 : ft_putnbr(d);
}

static void	m_d(long long d, t_flags *flgs, int *sz)
{
	if (flgs->plus)
		*sz += write(1, &flgs->plus, 1) + 0 * flgs->wd--;
	else if (flgs->space)
		*sz += write(1, " ", 1) + 0 * flgs->wd--;
	if (flgs->pr > n_len(d))
	{
		*sz += put_zero(flgs->pr - n_len(d));
		flgs->wd -= flgs->pr - n_len(d);
	}
	(!flgs->pr && flgs->dot && !d) ? 0 : ft_putnbr(d);
	*sz += (!flgs->pr && flgs->dot && !d) ? 0 : n_len(d);
	flgs->wd -= (!flgs->pr && flgs->dot && !d) ? 0 : n_len(d);
	*sz += put_space(flgs->wd);
}

void		d_proc(const char *frm, va_list ap, int *i, int *sz)
{
	long long	d;
	t_flags		flgs;
	int			indx;

	indx = *i;
	while (frm[indx] != 'd' && frm[indx] != 'i')
		indx++;
	if (frm[indx] == 'd')
		get_flgs(frm, &flgs, i, 'd');
	if (frm[indx] == 'i')
		get_flgs(frm, &flgs, i, 'i');
	d = get_va_arg(ap, flgs);
	if (d < 0)
	{
		d *= -1;
		flgs.plus = '-';
	}
	if (flgs.mi)
		m_d(d, &flgs, sz);
	else
		no_m_d(d, &flgs, sz);
}
