/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_f_proc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjouaoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 14:22:00 by yjouaoud          #+#    #+#             */
/*   Updated: 2019/08/09 14:22:01 by yjouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*init_rf(int len, int *p, char *pow, t_flags *f)
{
	char	*r;
	char	*tmp;
	char	*t;
	char	*ttmp;

	if (f->pr < *p)
	{
		tmp = ft_strsub(pow, 0, len - *p);
		r = str_delzero(ft_round(pow, *p, f->pr));
		t = ft_strsub(r, 0, len - *p + 1);
		ttmp = str_add(tmp, "1");
		if (!ft_strcmp(ttmp, t) && (1 + 0 * (*p)--))
			f->wd += (!f->pr && f->dot) ? 2 : 0;
		free(tmp);
		free(ttmp);
		free(t);
	}
	else
		r = ft_strdup(pow);
	return (r);
}

void		rrf_proc(t_flags *f, int *sz, char *pow, int lp[])
{
	char	*tmp;

	f->pr = (!f->pr && !f->dot) ? 6 : f->pr;
	tmp = init_rf(lp[1], &lp[0], pow, f);
	f->wd -= (f->dot && f->dot && !f->oc && !f->pr) ? 1 : 0;
	f->wd -= (f->plus || f->space) ? 1 : 0;
	*sz += (f->wd && !f->zero && !f->mi) ?
		put_space(f->wd - f->pr - (lp[1] - lp[0]) - 1) : 0;
	*sz += (f->plus) ? write(1, &f->plus, 1) : 0;
	*sz += (!f->plus && f->space) ? write(1, " ", 1) : 0;
	*sz += (f->wd && f->zero && !f->mi) ?
		put_zero(f->wd - f->pr - (lp[1] - lp[0]) - 1) : 0;
	*sz += ((!(f->dot && !f->pr) || f->oc)) ?
		print_fd(tmp, lp[1], lp[0], f->pr) : print_f(tmp, lp[1], lp[0], f->pr);
	*sz += (f->mi && f->wd) ?
		put_space(f->wd - f->pr - (lp[1] - lp[0]) - 1) : 0;
	free(pow);
	free(tmp);
}

static char	*init_sub(int len, int *p, char *pow, int pr)
{
	char *tmp;
	char *t;
	char *s;
	char *add;

	if (pr < *p)
	{
		tmp = ft_round(pow, *p, pr);
		s = ft_strsub(pow + (len - *p), 0, pr);
		t = ft_strsub(tmp + (len - *p) + 1, 0, pr);
		t = str_delzero(t);
		add = str_delzero(str_add(s, "1"));
		if (!ft_strcmp(add, t))
			*p -= 1;
		free(s);
		free(t);
		free(add);
	}
	else
		tmp = ft_strdup(pow);
	return (tmp);
}

void		sub_proc(t_flags *f, int *sz, char *pow, int lp[])
{
	char	*tmp;

	f->pr = (!f->pr && !f->dot) ? 6 : f->pr;
	tmp = pow;
	tmp = init_sub(lp[1], &lp[0], pow, f->pr);
	f->wd -= (f->dot && f->dot && !f->oc && !f->pr) ? 1 : 0;
	f->wd -= (f->plus || f->space) ? 1 : 0;
	*sz += (f->wd && !f->zero && !f->mi) ?
		put_space(f->wd - (f->pr + 2)) : 0;
	*sz += (f->plus) ? write(1, &f->plus, 1) : 0;
	*sz += (!f->plus && f->space) ? write(1, " ", 1) : 0;
	*sz += (f->wd && f->zero && !f->mi) ?
		put_zero(f->wd - (f->pr + 2)) : 0;
	*sz += ((!(f->dot && !f->pr) || f->oc)) ?
		p_fsubd(tmp, lp[1], lp[0], f->pr) : p_fsub(tmp, lp[1], lp[0]);
	*sz += (f->mi && f->wd) ? put_space(f->wd - (f->pr + 2)) : 0;
	free(pow);
	free(tmp);
}
