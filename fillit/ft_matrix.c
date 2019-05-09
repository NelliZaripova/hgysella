/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrixnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgysella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 15:50:42 by hgysella          #+#    #+#             */
/*   Updated: 2018/12/14 12:40:51 by hgysella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void
	ft_matrix_fill(char **matrix, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		matrix[i] = ft_memset(matrix[i], '.', size);
		i++;
	}
}

char
	**ft_matrixnew(size_t size_x, size_t size_y)
{
	char	**s;
	size_t	j;

	j = 0;
	if (size_x == (size_t)(-1) || size_y == (size_t)(-1))
		return (NULL);
	s = (char**)malloc(sizeof(char *) * (size_y + 1));
	if (s == NULL)
		return (NULL);
	while (j < size_y)
	{
		s[j] = (char*)malloc(sizeof(char) * (size_x + 1));
		if (!s[j])
		{
			ft_matrixdel(s);
			return (NULL);
		}
		ft_memset(s[j], (int)'\0', size_x + 1);
		j++;
	}
	s[j] = NULL;
	ft_matrix_fill(s, size_x);
	return (s);
}

void
	del_elem(t_elem *tetrik, char **matrix, int width, int height)
{
	int x;
	int y;

	x = 0;
	while (x < tetrik->x)
	{
		y = 0;
		while (y < tetrik->y)
		{
			if (tetrik->str[y * 5 + x] == '#')
				matrix[height + y][width + x] = '.';
			y++;
		}
		x++;
	}
}

void
	ft_matrixdel(char **s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}
