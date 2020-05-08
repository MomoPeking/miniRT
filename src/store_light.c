/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Amber <Amber@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 22:39:52 by Amber             #+#    #+#             */
/*   Updated: 2020/05/07 14:36:20 by Amber            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

int		store_light(char **split, t_info *s)
{
	char		**temp;
	t_light		*info;
	t_list		*new;

	if (split_count(split) != 4)
		return (9);

	temp = ft_strsplit(split[1], ',');
	if (split_count(temp) != 3)
		return (free_temp(temp, NULL, 9));
	if (check_float(temp[0]) != 0 || check_float(temp[1]) != 0
		|| check_float(temp[2]) != 0)
		return (free_temp(temp, NULL, 9));
	info = ft_memalloc(sizeof(t_light));
	info->l_x = ft_atof(temp[0]);
	info->l_y = ft_atof(temp[1]);
	info->l_z = ft_atof(temp[2]);
	free_split(temp);
	
	if (check_float(split[2]) != 0)
		return (free_temp(NULL, info, 9));
	info->l_r = ft_atof(split[2]);
	if (info->l_r < 0 || info->l_r > 1)
		return (free_temp(NULL, info, 9));
		
	temp = ft_strsplit(split[3], ',');
	if (split_count(temp) != 3)
		return (free_temp(temp, info, 9));
	if (check_int(temp[0]) != 0 || check_int(temp[1]) != 0
		|| check_int(temp[2]) != 0)
		return (free_temp(temp, info, 9));
	info->l_red = ft_atoi(temp[0]);
	info->l_green = ft_atoi(temp[1]);
	info->l_blue = ft_atoi(temp[2]);		
	if (info->l_red < 0 || info->l_red > 255 || info->l_green < 0
		|| info->l_green > 255 || info->l_blue < 0 || info->l_blue > 255)
		return (free_temp(temp, info, 9));
	free_split(temp);
	new = ft_lstnew(info);
	ft_lstadd_back(&(s->l), new);
	return (0);
}
