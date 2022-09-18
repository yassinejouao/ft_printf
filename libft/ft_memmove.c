/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjouaoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 16:26:32 by yjouaoud          #+#    #+#             */
/*   Updated: 2019/04/07 15:18:04 by yjouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t		i;
	const char	*s;
	char		*d;

	i = 0;
	s = (const char *)src;
	d = (char *)dst;
	if (s < d)
	{
		while ((int)(--n) >= 0)
			d[n] = s[n];
	}
	else
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	return (d);
}
