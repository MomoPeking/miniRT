/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Amber <Amber@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 09:54:56 by Amber             #+#    #+#             */
/*   Updated: 2020/05/07 16:43:20 by Amber            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

void	free_split(char **str)
{
	int		i;

	i = 0;
	if (str)
	{
		while (str[i] != NULL)
		{
			free(str[i]);
			i++;	
		}
		free(str);
	}
}

int		free_temp(char **split, void *content, int rt)
{
	if (split != NULL)
		free_split(split);
	if (content != NULL)
		free(content);
	return (rt);
}

void	free_all(t_info *s, int i)
{
	ft_lstclear(&(s->c), free);
	ft_lstclear(&(s->l), free);
	ft_lstclear(&(s->sp), free);
	ft_lstclear(&(s->pl), free);
	ft_lstclear(&(s->sq), free);
	ft_lstclear(&(s->cy), free);
	ft_lstclear(&(s->tr), free);
	free(s);
//	system ("leaks miniRT");	
	if (i != 0)
		error_info(i);
}