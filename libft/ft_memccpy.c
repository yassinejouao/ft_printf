/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjouaoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 16:18:55 by yjouaoud          #+#    #+#             */
/*   Updated: 2019/04/02 17:48:50 by yjouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*d;
	const char		*s;
	char			cc;

	i = 0;
	s = (const char *)src;
	d = (unsigned char *)dst;
	cc = (unsigned char)c;
	while (i < n)
	{
		d[i] = s[i];
		if (s[i] == cc)
			return (d + i + 1);
		i++;
	}
	return (NULL);
}
