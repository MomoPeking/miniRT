/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_ambient_lighting.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Amber <Amber@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 22:37:54 by Amber             #+#    #+#             */
/*   Updated: 2020/05/05 11:33:25 by Amber            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

int		store_ambient_lighting(char **split, t_info *s)
{
	char	**temp;

	if (split_count(split) != 3)
		return (7);
	if (check_float(split[1]) != 0)
		return (7);
	s->a_r = ft_atof(split[1]);
	if (s->a_r < 0 || s->a_r > 1)
		return (7);
	temp = ft_strsplit(split[2], ',');
	if (split_count(temp) != 3)
		return (free_temp(temp, NULL, 7));
	if (check_int(temp[0]) != 0 || check_int(temp[1]) != 0
		|| check_int(temp[2]) != 0)
		return (free_temp(temp, NULL, 7));
	s->a_red = ft_atoi(temp[0]);
	s->a_green = ft_atoi(temp[1]);
	s->a_blue = ft_atoi(temp[2]);
	if (s->a_red < 0 || s->a_red > 255 || s->a_green < 0 || s->a_green > 255
		|| s->a_blue < 0 || s->a_blue > 255)
		return (free_temp(temp, NULL, 7));
	free_split(temp);
	return (0);
}