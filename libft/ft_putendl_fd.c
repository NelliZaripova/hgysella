/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgysella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:01:02 by hgysella          #+#    #+#             */
/*   Updated: 2018/11/30 18:54:52 by hgysella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	size_t	i;

	i = 0;
	if (fd == -1)
		return ;
	if (s != NULL)
	{
		while (s[i])
		{
			write(fd, &s[i], 1);
			i++;
		}
		ft_putchar_fd('\n', fd);
	}
}
