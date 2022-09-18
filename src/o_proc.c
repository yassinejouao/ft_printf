/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_proc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjouaoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:36:00 by yjouaoud          #+#    #+#             */
/*   Updated: 2019/07/22 16:36:03 by yjouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long	get_va_arg_o(va_list ap, t_flags flgs)
{
	if (flgs.h == 1)
		return ((unsigned short)va_arg(ap, int));
	else if (flgs.h == 2)
		return ((unsigned char)va_arg(ap, int));
	else if (flgs.l == 1)
		return (va_arg(ap, unsigned long));
	else if (flgs.l == 2)
		return (va_arg(ap, unsigned long long));
	else
		return (va_arg(ap, unsigned int));
}

static	int			sub_w_o(t_flags flgs, char *o)
{
	int c;

	c = 0;
	c += (flgs.oc) ? 1 : 0;
	c += (flgs.pr > (int)ft_strlen(o)) ? flgs.pr : (int)ft_strlen(o);
	c -= (((!flgs.pr && flgs.dot) || flgs.oc) && o[0] == '0') ? 1 : 0;
	return (c);
}

static void			no_m_o(char *o, t_flags *flgs, int *sz)
{
	flgs->wd -= sub_w_o(*flgs, o);
	if (flgs->oc && flgs->pr > (int)ft_strlen(o) && o[0] != '0')
		flgs->wd += 1;
	flgs->pr -= (flgs->oc && o[0] != '0') ? 1 : 0;
	*sz += (!flgs->zero || flgs->dot) ? put_space(flgs->wd) : 0;
	*sz += (flgs->zero && !flgs->dot) ? put_zero(flgs->wd) : 0;
	*sz += (flgs->pr > (int)ft_strlen(o)) ?
		put_zero(flgs->pr - (int)ft_strlen(o)) : 0;
	if (flgs->oc)
		*sz += write(1, "0", 1) + 0 * flgs->pr--;
	*sz += (((!flgs->pr && flgs->dot) || flgs->oc) && o[0] == '0') ?
		0 : (int)ft_strlen(o);
	(((!flgs->pr && flgs->dot) || flgs->oc) && o[0] == '0') ?
		0 : ft_putstr(o);
}

static void			m_o(char *o, t_flags *flgs, int *sz)
{
	flgs->pr -= (flgs->oc && o[0] != '0') ? 1 : 0;
	if (flgs->pr > (int)ft_strlen(o))
	{
		*sz += put_zero(flgs->pr - (int)ft_strlen(o));
		flgs->wd -= flgs->pr - (int)ft_strlen(o);
	}
	if (flgs->oc)
		*sz += write(1, "0", 1) + 0 * flgs->wd--;
	(((!flgs->pr && flgs->dot) || flgs->oc) && o[0] == '0') ?
		0 : ft_putstr(o);
	*sz += (((!flgs->pr && flgs->dot) || flgs->oc) && o[0] == '0') ?
		0 : (int)ft_strlen(o);
	flgs->wd -= (((!flgs->pr && flgs->dot) || flgs->oc) && o[0] == '0') ?
		0 : (int)ft_strlen(o);
	*sz += put_space(flgs->wd);
}

void				o_proc(const char *frm, va_list ap, int *i, int *sz)
{
	unsigned long long	o;
	char				*s;
	t_flags				flgs;

	get_flgs(frm, &flgs, i, 'o');
	o = get_va_arg_o(ap, flgs);
	s = itoa_base(o, 8);
	if (flgs.mi)
		m_o(s, &flgs, sz);
	else
		no_m_o(s, &flgs, sz);
	free(s);
}
