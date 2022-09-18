/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjouaoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 20:37:12 by yjouaoud          #+#    #+#             */
/*   Updated: 2019/04/13 15:27:21 by yjouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_ccc(int n)
{
	int tmp;
	int size;

	tmp = n;
	size = 1;
	while ((tmp = tmp / 10))
		size++;
	return (size);
}

char		*ft_itoa(int n)
{
	char	*a;
	int		size;
	int		sign;

	sign = 0;
	if (n < 0)
		sign = 1;
	size = ft_ccc(n);
	a = ft_strnew(size + sign);
	if (a == NULL)
		return (NULL);
	if (sign)
		a[0] = '-';
	while (size--)
	{
		if (sign == 1)
			a[size + sign] = -(n % 10) + '0';
		else
			a[size + sign] = (n % 10) + '0';
		n /= 10;
	}
	return (a);
}
