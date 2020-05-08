/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Amber <Amber@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 23:20:08 by Amber             #+#    #+#             */
/*   Updated: 2020/05/02 19:40:46 by Amber            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

int		check_int(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (-1);
		str++;
	}
	return (0);
}

int		check_float(char *str)
{
	if (*str == '-')
		str++;
	while (*str && *str != '.')
	{
		if (*str < '0' || *str > '9')
			return (-1);
		str++;
	}
	if (*str == '.')
		str++;
	return (check_int(str));
}