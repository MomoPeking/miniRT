/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Amber <Amber@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 22:38:27 by Amber             #+#    #+#             */
/*   Updated: 2020/05/05 11:40:08 by Amber            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

int		store_camera(char **split, t_info *s)
{
	char		**temp;
	t_camera	*info;
	t_list		*new;

	if (split_count(split) != 3)
		return (8);
	temp = ft_strsplit(split[1], ',');
	if (split_count(temp) != 3)
		return (free_temp(temp, NULL, 8));
	if (check_float(temp[0]) != 0 || check_float(temp[1]) != 0
		|| check_float(temp[2]) != 0)
		return (free_temp(temp, NULL, 8));
	info = ft_memalloc(sizeof(t_camera));
	info->c_x = ft_atof(temp[0]);
	info->c_y = ft_atof(temp[1]);
	info->c_z = ft_atof(temp[2]);
	free_split(temp);
	temp = ft_strsplit(split[2], ',');
	if (split_count(temp) != 3)
		return (free_temp(temp, info, 8));
	if (check_float(temp[0]) != 0 || check_float(temp[1]) != 0
		|| check_float(temp[2]) != 0)
		return (free_temp(temp, info, 8));
	info->c_vx = ft_atof(temp[0]);
	info->c_vy = ft_atof(temp[1]);
	info->c_vz = ft_atof(temp[2]);
	if (info->c_vx < -1 || info->c_vx > 1 || info->c_vy < -1
		|| info->c_vy > 1 || info->c_vz < -1 || info->c_vz > 1)
		return (free_temp(temp, info, 8));
	free_split(temp);
	new = ft_lstnew(info);
	ft_lstadd_back(&(s->c), new);
	return (0);
}
