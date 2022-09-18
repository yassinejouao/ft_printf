/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjouaoud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 20:40:35 by yjouaoud          #+#    #+#             */
/*   Updated: 2019/04/13 15:26:37 by yjouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_wc(char const *s, char c)
{
	int		i;
	int		wc;

	i = 0;
	wc = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
			wc++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (wc);
}

static	int	ft_cc(const char *s, char c)
{
	int		cc;
	int		i;

	cc = 0;
	i = 0;
	while (s[i] == c)
		i++;
	while (s[i] != c && s[i++])
		cc++;
	return (cc);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**split;
	int		i;
	int		j;
	int		k;

	i = -1;
	j = 0;
	if (!s || !(split = (char **)malloc(sizeof(*split) * (ft_wc(s, c) + 1))))
		return (NULL);
	while (++i < ft_wc(s, c))
	{
		if (!(split[i] = (char*)malloc(ft_cc(&s[j], c) + 1)))
			return (NULL);
		k = 0;
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
			split[i][k++] = s[j++];
		split[i][k] = '\0';
	}
	split[i] = 0;
	return (split);
}
