/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Amber <Amber@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 12:39:50 by Amber             #+#    #+#             */
/*   Updated: 2020/05/07 16:41:24 by Amber            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

int		key_press(int keycode, void *param)
{
	param = NULL;
	if (keycode == ESC)
		exit(0);
	return (0);
}	

int		split_count(char **str)
{
	int		i;

	i = 0;
	while (str[i] != NULL)
		i++;
	return (i);
}

int		main(int ac, char **av)
{
	t_info		*s;
	int			i;
/*
	void	*mlx_ptr;
	void	*win_ptr;
	void	*param = NULL;
*/
/*	
	clock_t		start;
	clock_t		finish;
	double 		total_time;

	start = clock();
*/

	if (ac == 1 || ac > 3)
		error_info(1);
	if (ac == 3 && ft_strcmp(av[2], "--save") != 0)
		error_info(2);
	s = (t_info *)ft_memalloc(sizeof(t_info));
	i = store_info(av[1], s);
	if (i != 0)
		free_all(s, i);

	
	printf("x: %d, y: %d\n", s->r_x, s->r_y);
	printf("a.ratio: %f, a.red: %d, a.green: %d, a.blue: %d\n", s->a_r, s->a_red, s->a_green, s->a_blue);
	printf("c.x: %f, v.x: %f\n", ((t_camera *)(s->c->content))->c_x, ((t_camera *)(s->c->content))->c_vx);	
	printf("l.x: %f, l.ratio: %f, l.red: %d\n", ((t_light *)(s->l->content))->l_x, ((t_light *)(s->l->content))->l_r, ((t_light *)(s->l->content))->l_red);		
	printf("sp.x: %f, sp.d: %f, sp.red: %d\n", ((t_sphere *)(s->sp->content))->sp_x, ((t_sphere *)(s->sp->content))->sp_d, ((t_sphere *)(s->sp->content))->sp_red);	
	printf("pl.x: %f, pl.vx: %f, pl.red: %d\n", ((t_plane *)(s->pl->content))->pl_x, ((t_plane *)(s->pl->content))->pl_vx, ((t_plane *)(s->pl->content))->pl_red);
	printf("sq.x: %f, sq.vx: %f, sq.red: %d\n", ((t_square *)(s->sq->content))->sq_x, ((t_square *)(s->sq->content))->sq_vx, ((t_square *)(s->sq->content))->sq_red);
	printf("tr.x1: %f, tr.x2: %f, tr.red: %d\n", ((t_triangle *)(s->tr->content))->tr_x1, ((t_triangle *)(s->tr->content))->tr_x1, ((t_triangle *)(s->tr->content))->tr_red);	
/*	
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, s->r_x, s->r_y, "miniRT");
    mlx_key_hook(win_ptr, key_press, param);
	mlx_loop(mlx_ptr);
*/	
/*
	finish = clock();
	total_time = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("Total time: %f seconds/n", total_time); 
*/
	free_all(s, 0);
	return (0);
}