/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_arithmetics.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjouaoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 14:24:01 by yjouaoud          #+#    #+#             */
/*   Updated: 2019/08/04 14:24:02 by yjouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*str_delzero(char *s)
{
	char	*r;
	int		i;

	i = 0;
	while (s[i] == '0')
		i++;
	r = ft_strsub(s, i, ft_strlen(s) - i);
	free(s);
	return (r);
}

char	*str_pow(char *a, int pow)
{
	char	*prd;
	char	*tmp;

	prd = ft_strnew(1);
	ft_memset(prd, '1', 1);
	while (pow > 0)
	{
		tmp = prd;
		prd = str_mul(tmp, a, 0);
		free(tmp);
		pow--;
	}
	return (prd);
}

char	*mant_addzero(char *mant, int sz)
{
	char	*a;
	int		i;
	int		j;

	a = ft_strnew(sz);
	ft_memset(a, '0', sz);
	i = ft_strlen(a) - 1;
	j = ft_strlen(mant) - 1;
	while (j >= 0)
		a[i--] = mant[j--];
	return (a);
}
