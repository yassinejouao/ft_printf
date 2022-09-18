/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_proc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjouaoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 19:31:51 by yjouaoud          #+#    #+#             */
/*   Updated: 2019/07/13 19:32:01 by yjouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		prf(const char *frm, int i)
{
	int pr;

	pr = 0;
	while (frm[i] != '.' && frm[i] && frm[i] != 's')
		i++;
	if (frm[i] == '.')
		i++;
	else
		return (0);
	if (frm[i] >= '1' && frm[i] <= '9')
		pr = ft_atoi(&frm[i]);
	return (pr);
}

void			s_proc(const char *frm, va_list ap, int *i, int *sz)
{
	char	*s;
	char	*tmp;
	int		indx;
	int		pr;
	int		must_free;

	s = va_arg(ap, char*);
	indx = *i;
	must_free = 0;
	if (!s && (must_free = 1))
		s = ft_strdup("(null)");
	if ((pr = prf(frm, *i)))
	{
		(must_free == 1 && (tmp = s)) ? free(tmp) : ft_putstr("");
		s = ft_strsub(s, 0, pr);
		must_free = 1;
	}
	(frm[indx] == '-' && (*i)++) ? ft_putstr(s) : ft_putstr("");
	if (frm[*i] >= '1' && frm[*i] <= '9')
		*sz += put_space(ft_atoi(&frm[*i]) - ft_strlen(s));
	(frm[indx] != '-' && (*i)++) ? ft_putstr(s) : ft_putstr("");
	(must_free == 1) ? free(s) : ft_putstr("");
	(*sz) += ft_strlen(s);
}
