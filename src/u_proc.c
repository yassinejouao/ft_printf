/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_proc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjouaoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 14:09:49 by yjouaoud          #+#    #+#             */
/*   Updated: 2019/07/28 14:09:51 by yjouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	sub_w_u(t_flags flgs, char *u)
{
	int c;

	c = 0;
	c += (flgs.space) ? 1 : 0;
	c += (flgs.pr > (int)ft_strlen(u)) ? flgs.pr : (int)ft_strlen(u);
	c -= (!flgs.pr && flgs.dot && u[0] == '0') ? 1 : 0;
	return (c);
}

static void	no_m_u(char *u, t_flags *flgs, int *sz)
{
	flgs->wd -= sub_w_u(*flgs, u);
	*sz += (!flgs->zero || flgs->dot) ?
		put_space(flgs->wd) : 0;
	if (flgs->space)
		*sz += write(1, " ", 1);
	*sz += (flgs->zero && !flgs->dot) ?
		put_zero(flgs->wd) : 0;
	*sz += (flgs->pr > (int)ft_strlen(u)) ?
		put_zero(flgs->pr - ft_strlen(u)) : 0;
	*sz += (!flgs->pr && flgs->dot && u[0] == '0') ? 0 : ft_strlen(u);
	(!flgs->pr && flgs->dot && u[0] == '0') ? 0 : ft_putstr(u);
}

static void	m_u(char *u, t_flags *flgs, int *sz)
{
	if (flgs->space)
		*sz += write(1, " ", 1) + 0 * flgs->wd--;
	if (flgs->pr > (int)ft_strlen(u))
	{
		*sz += put_zero(flgs->pr - ft_strlen(u));
		flgs->wd -= flgs->pr - ft_strlen(u);
	}
	(!flgs->pr && flgs->dot && u[0] == '0') ? 0 : ft_putstr(u);
	*sz += (!flgs->pr && flgs->dot && u[0] == '0') ? 0 : ft_strlen(u);
	flgs->wd -= (!flgs->pr && flgs->dot && u[0] == '0') ? 0 : ft_strlen(u);
	*sz += put_space(flgs->wd);
}

void		u_proc(const char *frm, va_list ap, int *i, int *sz)
{
	unsigned long long	o;
	char				*s;
	t_flags				flgs;

	get_flgs(frm, &flgs, i, 'u');
	o = get_va_arg_o(ap, flgs);
	s = itoa_base(o, 10);
	if (flgs.mi)
		m_u(s, &flgs, sz);
	else
		no_m_u(s, &flgs, sz);
	free(s);
}
