/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjouaoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 16:47:46 by yjouaoud          #+#    #+#             */
/*   Updated: 2019/04/12 19:25:23 by yjouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1c;
	unsigned char	*s2c;

	i = 0;
	if (!n)
		return (0);
	s1c = (unsigned char*)s1;
	s2c = (unsigned char*)s2;
	while (s1c[i] && s2c[i] && (s1c[i] == s2c[i]) && i < n - 1)
		i++;
	return (s1c[i] - s2c[i]);
}
