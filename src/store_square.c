/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_square.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Amber <Amber@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 22:43:25 by Amber             #+#    #+#             */
/*   Updated: 2020/05/07 16:13:21 by Amber            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

int		store_square(char **split, t_info *s)
{

	char		**temp;
	t_square	*info;
	t_list		*new;

	if (split_count(split) != 5)
		return (12);
		
	temp = ft_strsplit(split[1], ',');
	if (split_count(temp) != 3)
		return (free_temp(temp, NULL, 12));
	if (check_float(temp[0]) != 0 || check_float(temp[1]) != 0
		|| check_float(temp[2]) != 0)
		return (free_temp(temp, NULL, 12));
	info = ft_memalloc(sizeof(t_square));
	info->sq_x = ft_atof(temp[0]);
	info->sq_y = ft_atof(temp[1]);
	info->sq_z = ft_atof(temp[2]);
	free_split(temp);

	temp = ft_strsplit(split[2], ',');
	if (split_count(temp) != 3)
		return (free_temp(temp, info, 12));	
	if (check_float(temp[0]) != 0 || check_float(temp[1]) != 0
		|| check_float(temp[2]) != 0)
		return (free_temp(temp, info, 12));
	info->sq_vx = ft_atof(temp[0]);
	info->sq_vy = ft_atof(temp[1]);
	info->sq_vz = ft_atof(temp[2]);
	if (info->sq_vx < -1 || info->sq_vx > 1 || info->sq_vy < -1
		|| info->sq_vy > 1 || info->sq_vz < -1 || info->sq_vz > 1)
		return (free_temp(temp, info, 12));
	free_split(temp);

	if (check_float(split[3]) != 0)
		return (free_temp(NULL, info, 12));
	info->sq_s = ft_atof(split[3]);
	if (info->sq_s < 0)
		return (free_temp(NULL, info, 12));

	temp = ft_strsplit(split[4], ',');
	if (split_count(temp) != 3)
		return (free_temp(temp, info, 12));
	if (check_int(temp[0]) != 0 || check_int(temp[1]) != 0
		|| check_int(temp[2]) != 0)
		return (free_temp(temp, info, 12));		
	info->sq_red = ft_atoi(temp[0]);
	info->sq_green = ft_atoi(temp[1]);
	info->sq_blue = ft_atoi(temp[2]);
	if (info->sq_red < 0 || info->sq_red > 255 || info->sq_green < 0
		|| info->sq_green > 255 || info->sq_blue < 0 || info->sq_blue > 255)
		return (free_temp(temp, info, 12));	
	free_split(temp);	

	new = ft_lstnew(info);
	ft_lstadd_back(&(s->sq), new);
	return (0);	
}