/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disasm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 22:25:54 by jritchie          #+#    #+#             */
/*   Updated: 2019/08/02 18:45:25 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disasm_func.h"
#include "asm_op.h"

void		start(int fd, char *argv)
{
	int		fd_out;
	int		i;
	char	*name;

	name = ft_strnew(ft_strlen(argv) - 2);
	ft_memmove(name, argv, ft_strlen(argv) - 2);
	i = ft_strrchr(name, '.') - name;
	name[i + 1] = 's';
	name[i + 2] = '\0';
	fd_out = open(name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	lseek(fd, 0, SEEK_SET);
	disasm_func(fd, fd_out);
	ft_putstr("Writing output program to ");
	ft_putendl(name);
	close(fd);
	close(fd_out);
	ft_strdel(&name);
}

void		champ_err(int value, int f, char *str, int expect)
{
	if (f == 1)
		ft_printf("%w\033[1;31mCan't open %s\n", STDERR, str);
	else if (f == 2)
		ft_printf("%w\033[1;31m%s is not champion\n", STDERR, str);
	else if (f == 5)
		ft_printf("%w\033[1;31m%s has invalid operations\n", STDERR, str);
	else if (value == -1)
		ft_printf("%w\033[1;31mCan't read %s\n", STDERR, str);
	else if (value < expect)
		ft_printf("%w\033[1;31mInvalid champion size\n", STDERR, str);
	else
		return ;
	exit(0);
}

int			disasm(char *fn)
{
	int		fd;
	t_param	p;

	get_champ(fn, &p, 1);
	fd = open(fn, O_RDONLY);
	start(fd, fn);
	return (0);
}
