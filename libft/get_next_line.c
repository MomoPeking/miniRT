/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Amber <Amber@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 18:03:08 by qdang             #+#    #+#             */
/*   Updated: 2020/05/07 16:05:55 by Amber            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line_2(const int fd, char **save, char **line)
{
	char	*temp;
	int		i;

	i = 0;
	while (save[fd][i] && save[fd][i] != '\n')
		i++;
	*line = ft_strsub(save[fd], 0, i);
	if (save[fd][i] == 0)
	{
		save[fd] = NULL;
		free(save[fd]);
	}
	else
	{
		temp = ft_strsub(save[fd], i + 1, ft_strlen(save[fd]) - i - 1);
		free(save[fd]);
		save[fd] = ft_strdup(temp);
		free(temp);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*save[FD_SIZE];
	char		buff[BUFF_SIZE + 1];
	char		*temp;
	int			i;

	if (fd < 0 || line == NULL || read(fd, buff, 0) < 0)
		return (-1);	
	while ((i = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[i] = '\0';
		if (save[fd] == NULL)
			save[fd] = ft_strnew(0);
		temp = ft_strjoin(save[fd], buff);
		free(save[fd]);
		save[fd] = ft_strdup(temp);
		free(temp);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (i == 0 && (save[fd] == NULL || !save[fd][0]))
		return (0);
	return (get_next_line_2(fd, save, line));
}
