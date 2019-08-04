/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srcs2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 22:25:54 by jritchie          #+#    #+#             */
/*   Updated: 2019/08/02 19:54:34 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				check_num(t_asm *ch, char *line)
{
	int		i;

	i = 0;
	while (line[i] && line[i] != SEPARATOR_CHAR
		&& line[i] != ' ' && line[i] != '\t')
	{
		if (i != 0 || line[i] != '-')
			if (line[i] < '0' || line[i] > '9')
				return (0);
		i++;
	}
	if ((line[i] && ((ch->last && !check_simple_comment(line + i))
		|| (!ch->last && !check_non_last(line + i)))) || i == 0)
		error_clear_exit(ch, "Error", 1, &line[i]);
	return (1);
}

int				get_args(t_asm *ch, char *line, int args, int i)
{
	int		res;
	char	*tmp;

	tmp = strtrim_(line);
	res = 0;
	if (args == 3 || args == 5 || args == 6 || args == 7)
		res = get_arg_i(ch, tmp, i);
	if (!res && (args == 1 || args == 4 || args == 5 || args == 7))
		res = get_arg_r(ch, tmp, i);
	if (!res && (args == 2 || args == 4 || args == 6 || args == 7))
		res = get_arg_d(ch, tmp, i);
	if (res == 0)
	{
		ft_strdel(&tmp);
		error_clear_exit(ch, "Error", 1, line);
	}
	ft_strdel(&tmp);
	return (res);
}

unsigned char	get_byte(unsigned int a, int num)
{
	if (num == 0)
		return (a % 256);
	if (num == 1)
		return ((a / 256) % 256);
	if (num == 2)
		return ((a / (256 * 256)) % 256);
	if (num == 3)
		return ((a / (256 * 256 * 256)));
	return (-1);
}

int				get_addr(t_asm *ch, char *line)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (line[i] && line[i] != SEPARATOR_CHAR
		&& line[i] != ' ' && line[i] != '\t')
		i++;
	j = 0;
	tmp = ft_strncpy((char *)malloc(i + 1), line, i);
	tmp[i] = '\0';
	while (j < ch->labels_count)
	{
		if (ft_strcmp(tmp, ch->labels[j].label) == 0)
		{
			ft_strdel(&tmp);
			return (ch->labels[j].addr);
		}
		j++;
	}
	ft_strdel(&tmp);
	error_clear_exit(ch, "Error", 0, line);
	return (0);
}

int				only_num(char *line)
{
	int		i;

	i = 0;
	while (line[i] && line[i] != SEPARATOR_CHAR)
	{
		if (line[i] < '0' || line[i] > '9')
			return (0);
		i++;
	}
	if (i > 11 || i == 0)
		return (0);
	return (1);
}
