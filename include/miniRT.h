/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Amber <Amber@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 12:53:31 by Amber             #+#    #+#             */
/*   Updated: 2020/05/07 14:18:57 by Amber            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include "struct.h"

# include <fcntl.h>

# include <stdio.h>		//记得删除
# include <time.h>		//记得删除

# define ESC		53
# define X_BUTTON	17



int		store_info(char *file, t_info *s);

int		store_resolution(char **split, t_info *s);
int		store_ambient_lighting(char **split, t_info *s);
int		store_camera(char **split, t_info *s);
int		store_light(char **split, t_info *s);

int		store_sphere(char **split, t_info *s);
int		store_plane(char **split, t_info *s);
int		store_square(char **split, t_info *s);
int		store_cylinder(char **split, t_info *s);
int		store_triangle(char **split, t_info *s);


int		check_int(char *str);
int		check_float(char *str);

int		split_count(char **str);

void	error_info(unsigned char e);

void	free_split(char **str);
int		free_temp(char **split, void *content, int rt);
void	free_all(t_info *s, int i);


#endif