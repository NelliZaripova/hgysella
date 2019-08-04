/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srcs1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 12:35:30 by jritchie          #+#    #+#             */
/*   Updated: 2019/08/02 20:11:39 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		error_clear_exit(t_asm *ch, char *msg, int clear, char *s)
{
	if (ch)
	{
		if (clear == 1)
			ft_printf("%s\t[%s]\tСтрока:%d\n", msg, s, ch->row);
		else
			ft_printf("%s\t[%s]\n", msg, s);
		free(ch);
	}
	else
		ft_printf("%w%s%s\n", STDERR, msg, s);
	exit(0);
}

int			get_arg_r(t_asm *ch, char *line, int i)
{
	int		res;

	res = 0;
	if (line && line[0] == 'r'
		&& check_num(ch, line + 1) == 1
		&& (ch->args[i][0] = ft_atol(line + 1)) > 0
		&& ch->args[i][0] <= 16)
	{
		ch->args[i][1] = 1;
		ch->args[i][2] = 1;
		res = 1;
	}
	return (res);
}

int			get_arg_d(t_asm *ch, char *line, int i)
{
	int		res;
	int		pr_nb;

	res = 0;
	if (line[0] == DIRECT_CHAR)
	{
		if (line[1] == LABEL_CHAR && check_inderect(ch, line + 1))
		{
			ch->args[i][0] = get_addr(ch, line + 2);
			ch->args[i][0] = ch->args[i][0] - ch->tmp;
			ch->args[i][1] = 2;
			ch->args[i][2] = REG_SIZE;
			res = 1;
		}
		else if (check_num(ch, line + 1))
		{
			line++;
			ch->args[i][0] = pratoui(&line, &pr_nb);
			ch->args[i][1] = 2;
			ch->args[i][2] = REG_SIZE;
			res = (pr_nb < 0) ? 0 : 1;
		}
	}
	return (res);
}

int			get_arg_i(t_asm *ch, char *line, int i)
{
	int		res;
	int		pr_nb;

	res = 0;
	if (line[0] == LABEL_CHAR)
	{
		ch->args[i][0] = get_addr(ch, line + 1);
		ch->args[i][0] = ch->args[i][0] - ch->tmp;
		ch->args[i][1] = 3;
		ch->args[i][2] = IND_SIZE;
		res = 1;
	}
	else if (check_num(ch, line))
	{
		ch->args[i][0] = pratoui(&line, &pr_nb);
		ch->args[i][1] = 3;
		ch->args[i][2] = IND_SIZE;
		res = (pr_nb < 0) ? 0 : 1;
	}
	return (res);
}

int			check_non_last(char *line)
{
	char	*tmp;

	tmp = strtrim_(line);
	if (tmp && tmp[0] == SEPARATOR_CHAR)
	{
		ft_strdel(&tmp);
		return (1);
	}
	ft_strdel(&tmp);
	return (0);
}
