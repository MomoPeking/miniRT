/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Amber <Amber@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 22:42:40 by Amber             #+#    #+#             */
/*   Updated: 2020/05/07 13:34:59 by Amber            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

int		store_plane(char **split, t_info *s)
{
	char		**temp;
	t_plane		*info;
	t_list		*new;

	if (split_count(split) != 4)
		return (11);
	temp = ft_strsplit(split[1], ',');
	if (split_count(temp) != 3)
		return (free_temp(temp, NULL, 11));
	if (check_float(temp[0]) != 0 || check_float(temp[1]) != 0
		|| check_float(temp[2]) != 0)
		return (free_temp(temp, NULL, 11));
	info = ft_memalloc(sizeof(t_plane));
	info->pl_x = ft_atof(temp[0]);
	info->pl_y = ft_atof(temp[1]);
	info->pl_z = ft_atof(temp[2]);
	free_split(temp);
	temp = ft_strsplit(split[2], ',');
	if (split_count(temp) != 3)
		return (free_temp(temp, info, 11));	
	if (check_float(temp[0]) != 0 || check_float(temp[1]) != 0
		|| check_float(temp[2]) != 0)
		return (free_temp(temp, info, 11));
	info->pl_vx = ft_atof(temp[0]);
	info->pl_vy = ft_atof(temp[1]);
	info->pl_vz = ft_atof(temp[2]);
	if (info->pl_vx < -1 || info->pl_vx > 1 || info->pl_vy < -1
		|| info->pl_vy > 1 || info->pl_vz < -1 || info->pl_vz > 1)
		return (free_temp(temp, info, 11));
	free_split(temp);	
	temp = ft_strsplit(split[3], ',');
	if (split_count(temp) != 3)
		return (free_temp(temp, info, 11));
	if (check_int(temp[0]) != 0 || check_int(temp[1]) != 0
		|| check_int(temp[2]) != 0)
		return (free_temp(temp, info, 11));		
	info->pl_red = ft_atoi(temp[0]);
	info->pl_green = ft_atoi(temp[1]);
	info->pl_blue = ft_atoi(temp[2]);
	if (info->pl_red < 0 || info->pl_red > 255 || info->pl_green < 0
		|| info->pl_green > 255 || info->pl_blue < 0 || info->pl_blue > 255)
		return (free_temp(temp, info, 11));	
	free_split(temp);
	new = ft_lstnew(info);
	ft_lstadd_back(&(s->pl), new);
	return (0);
}