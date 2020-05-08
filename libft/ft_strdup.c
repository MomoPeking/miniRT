/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Amber <Amber@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 13:22:15 by qdang             #+#    #+#             */
/*   Updated: 2020/05/01 14:09:06 by Amber            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*str;

	i = 0;
	if (!s1)
		return (NULL);
	str = ft_strnew(ft_strlen(s1));
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	return (str);
}
