/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_finfz_proc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjouaoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 14:24:10 by yjouaoud          #+#    #+#             */
/*   Updated: 2019/08/09 14:24:11 by yjouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	z_proc(t_flags *flgs, int *sz)
{
	char	*z;

	if (!flgs->pr && flgs->dot && !flgs->oc)
		z = ft_strdup("0");
	else
		z = ft_strdup("0.");
	flgs->pr = (!flgs->pr && !flgs->dot) ? 6 : flgs->pr;
	flgs->wd -= (flgs->plus || flgs->space) ? 1 : 0;
	*sz += (flgs->wd && !flgs->zero && !flgs->mi) ?
		put_space(flgs->wd - flgs->pr - ft_strlen(z)) : 0;
	if (flgs->plus)
		*sz += write(1, &flgs->plus, 1);
	else if (flgs->space)
		*sz += write(1, " ", 1);
	*sz += (flgs->zero && !flgs->mi) ?
		put_zero(flgs->wd - flgs->pr - ft_strlen(z)) : 0;
	ft_putstr(z);
	*sz += ft_strlen(z);
	*sz += put_zero(flgs->pr);
	*sz += (flgs->mi) ? put_space(flgs->wd - flgs->pr - ft_strlen(z)) : 0;
	free(z);
}

void	infnan_proc(t_flags *f, int *sz, char *mant)
{
	char	*inf;
	int		isinf;

	isinf = 0;
	if (check_mant_zero(mant) && (isinf = 1))
		inf = ft_strdup("inf");
	else
		inf = ft_strdup("nan");
	f->wd -= (isinf && (f->plus || f->space)) ? 1 : 0;
	*sz += (!f->mi && f->wd) ? put_space(f->wd - ft_strlen(inf)) : 0;
	if (f->plus && isinf)
		*sz += write(1, &f->plus, 1);
	else if (f->space && isinf)
		*sz += write(1, " ", 1);
	ft_putstr(inf);
	*sz += ft_strlen(inf);
	*sz += (f->mi && f->wd) ? put_space(f->wd - ft_strlen(inf)) : 0;
	free(inf);
}
