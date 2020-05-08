/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Amber <Amber@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 09:50:56 by Amber             #+#    #+#             */
/*   Updated: 2020/05/07 16:33:24 by Amber            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

void	error_info(unsigned char e)
{
	if (e == 1)
		ft_putstr("Please input a scene.\n");
	else if (e == 2)
		ft_putstr("Flag usage: --save\n");
	else if (e == 3)
		ft_putstr("Unable to open the scene.\n");
	else if (e == 4)
		ft_putstr("Unable to read the scene.\n");
	else if (e == 5)
		ft_putstr("The scene is invalid.\n");
	else if (e == 6)
		ft_putstr("The resolution info is invalid.\n");
	else if (e == 7)
		ft_putstr("The ambient lightning info is invalid.\n");
	else if (e == 8)
		ft_putstr("The camera info is invalid.\n");
	else if (e == 9)
		ft_putstr("The light info is invalid.\n");
	else if (e == 10)
		ft_putstr("The sphere info is invalid.\n");
	else if (e == 11)
		ft_putstr("The plane info is invalid.\n");
	else if (e == 12)
		ft_putstr("The square info is invalid.\n");
	else if (e == 13)
		ft_putstr("The cylinder info is invalid.\n");
	else if (e == 14)
		ft_putstr("The triangle info is invalid.\n");					
	exit(0);
}