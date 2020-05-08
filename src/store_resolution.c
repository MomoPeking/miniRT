/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_resolution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Amber <Amber@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 22:37:04 by Amber             #+#    #+#             */
/*   Updated: 2020/05/04 22:37:27 by Amber            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

int		store_resolution(char **split, t_info *s)
{
	if (split_count(split) != 3)
		return (6);
	if (check_int(split[1]) != 0 || check_int(split[2]) != 0)
		return (6);
	s->r_x = ft_atoi(split[1]);
	s->r_y = ft_atoi(split[2]);
	return (0);
}
