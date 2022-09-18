/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjouaoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 15:32:24 by yjouaoud          #+#    #+#             */
/*   Updated: 2019/04/13 20:31:21 by yjouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	ld;
	size_t	ls;
	size_t	r;

	i = 0;
	ld = ft_strlen(dest);
	ls = ft_strlen(src);
	if (size <= ld)
		return (size + ls);
	else
	{
		r = ld + ls;
		while (src[i] && ld + 1 < size)
		{
			dest[ld] = src[i];
			ld++;
			i++;
		}
		dest[ld] = '\0';
	}
	return (r);
}
