/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw_validator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 16:47:07 by jwinthei          #+#    #+#             */
/*   Updated: 2019/08/02 16:27:33 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw.h"

static void		fill_champ(t_cw *cw, char *file_name, uint8_t id_champ, int arg)
{
	int			fd;
	uint8_t		head[HEADER_SIZE + 1];
	uint8_t		exec[CHAMP_MAX_SIZE * 2 + 1];

	if (add_champ(cw, id_champ))
		cw_out(cw, ft_printf("%w\033[1;31mPlayer# %u is already exist ",\
					STDERR, id_champ) +\
					ft_printf("%w[arg#: %d]\033[0m\n", STDERR, arg), 0);
	if ((fd = open(file_name, O_RDONLY)) < 0)
		cw_out(cw, ft_printf("%w\033[1;31mFile %s: permission denied\033[0m\n",\
												STDERR, file_name), 0);
	if (read(fd, head, HEADER_SIZE) <= 0)
		cw_out(cw, ft_printf("%w\033[1;31mFile %s: read error\033[0m\n",\
												STDERR, file_name), 0);
	if ((cw->champ[IN(cw->num_of_champs)]->head.prog_size =\
							read(fd, exec, CHAMP_MAX_SIZE * 2 + 1)) <= 0)
		cw_out(cw, ft_printf("%w\033[1;31mFile %s: read error\033[0m\n",\
												STDERR, file_name), 0);
	if (cw->champ[IN(cw->num_of_champs)]->head.prog_size > CHAMP_MAX_SIZE)
		cw_out(cw, ft_printf("%w\033[1;31mFile %s: %s %u > %s(%u)%s",\
			STDERR, file_name, "too large executable code:",\
			cw->champ[IN(cw->num_of_champs)]->head.prog_size,\
			"CHAMP_MAX_SIZE", CHAMP_MAX_SIZE, "\033[0m\n"), 0);
	cw_fill_head(cw, head, exec, IN(cw->num_of_champs));
	close(fd);
}

static int		args_analis(char **av, t_cw *cw, int i, int mode)
{
	cw->step = 0;
	if (mode)
	{
		if (i == mode ||\
			((cw->step = ft_atoi(av[i])) < 1 || MAX_PLAYERS < cw->step))
			cw_out(cw, ft_printf("%w\033[1;31m%s %s. %s(%u) [arg#: %d]\n",\
				STDERR, "Invalid player number:",\
				(i == mode) ? NULL : av[i],\
				"N must be from 1 to MAX_PLAYERS", MAX_PLAYERS,\
				i), av[0]);
		if (++i == mode)
			cw_out(cw, ft_printf("%w\033[1;31m%s %s [arg#: %d]\n",
					STDERR, "Invalid file name:", NULL, i), av[0]);
	}
	if (cw_strrstr(av[i], ".cor"))
		fill_champ(cw, av[i], cw->step, i);
	else
		cw_out(cw, ft_printf("%w\033[1;31m%s %s [arg#: %d]\n",
				STDERR, "Invalid file name:", av[i], i), av[0]);
	cw->step = 0;
	return (i);
}

static void		flg_analis_2(char **av, t_cw *cw, int i, size_t j)
{
	cw->err = 0;
	if (av[i][j] == 'a' && !av[i][j + 1] && (cw->err = 1) && !cw->f.lg.af)
		cw->f.lag |= AF;
	else if (av[i][j] == 'd' && !av[i][j + 1] && (cw->err = 1) && !cw->f.lg.dbg)
		cw->f.lag |= DEBUG;
	else if (av[i][j] == 'd' && av[i][j + 1] == 'c' && !av[i][j + 2] &&\
										(cw->err = 1) && !cw->f.lg.dbg_c)
		cw->f.lag |= DEBUG_C;
	else if (av[i][j] == 'd' && av[i][j + 1] == 'r' && !av[i][j + 2] &&\
										(cw->err = 1) && !cw->f.lg.dbg_r)
		cw->f.lag |= DEBUG_R;
	else if (av[i][j] == 'd' && av[i][j + 1] == 'f' && !av[i][j + 2] &&\
					(cw->err = 1) && (cw->f.lag & (DEBUG_F)) != (DEBUG_F))
		cw->f.lag |= DEBUG_F;
	else if (av[i][j] == 'v' && !av[i][j + 1] && (cw->err = 1) && !cw->f.lg.vs)
		cw->f.lag |= VISU;
	else if (cw->err)
		cw_out(cw, ft_printf("%w\033[1;31mFlag '%s' %s [arg#: %d]\n",\
						STDERR, &av[i][j], "is already exist", i), av[0]);
	else
		cw_out(cw, ft_printf("%w\033[1;31mInvalid flag: %s [arg#: %d]\n",\
											STDERR, &av[i][j], i), av[0]);
	if (cw->f.lg.vs && cw->f.lg.dbg)
		cw_out(cw, ft_printf("%w\033[1;31mVisual flag 'v' %s [arg#: %d]\n",\
						STDERR, "and Debug flags do not stack", i), av[0]);
}

static int		flg_analis_1(int ac, char **av, t_cw *cw, int i)
{
	size_t		j;

	j = cw->lives;
	if (av[i][j] == 's' && !av[i][j + 1] && !cw->f.lg.prg_strt)
	{
		if (++i == ac || ((cw->f.lag |= PRG_STRT) &&\
			!(cw->start_cycle = ft_atoi(av[i])) && av[i][0] != '0'))
			cw_out(cw, ft_printf("%w\033[1;31m%s %s [arg#: %d]\n",\
							STDERR, "Invalid cycle value:",\
								(i == ac) ? NULL : av[i], i), av[0]);
	}
	else if (av[i][j] == 'e' && !av[i][j + 1] && !cw->f.lg.prg_end)
	{
		if (++i == ac || ((cw->f.lag |= PRG_END) &&\
			!(cw->end_cycle = ft_atoi(av[i])) && av[i][0] != '0'))
			cw_out(cw, ft_printf("%w\033[1;31m%s %s [arg#: %d]\n",\
							STDERR, "Invalid cycle value:",\
								(i == ac) ? NULL : av[i], i), av[0]);
	}
	else
		flg_analis_2(av, cw, i, j);
	cw->lives = 0;
	return (i);
}

void			cw_flg_analis(int ac, char **av, t_cw *cw, int i)
{
	size_t		j;

	while (++i < ac)
	{
		j = 0;
		while (av[i][j] == ' ' || av[i][j] == '\t' || av[i][j] == '\n')
			j++;
		if (av[i][j++] != '-')
			i = args_analis(av, cw, i, 0);
		else if (av[i][j] == 'n' && !av[i][j + 1])
			i = args_analis(av, cw, i + 1, ac);
		else if (!cw->f.lg.dump && (!ft_strcmp(&av[i][j], "dump") ||\
									!ft_strcmp(&av[i][j], "dump64")))
		{
			cw->f.lag |= (av[i][j + 4]) ? DUMP64 : DUMP;
			if (++i == ac ||\
					(!(cw->cycle_to_dump = ft_atoi(av[i])) && av[i][0] != '0'))
				cw_out(cw, ft_printf("%w\033[1;31m%s %s [arg#: %d]\n",\
											STDERR, "Invalid dump size:",\
										(i == ac) ? NULL : av[i], i), av[0]);
		}
		else if ((cw->lives = j))
			i = flg_analis_1(ac, av, cw, i);
	}
	cw->err = 0;
}
