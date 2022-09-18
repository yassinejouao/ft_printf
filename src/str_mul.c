/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_mul.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjouaoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 15:23:06 by yjouaoud          #+#    #+#             */
/*   Updated: 2019/08/09 15:23:08 by yjouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_strrev(char *s)
{
	char		*temp;
	char		temp2;
	int			i;
	int			j;

	j = ft_strlen(s) - 1;
	i = 0;
	temp = s;
	while (i < j)
	{
		temp2 = s[i];
		s[i] = temp[j];
		temp[j] = temp2;
		i++;
		j--;
	}
}

static void		ft_add_0(char *s, size_t size)
{
	size_t		n;

	n = 0;
	while (n < size - 1)
	{
		s[n] = '0';
		n++;
	}
	s[n] = 0;
}

static void		ft_sub_mult(char *s1, char *s2, char *res, int len1)
{
	int			temp;
	int			rest;
	int			len2;
	int			i;
	int			j;

	temp = 0;
	i = 0;
	len2 = (int)ft_strlen(s2);
	while (i < (int)len1)
	{
		rest = 0;
		j = 0;
		while (j < (int)len2)
		{
			temp = res[i + j] - '0' + rest;
			res[i + j] = ((((res[i + j] - '0')
							+ rest + (s1[i] - '0')
							* (s2[j] - '0')) % 10) + '0');
			rest = ((temp + ((s1[i] - '0') * (s2[j] - '0'))) / 10);
			j++;
		}
		res[j + i++] = rest + '0';
	}
	res[i + j - 1] = (rest) + '0';
}

static char		*ft_ten_mult(char *s1)
{
	char		*res;
	char		*ten;
	size_t		len1;

	ten = ft_strdup("10");
	len1 = ft_strlen(s1);
	res = ft_strnew(len1 + 2);
	ft_add_0(res, len1 + 2);
	ft_strrev(s1);
	ft_strrev(ten);
	ft_sub_mult(s1, ten, res, len1);
	ft_strrev(res);
	free(ten);
	return (res);
}

char			*str_mul(char *s1, char *s2, int flag)
{
	size_t		len1;
	char		*res;

	if (flag == 1)
		res = ft_ten_mult(s1);
	else
	{
		len1 = ft_strlen(s1);
		res = ft_strnew(len1 + ft_strlen(s2));
		ft_add_0(res, len1 + ft_strlen(s2));
		ft_strrev(s1);
		ft_strrev(s2);
		ft_sub_mult(s1, s2, res, len1);
		ft_strrev(res);
	}
	return (res);
}
