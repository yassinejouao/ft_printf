/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjouaoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 16:46:12 by yjouaoud          #+#    #+#             */
/*   Updated: 2019/04/07 13:28:39 by yjouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	if (!needle[i])
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		while ((haystack[i + j] == needle[j]) && needle[j] && (j + i) < len)
			j++;
		if (!needle[j])
			return ((char*)(haystack + i));
		j = 0;
		i++;
	}
	return (NULL);
}
