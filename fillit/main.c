/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgysella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 12:53:52 by hgysella          #+#    #+#             */
/*   Updated: 2018/12/19 14:04:36 by hgysella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int		fd;
	t_elem	*elem;

	if (argc != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0 || !(elem = ft_read_map(fd)))
	{
		ft_putstr("error\n");
		return (1);
	}
	ft_create_map(elem);
	ft_free_tetrik(&elem);
	close(fd);
	return (0);
}
