/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_flg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjouaoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 09:42:43 by yjouaoud          #+#    #+#             */
/*   Updated: 2019/07/18 09:42:45 by yjouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	set_flgs(t_flags *flgs)
{
	flgs->mi = 0;
	flgs->plus = 0;
	flgs->space = 0;
	flgs->zero = 0;
	flgs->wd = 0;
	flgs->pr = 0;
	flgs->dot = 0;
	flgs->h = 0;
	flgs->l = 0;
	flgs->lcap = 0;
	flgs->oc = 0;
}

static	void	get_hl(const char *frm, t_flags *flgs, int *i, char c)
{
	while (frm[*i] != c)
		(*i)++;
	if (frm[*i - 1] == 'h')
		flgs->h = (frm[*i - 2] == 'h') ? 2 : 1;
	else if (frm[*i - 1] == 'l')
		flgs->l = (frm[*i - 2] == 'l') ? 2 : 1;
	else if (frm[*i - 1] == 'L')
		flgs->lcap = 1;
}

void			get_flgs(const char *frm, t_flags *flgs, int *i, char c)
{
	set_flgs(flgs);
	while (!(frm[*i] >= '1' && frm[*i] <= '9') &&
		frm[*i] != '.' && frm[*i] != c && frm[*i] != 'h' && frm[*i] != 'l')
	{
		if (frm[*i] == '-')
			flgs->mi = 1;
		else if (frm[*i] == '+')
			flgs->plus = '+';
		else if (frm[*i] == ' ')
			flgs->space = 1;
		else if (frm[*i] == '#')
			flgs->oc = 1;
		else if (frm[*i] == '0')
			flgs->zero = 1;
		(*i)++;
	}
	while (frm[*i] == '0')
		(*i)++;
	flgs->wd = (frm[*i] >= '1' && frm[*i] <= '9' && frm[*i] != c) ?
		ft_atoi(&frm[*i]) : 0;
	while (frm[*i] != '.' && frm[*i] != c && frm[*i] != 'h' && frm[*i] != 'l')
		(*i)++;
	flgs->pr = (frm[*i] == '.') ? ft_atoi(&frm[*i + 1]) : 0;
	flgs->dot = (frm[*i] == '.') ? 1 : 0;
	get_hl(frm, flgs, i, c);
}
