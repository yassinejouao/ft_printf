/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_proc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjouaoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 16:16:09 by yjouaoud          #+#    #+#             */
/*   Updated: 2019/07/29 16:16:11 by yjouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long double	get_va_arg_f(va_list ap, t_flags flgs)
{
	if (flgs.lcap == 1)
		return (va_arg(ap, long double));
	else
		return ((long double)va_arg(ap, double));
}

static char			*conv_mant(char *mant, int exp)
{
	int		i;
	char	*a;
	char	*tmp;
	char	*pw;

	i = -1;
	a = ft_strnew(1);
	(exp == 0) ? ft_memset(a, '0', 1) : ft_memset(a, '1', 1);
	while (mant[++i])
	{
		tmp = a;
		a = str_mul(a, "10", 1);
		free(tmp);
		if (mant[i] == '1')
		{
			tmp = ft_strdup("5");
			pw = str_pow(tmp, i + 1);
			free(tmp);
			tmp = a;
			a = str_add(a, pw);
			free(tmp);
			free(pw);
		}
	}
	return (a);
}

static void			rf_proc(t_flags *f, int *sz, char *mant, union u_ld ld)
{
	int			lp[2];
	char		*pow;
	char		*tmp;
	char		*tmpm;

	tmpm = conv_mant(mant, ld.uld.exp);
	if (ld.uld.exp - 16383 < 0 && (lp[0] = ((ld.uld.exp - 16383) * -1) + 63))
		pow = str_pow("5", (ld.uld.exp - 16383) * -1);
	else
	{
		pow = str_pow("2", ld.uld.exp - 16383);
		lp[0] = 63;
	}
	tmp = pow;
	pow = str_mul(pow, tmpm, 0);
	free(tmp);
	free(tmpm);
	pow = (!(ld.ld > 0 && ld.ld < 1)) ? str_delzero(pow) : pow;
	lp[1] = (int)ft_strlen(pow);
	if (ld.ld > 0 && ld.ld < 1)
		sub_proc(f, sz, pow, lp);
	else
		rrf_proc(f, sz, pow, lp);
}

void				f_proc(const char *frm, va_list ap, int *i, int *sz)
{
	char		*mant;
	char		*bin;
	t_flags		flgs;
	union u_ld	uld;

	get_flgs(frm, &flgs, i, 'f');
	uld.ld = get_va_arg_f(ap, flgs);
	if ((flgs.pr < 0 || flgs.wd < 0) && (flgs.pr = 6))
		flgs.wd = 0;
	if (uld.uld.sign)
		flgs.plus = '-';
	if (uld.ld == 0)
		z_proc(&flgs, sz);
	else
	{
		bin = itoa_base(uld.uld.mant, 2);
		mant = mant_addzero(bin, 63);
		if (uld.uld.exp == 32767)
			infnan_proc(&flgs, sz, mant);
		else
			rf_proc(&flgs, sz, mant, uld);
		free(mant);
		free(bin);
	}
}
