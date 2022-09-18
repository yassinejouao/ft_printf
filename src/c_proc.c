/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_proc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjouaoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 15:14:54 by yjouaoud          #+#    #+#             */
/*   Updated: 2019/07/13 19:11:05 by yjouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	c_proc(const char *frm, va_list ap, int *i, int *sz)
{
	char	c;
	int		indx;

	c = (char)va_arg(ap, int);
	indx = *i;
	if (frm[*i] == '-')
		ft_putchar(c);
	while (frm[*i] != 'c' && frm[*i])
	{
		if (frm[*i] >= '1' && frm[*i] <= '9')
		{
			*sz += put_space(ft_atoi(&frm[*i]) - 1);
			break ;
		}
		(*i)++;
	}
	if (frm[indx] != '-')
		ft_putchar(c);
	(*sz)++;
}
