/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 09:13:15 by jritchie          #+#    #+#             */
/*   Updated: 2019/08/02 20:55:32 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			asm_err(t_asm **ch, int prnt)
{
	free(*ch);
	ch = NULL;
	exit(prnt);
}

static void		usage(t_asm **ch, char *file_name, int prnt)
{
	ft_printf("\033[1;30mUsage: %s [-d] <sourcefile.s>\n%s",\
	file_name, "        -d      : Disassembler flag\033[0m\n");
	free(*ch);
	ch = NULL;
	exit(prnt);
}

static int		flg_analis(int ac, char **av, t_asm **ch, int i)
{
	int			count;
	int			retv;
	size_t		j;

	count = 0;
	while (++i < ac)
	{
		j = 0;
		while (av[i][j] == ' ' || av[i][j] == '\t' || av[i][j] == '\n')
			j++;
		if (av[i][j++] != '-')
			continue ;
		if (av[i][j] == 'd' && !av[i][j + 1] && (retv = i))
			count++;
		else
			usage(ch, av[0], ft_printf("%w\033[1;31mInvalid flag %s\n",\
									STDERR, &av[i][j]));
	}
	if (count > 1)
		usage(ch, av[0], ft_printf("%w\033[1;31mFlag 'd' %s\n",\
									STDERR, "is already exist"));
	else if (count)
		return (retv > 1 ? 1 : 2);
	return (0);
}

int				main(int ac, char **av)
{
	t_asm		*ch;
	int			i;

	i = 0;
	if (!(ch = (t_asm *)malloc(sizeof(t_asm))))
		return (ft_printf("%w\033[1;31mMalloc Error\n", STDERR));
	asm_init(ch);
	if (ac == 1)
		usage(&ch, av[0], 0);
	if ((i = flg_analis(ac, av, &ch, i)))
		disasm(av[i]);
	else
	{
		read_champ(av[1], ch);
		write_bytes(av[1], ch);
	}
	free(ch);
	return (0);
}
