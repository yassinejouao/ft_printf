/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjouaoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 16:46:53 by yjouaoud          #+#    #+#             */
/*   Updated: 2019/04/12 19:24:08 by yjouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char *s1c;
	unsigned char *s2c;

	s1c = (unsigned char*)s1;
	s2c = (unsigned char*)s2;
	while (*s1c && *s2c && (*s1c == *s2c))
	{
		s1c++;
		s2c++;
	}
	return (*s1c - *s2c);
}
