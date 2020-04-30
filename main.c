/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Amber <Amber@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 12:39:50 by Amber             #+#    #+#             */
/*   Updated: 2020/04/30 15:38:23 by Amber            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/miniRT.h"
#include <stdio.h>

int		main()
{
	void	*mlx_ptr;
	void	*win_ptr = NULL;
	
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1000, 500, "miniRT");
//	if (win_ptr)
//		printf("Amber: %p", win_ptr);

	if (win_ptr)
		mlx_loop(mlx_ptr);
	return (0);
}
