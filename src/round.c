/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   round.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbouazao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 14:42:07 by jbouazao          #+#    #+#             */
/*   Updated: 2019/08/09 15:44:54 by yjouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_round(char *pow, int pnt, int pr)
{
	int		i;
	int		i2;
	char	*temp;
	char	*tmp;

	i = (int)ft_strlen(pow) - pnt + pr;
	if (pow[i] >= '5')
	{
		i2 = i + 1;
		if (pow[i] == '5')
			while (pow[i2] == '0' && pow[i2])
				i2++;
		if (i2 < (int)ft_strlen(pow) || pow[i - 1] % 2 != 0 || pow[i] > '5')
		{
			temp = ft_strsub(pow, 0, i);
			tmp = temp;
			temp = str_add(tmp, "1");
			free(tmp);
		}
		else
			temp = ft_strsub(pow, 0, i);
	}
	else
		temp = ft_strsub(pow, 0, i);
	return (temp);
}

int		check_mant_zero(char *mant)
{
	int i;

	i = 0;
	while (mant[i] == '0' && mant[i])
		i++;
	if (i < (int)ft_strlen(mant))
		return (0);
	return (1);
}
