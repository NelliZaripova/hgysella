/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgysella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 15:52:07 by hgysella          #+#    #+#             */
/*   Updated: 2019/03/05 17:02:09 by hgysella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>

size_t	index_search(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

void	ft_read_fd(char **s, int fd)
{
	int		ret;
	char	buff[BUFF_SIZE + 1];
	char	*tfd;

	if (!*s)
		*s = ft_strnew(BUFF_SIZE);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		tfd = ft_strjoin(*s, buff);
		if (!tfd)
		{
			free(tfd);
			ft_strdel(s);
			break ;
		}
		ft_strdel(s);
		*s = tfd;
		if (ft_strchr(*s, '\n') != NULL)
			break ;
	}
}

int		get_next_line(const int fd, char **line)
{
	static char		**str;
	size_t			i;
	char			*tmp;

	if (fd < 0 || !line || fd >= FD_MAX || read(fd, NULL, 0) < 0)
		return (-1);
	if (!str)
		str = (char **)malloc(sizeof(char *) * (FD_MAX + 1));
	ft_read_fd(&str[fd], fd);
	if (str[fd])
	{
		i = index_search(str[fd]);
		if (i == 0 && str[fd][0] != '\n')
			return (0);
		*line = ft_strsub(str[fd], 0, i);
		if (i == ft_strlen(str[fd]))
			tmp = ft_strdup("");
		else
			tmp = ft_strsub(str[fd], i + 1, ft_strlen(str[fd]));
		ft_strdel(&str[fd]);
		str[fd] = tmp;
		return (1);
	}
	return (-1);
}
