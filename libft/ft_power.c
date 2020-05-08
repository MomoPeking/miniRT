/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Amber <Amber@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 14:21:51 by qdang             #+#    #+#             */
/*   Updated: 2020/05/02 15:08:25 by Amber            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_power(int base, int power)
{
	int		ans;

	ans = 1;
	if (power < 0)
		return (-1);
	if (power == 0)
		return (1);
	while (power > 0)
	{
		ans *= base;
		power--;
	}
	return (ans);
}
