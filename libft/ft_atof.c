/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Amber <Amber@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 15:14:21 by Amber             #+#    #+#             */
/*   Updated: 2020/05/02 19:19:57 by Amber            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atof(const char *str)
{
	int		sign;
	double	ans;
	char	*dec;

	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	ans = ft_atoi(str);
	dec = ft_strchr(str, '.');
	if (dec)
		ans += (double)ft_atoi(dec + 1) / ft_power(10, ft_strlen(dec + 1));		
	return (ans * sign);	
}