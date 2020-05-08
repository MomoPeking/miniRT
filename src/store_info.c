/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Amber <Amber@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 22:22:08 by Amber             #+#    #+#             */
/*   Updated: 2020/05/07 16:42:30 by Amber            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

int		store_info(char *file, t_info *s)
{
	int		fd;
	char	*line;
	char	**split;
	int		i;
	int		j;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (3);
	if (get_next_line(fd, &line) == 0)
		return (5);
	free(line);
	j = 0;
	fd = open(file, O_RDONLY);
	while ((i = get_next_line(fd, &line)) != 0)
	{
		if (i < 0)
			return (4);
		if (line != NULL)
		{		
			split = ft_strsplit(line, ' ');
			if (ft_strcmp(split[0], "R") == 0)
				j = store_resolution(split, s);
			else if (ft_strcmp(split[0], "A") == 0)
				j = store_ambient_lighting(split, s);
			else if (ft_strcmp(split[0], "c") == 0)
				j = store_camera(split, s);
			else if (ft_strcmp(split[0], "l") == 0)
				j = store_light(split, s);
			else if (ft_strcmp(split[0], "sp") == 0)			
				j = store_sphere(split, s);
			else if (ft_strcmp(split[0], "pl") == 0)
				j = store_plane(split, s);
			else if (ft_strcmp(split[0], "sq") == 0)
				j = store_square(split, s);
			else if (ft_strcmp(split[0], "cy") == 0)
				j = store_cylinder(split, s);
			else if (ft_strcmp(split[0], "tr") == 0)
				j = store_triangle(split, s);
			else
				return (5);
			free_split(split);
			free(line);
			if (j != 0)
				return (j);
		}
	}
	return (0);
}



/*			
			

			if (ft_strcmp(split[0], "sq") == 0)

			if (ft_strcmp(split[0], "cy") == 0)

			if (ft_strcmp(split[0], "tr") == 0)
			ft_putstr(split[0]);
			ft_putchar('\n');
			ft_putstr(split[1]);
			ft_putchar('\n');
			ft_putstr(split[2]);
			ft_putchar('\n');
*/