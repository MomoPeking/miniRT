/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Amber <Amber@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 11:23:06 by Amber             #+#    #+#             */
/*   Updated: 2020/05/07 16:33:02 by Amber            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "../libft/libft.h"

typedef	struct	s_info
{
	int		r_x;
	int		r_y;
	double	a_r;
	int		a_red;
	int		a_green;
	int		a_blue;
	t_list	*c;
	t_list	*l;
	t_list	*sp;
	t_list	*pl;
	t_list	*sq;
	t_list	*cy;
	t_list	*tr;	
}				t_info;

typedef	struct	s_camera
{
	double	c_x;
	double	c_y;
	double	c_z;
	double	c_vx;
	double	c_vy;
	double	c_vz;
//	int		fov;	
}				t_camera;

typedef	struct	s_light
{
	double	l_x;
	double	l_y;
	double	l_z;
	double	l_r;
	int		l_red;
	int		l_green;
	int		l_blue;	
}				t_light;

typedef	struct	s_sphere
{
	double	sp_x;
	double	sp_y;
	double	sp_z;
	double	sp_d;
	int		sp_red;
	int		sp_green;
	int		sp_blue;	
}				t_sphere;

typedef	struct	s_plane
{
	double	pl_x;
	double	pl_y;
	double	pl_z;
	double	pl_vx;
	double	pl_vy;
	double	pl_vz;
	int		pl_red;
	int		pl_green;
	int		pl_blue;	
}				t_plane;

typedef	struct	s_square
{
	double	sq_x;
	double	sq_y;
	double	sq_z;
	double	sq_vx;
	double	sq_vy;
	double	sq_vz;
	double	sq_s;
	int		sq_red;
	int		sq_green;
	int		sq_blue;	
}				t_square;

typedef	struct	s_cylinder
{
	double	cy_x;
	double	cy_y;
	double	cy_z;
	double	cy_vx;
	double	cy_vy;
	double	cy_vz;
	double	cy_d;
	double	cy_h;
	int		cy_red;
	int		cy_green;
	int		cy_blue;	
}				t_cylinder;

typedef	struct	s_triangle
{
	double	tr_x1;
	double	tr_y1;
	double	tr_z1;
	double	tr_x2;
	double	tr_y2;
	double	tr_z2;
	double	tr_x3;
	double	tr_y3;
	double	tr_z3;
	int		tr_red;
	int		tr_green;
	int		tr_blue;	
}				t_triangle;

#endif