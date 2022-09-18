/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjouaoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 15:14:23 by yjouaoud          #+#    #+#             */
/*   Updated: 2019/08/09 15:14:25 by yjouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	str_swap(char *s1, char *s2)
{
	char	*temp;

	temp = s1;
	s1 = s2;
	s2 = temp;
}

static	char	*ft_sub_add(char *s1, char *s2, size_t size)
{
	char			*res;
	unsigned int	rest;
	unsigned int	sum;
	size_t			i;

	sum = 0;
	i = 0;
	rest = 0;
	res = ft_strnew(size + 1);
	while (i < ft_strlen(s2))
	{
		sum = rest + ((s1[i] - '0') + (s2[i] - '0'));
		res[i++] = (sum % 10) + '0';
		rest = sum / 10;
	}
	while (i < ft_strlen(s1))
	{
		sum = rest + (s1[i] - '0');
		res[i++] = (sum % 10) + '0';
		rest = sum / 10;
	}
	res[i] = (rest != 0) ? rest + '0' : '0';
	return (res);
}

char			*str_add(char *s1, char *s2)
{
	char	*res;

	if (ft_strlen(s1) < ft_strlen(s2))
		str_swap(s1, s2);
	ft_strrev(s1);
	ft_strrev(s2);
	res = ft_sub_add(s1, s2, ft_strlen(s1));
	ft_strrev(res);
	return (res);
}
