/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_triangle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Amber <Amber@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 22:45:26 by Amber             #+#    #+#             */
/*   Updated: 2020/05/07 16:39:42 by Amber            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

int		store_triangle(char **split, t_info *s)
{

	char		**temp;
	t_triangle	*info;
	t_list		*new;

	if (split_count(split) != 5)
		return (14);

	temp = ft_strsplit(split[1], ',');
	if (split_count(temp) != 3)
		return (free_temp(temp, NULL, 14));
	if (check_float(temp[0]) != 0 || check_float(temp[1]) != 0
		|| check_float(temp[2]) != 0)
		return (free_temp(temp, NULL, 14));
	info = ft_memalloc(sizeof(t_triangle));
	info->tr_x1 = ft_atof(temp[0]);
	info->tr_y1 = ft_atof(temp[1]);
	info->tr_z1 = ft_atof(temp[2]);	
	free_split(temp);		
	
	temp = ft_strsplit(split[2], ',');
	if (split_count(temp) != 3)
		return (free_temp(temp, info, 14));
	if (check_float(temp[0]) != 0 || check_float(temp[1]) != 0
		|| check_float(temp[2]) != 0)
		return (free_temp(temp, info, 14));
	info->tr_x2 = ft_atof(temp[0]);
	info->tr_y2 = ft_atof(temp[1]);
	info->tr_z2 = ft_atof(temp[2]);
	free_split(temp);

	temp = ft_strsplit(split[3], ',');
	if (split_count(temp) != 3)
		return (free_temp(temp, info, 14));
	if (check_float(temp[0]) != 0 || check_float(temp[1]) != 0
		|| check_float(temp[2]) != 0)
		return (free_temp(temp, info, 14));
	info->tr_x3 = ft_atof(temp[0]);
	info->tr_y3 = ft_atof(temp[1]);
	info->tr_z3 = ft_atof(temp[2]);
	free_split(temp);

	temp = ft_strsplit(split[4], ',');
	if (split_count(temp) != 3)
		return (free_temp(temp, info, 14));
	if (check_int(temp[0]) != 0 || check_int(temp[1]) != 0
		|| check_int(temp[2]) != 0)
		return (free_temp(temp, info, 14));		
	info->tr_red = ft_atoi(temp[0]);
	info->tr_green = ft_atoi(temp[1]);
	info->tr_blue = ft_atoi(temp[2]);
	if (info->tr_red < 0 || info->tr_red > 255 || info->tr_green < 0
		|| info->tr_green > 255 || info->tr_blue < 0 || info->tr_blue > 255)
		return (free_temp(temp, info, 14));	
	free_split(temp);	

	new = ft_lstnew(info);
	ft_lstadd_back(&(s->tr), new);
	return (0);	
}