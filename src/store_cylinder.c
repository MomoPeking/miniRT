/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Amber <Amber@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 22:44:36 by Amber             #+#    #+#             */
/*   Updated: 2020/05/07 16:36:02 by Amber            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

int		store_cylinder(char **split, t_info *s)
{
	char		**temp;
	t_cylinder	*info;
	t_list		*new;

	if (split_count(split) != 6)
		return (13);

	temp = ft_strsplit(split[1], ',');
	if (split_count(temp) != 3)
		return (free_temp(temp, NULL, 13));
	if (check_float(temp[0]) != 0 || check_float(temp[1]) != 0
		|| check_float(temp[2]) != 0)
		return (free_temp(temp, NULL, 13));
	info = ft_memalloc(sizeof(t_square));
	info->cy_x = ft_atof(temp[0]);
	info->cy_y = ft_atof(temp[1]);
	info->cy_z = ft_atof(temp[2]);
	free_split(temp);

	temp = ft_strsplit(split[2], ',');
	if (split_count(temp) != 3)
		return (free_temp(temp, info, 13));	
	if (check_float(temp[0]) != 0 || check_float(temp[1]) != 0
		|| check_float(temp[2]) != 0)
		return (free_temp(temp, info, 13));
	info->cy_vx = ft_atof(temp[0]);
	info->cy_vy = ft_atof(temp[1]);
	info->cy_vz = ft_atof(temp[2]);
	if (info->cy_vx < -1 || info->cy_vx > 1 || info->cy_vy < -1
		|| info->cy_vy > 1 || info->cy_vz < -1 || info->cy_vz > 1)
		return (free_temp(temp, info, 13));
	free_split(temp);	
	
	if (check_float(split[3]) != 0)
		return (free_temp(NULL, info, 13));
	info->cy_d = ft_atof(split[3]);
	if (info->cy_d < 0)
		return (free_temp(NULL, info, 13));
	if (check_float(split[4]) != 0)
		return (free_temp(NULL, info, 13));
	info->cy_h = ft_atof(split[4]);
	if (info->cy_h < 0)
		return (free_temp(NULL, info, 13));

	temp = ft_strsplit(split[5], ',');
	if (split_count(temp) != 3)
		return (free_temp(temp, info, 13));
	if (check_int(temp[0]) != 0 || check_int(temp[1]) != 0
		|| check_int(temp[2]) != 0)
		return (free_temp(temp, info, 13));		
	info->cy_red = ft_atoi(temp[0]);
	info->cy_green = ft_atoi(temp[1]);
	info->cy_blue = ft_atoi(temp[2]);
	if (info->cy_red < 0 || info->cy_red > 255 || info->cy_green < 0
		|| info->cy_green > 255 || info->cy_blue < 0 || info->cy_blue > 255)
		return (free_temp(temp, info, 13));	
	free_split(temp);		

	new = ft_lstnew(info);
	ft_lstadd_back(&(s->cy), new);
	return (0);
}