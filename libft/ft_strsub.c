/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Amber <Amber@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 19:40:58 by qdang             #+#    #+#             */
/*   Updated: 2020/05/01 08:39:16 by Amber            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Cut an excerpt of string from s and return it as a new string, the start
** point and length is given.
*/

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*str;

	i = 0;
	if (!s || len == 0)
		return (NULL);
	str = ft_strnew(len);
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	return (str);
}
