/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Amber <Amber@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 21:11:05 by qdang             #+#    #+#             */
/*   Updated: 2020/05/01 16:26:30 by Amber            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	str_size(char const *s, char c)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			size++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (size);
}

static char	**ans_malloc(char const *s, char c)
{
	char	**ans;
	size_t	count;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	ans = (char **)malloc(sizeof(char *) * str_size(s, c) + 1);
	if (!ans)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		count = 0;
		while (s[i] && s[i] != c)
		{
			i++;
			count++;
		}
		if (count != 0)
			ans[j] = ft_strnew(count);
		j++;
	}
	return (ans);
}

static char	**split_now(char const *s, char c, char **ans)
{
	size_t	i;
	size_t	a;
	size_t	b;
	size_t	idx;

	i = 0;
	a = 0;
	while (s[i])
	{
		idx = 0;
		b = 0;
		while (s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			ans[a][b] = s[i];
			b++;
			i++;
			idx = 1;
		}
		if (idx == 1)
			a++;
	}
	ans[a] = NULL;
	return (ans);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**ans;

	if (s == NULL)
		return (NULL);
	ans = ans_malloc(s, c);
	if (!ans)
		return (NULL);
	return (split_now(s, c, ans));
}
