/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capx_proc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjouaoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 15:08:50 by yjouaoud          #+#    #+#             */
/*   Updated: 2019/08/09 15:08:54 by yjouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		sub_w_x(t_flags flgs, char *x)
{
	int c;

	c = 0;
	c += (flgs.oc && x[0] != '0') ? 2 : 0;
	c += (flgs.pr > (int)ft_strlen(x)) ? flgs.pr : (int)ft_strlen(x);
	c -= ((!flgs.pr && flgs.dot) && x[0] == '0') ? 1 : 0;
	return (c);
}

static	void	no_m_x(char *x, t_flags *flgs, int *sz)
{
	flgs->wd -= sub_w_x(*flgs, x);
	if (flgs->oc && flgs->pr > (int)ft_strlen(x) && x[0] != '0')
		flgs->wd += 2;
	flgs->wd -= (flgs->oc && flgs->dot && flgs->pr > 0 && flgs->h > 0) ? 2 : 0;
	*sz += (!flgs->zero || flgs->dot) ? put_space(flgs->wd) : 0;
	if (flgs->oc && x[0] != '0')
	{
		*sz += write(1, "0X", 2);
	}
	*sz += (flgs->zero && !flgs->dot) ? put_zero(flgs->wd) : 0;
	*sz += (flgs->pr > (int)ft_strlen(x)) ?
		put_zero(flgs->pr - (int)ft_strlen(x)) : 0;
	*sz += (!flgs->pr && flgs->dot && x[0] == '0') ?
		0 : (int)ft_strlen(x);
	(!flgs->pr && flgs->dot && x[0] == '0') ?
		0 : ft_putstr(x);
}

static	void	m_x(char *x, t_flags *flgs, int *sz)
{
	if (flgs->oc && x[0] != '0')
	{
		*sz += write(1, "0X", 2);
		flgs->wd -= 2;
	}
	if (flgs->pr > (int)ft_strlen(x))
	{
		*sz += put_zero(flgs->pr - (int)ft_strlen(x));
		flgs->wd -= flgs->pr - (int)ft_strlen(x);
	}
	(!flgs->pr && flgs->dot && x[0] == '0') ?
		0 : ft_putstr(x);
	*sz += (!flgs->pr && flgs->dot && x[0] == '0') ?
		0 : (int)ft_strlen(x);
	flgs->wd -= (!flgs->pr && flgs->dot && x[0] == '0') ?
		0 : (int)ft_strlen(x);
	*sz += put_space(flgs->wd);
}

void			xcap_proc(const char *frm, va_list ap, int *i, int *sz)
{
	unsigned long long	x;
	char				*s;
	t_flags				flgs;

	get_flgs(frm, &flgs, i, 'X');
	x = get_va_arg_o(ap, flgs);
	s = itoa_basecap(x, 16);
	if (flgs.mi)
		m_x(s, &flgs, sz);
	else
		no_m_x(s, &flgs, sz);
	free(s);
}
