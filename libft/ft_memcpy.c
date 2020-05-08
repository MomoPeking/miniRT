/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Amber <Amber@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 22:56:14 by qdang             #+#    #+#             */
/*   Updated: 2020/05/02 20:55:05 by Amber            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	size_t				i;
	unsigned char		*new;
	const unsigned char	*old;

	if (src == NULL && dst == NULL)
		return (NULL);
	new = (unsigned char *)dst;
	old = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		new[i] = old[i];
		i++;
	}
	return ((void *)new);
}
