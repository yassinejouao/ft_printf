/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjouaoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:28:33 by yjouaoud          #+#    #+#             */
/*   Updated: 2019/04/12 15:31:33 by yjouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_findall(char *src, char c)
{
	int i;
	int j;
	int count;
	int *occ;

	i = 0;
	j = 0;
	count = 0;
	while (src[i])
		if (src[i++] == c)
			count++;
	i = -1;
	if (!(occ = (int*)malloc(sizeof(int) * count)))
		return (0);
	while (src[++i])
		if (src[i] == c)
			occ[j++] = i;
	return (occ);
}
