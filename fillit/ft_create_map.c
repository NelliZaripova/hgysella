/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgysella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 12:07:00 by hgysella          #+#    #+#             */
/*   Updated: 2018/12/19 14:08:55 by hgysella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void
	set_elem(t_elem *tetrik, char **matrix, int width, int height)
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
				matrix[height + y][width + x] = tetrik->sym;
			y++;
		}
		x++;
	}
}

static int
	check_place(t_elem *tetrik, char **matrix, int x, int y)
{
	int i;
	int j;

	i = 0;
	while (i < tetrik->y)
	{
		j = 0;
		while (j < tetrik->x)
		{
			if (tetrik->str[i * 5 + j] == '#' && matrix[y + i][x + j] != '.')
				return (0);
			j++;
		}
		i++;
	}
	set_elem(tetrik, matrix, x, y);
	return (1);
}

static int
	ft_fillit(char **matrix, t_elem *tetrik, int size)
{
	int x;
	int y;

	if (tetrik == NULL)
		return (1);
	y = 0;
	while (y < size - tetrik->y + 1)
	{
		x = 0;
		while (x < size - tetrik->x + 1)
		{
			if (check_place(tetrik, matrix, x, y))
			{
				if (ft_fillit(matrix, tetrik->next, size))
					return (1);
				else
					del_elem(tetrik, matrix, x, y);
			}
			x++;
		}
		y++;
	}
	return (0);
}

static int
	ft_matrix_size(t_elem *list)
{
	int	n;
	int	size;

	size = 2;
	n = 0;
	while (list)
	{
		n++;
		list = list->next;
	}
	n *= 4;
	while (size * size < n)
		size++;
	return (size);
}

void
	ft_create_map(t_elem *tetrik)
{
	int		size;
	char	**matrix;

	size = ft_matrix_size(tetrik);
	if (!(matrix = ft_matrixnew(size, size)))
		return ;
	while (ft_fillit(matrix, tetrik, size) == 0)
	{
		ft_matrixdel(matrix);
		size++;
		matrix = ft_matrixnew(size, size);
	}
	ft_print(matrix, size, size);
	ft_matrixdel(matrix);
}
