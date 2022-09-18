/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjouaoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 15:35:21 by yjouaoud          #+#    #+#             */
/*   Updated: 2019/08/09 15:35:23 by yjouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_fd(char *pow, int lenp, int pnt, int pr)
{
	int indx;
	int count;

	indx = 0;
	count = 0;
	while (indx < lenp - pnt)
		ft_putchar(pow[indx++]);
	count += write(1, ".", 1);
	while (indx < pr + lenp - pnt && pow[indx])
		ft_putchar(pow[indx++]);
	count += indx;
	if (pr >= pnt)
		count += put_zero(pr - pnt);
	return (count);
}

int	print_f(char *pow, int lenp, int pnt, int pr)
{
	int indx;
	int count;

	indx = 0;
	count = 0;
	while (indx < lenp - pnt)
		ft_putchar(pow[indx++]);
	while (indx < pr + lenp - pnt && pow[indx])
		ft_putchar(pow[indx++]);
	count += indx;
	if (pr >= pnt)
		count += put_zero(pr - pnt);
	return (count);
}

int	p_fsubd(char *s, int len, int pnt, int pr)
{
	int i;
	int j;
	int c;

	i = 0;
	c = 0;
	while (i + 1 < len - pnt && (s[i + 1]))
		i++;
	c += write(1, &s[i++], 1);
	c += write(1, ".", 1);
	j = 0;
	while (j <= pr && s[i + j])
		c += write(1, &s[i + j++], 1);
	c += put_zero(pr - j);
	return (c);
}

int	p_fsub(char *s, int len, int pnt)
{
	int i;
	int c;

	i = 0;
	c = 0;
	while (i + 1 < len - pnt && (s[i + 1]))
		i++;
	c += write(1, &s[i++], 1);
	return (c);
}
