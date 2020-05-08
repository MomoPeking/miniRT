/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Amber <Amber@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 22:40:59 by Amber             #+#    #+#             */
/*   Updated: 2020/05/07 13:30:42 by Amber            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

int		store_sphere(char **split, t_info *s)
{	
	char		**temp;
	t_sphere	*info;
	t_list		*new;

	if (split_count(split) != 4)
		return (10);
	temp = ft_strsplit(split[1], ',');
	if (split_count(temp) != 3)
		return (free_temp(temp, NULL, 10));
	if (check_float(temp[0]) != 0 || check_float(temp[1]) != 0
		|| check_float(temp[2]) != 0)
		return (free_temp(temp, NULL, 10));
	info = ft_memalloc(sizeof(t_sphere));
	info->sp_x = ft_atof(temp[0]);
	info->sp_y = ft_atof(temp[1]);
	info->sp_z = ft_atof(temp[2]);
	free_split(temp);
	if (check_float(split[2]) != 0)
		return (free_temp(NULL, info, 10));
	info->sp_d = ft_atof(split[2]);
	if (info->sp_d < 0)
		return (free_temp(NULL, info, 10));
	temp = ft_strsplit(split[3], ',');
	if (split_count(temp) != 3)
		return (free_temp(temp, info, 10));
	if (check_int(temp[0]) != 0 || check_int(temp[1]) != 0
		|| check_int(temp[2]) != 0)
		return (free_temp(temp, info, 10));			
	info->sp_red = ft_atoi(temp[0]);
	info->sp_green = ft_atoi(temp[1]);
	info->sp_blue = ft_atoi(temp[2]);				
	if (info->sp_red < 0 || info->sp_red > 255 || info->sp_green < 0
		|| info->sp_green > 255 || info->sp_blue < 0 || info->sp_blue > 255)
		return (free_temp(temp, info, 10));
	free_split(temp);
	new = ft_lstnew(info);
	ft_lstadd_back(&(s->sp), new);
	return (0);	
}