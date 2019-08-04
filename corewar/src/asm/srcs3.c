/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srcs3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 18:16:27 by jritchie          #+#    #+#             */
/*   Updated: 2019/08/02 20:51:57 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	open_file(t_asm *ch, char *file)
{
	if ((ch->fd = open(file, O_RDONLY)) == -1 ||\
			read(ch->fd, 0, 0) == -1)
		error_clear_exit(NULL, "Error to open file ", 0, NULL);
}

int		check_simple_comment(char *line)
{
	int		i;
	char	*tmp;

	tmp = strtrim_(line);
	i = 0;
	if (tmp && tmp[i] != COMMENT_CHAR &&\
				tmp[i] != COMMENT_CHAR_ALT && ft_strlen(tmp))
	{
		ft_strdel(&tmp);
		return (0);
	}
	ft_strdel(&tmp);
	return (1);
}

int		check_symbol(int c)
{
	int		i;

	i = 0;
	while (LABEL_CHARS[i])
		if (LABEL_CHARS[i++] == c)
			return (1);
	return (0);
}

int		is_label_correct(t_asm *ch, char *line)
{
	int		i;

	i = -1;
	while (line[++i])
		if ((unsigned char)line[i] == 0xff)
			return (-1);
		else if (line[i] == LABEL_CHAR && i > 0)
		{
			ft_strncpy(ch->labels[ch->labels_count].label, line, i);
			ch->labels[ch->labels_count].label[i] = '\0';
			ch->labels[ch->labels_count].num = ch->labels_count;
			ch->labels_count++;
			return (0);
		}
	return (0);
}

int		check_inderect(t_asm *ch, char *line)
{
	int		i;

	i = 0;
	while (line[i] && line[i] != SEPARATOR_CHAR
		&& line[i] != ' ' && line[i] != '\t')
		i++;
	if ((line[i] && ch->last && !check_simple_comment(line + i))
		|| (!ch->last && !check_non_last(line + i)) || i == 0)
		error_clear_exit(ch, "Error", 1, NULL);
	return (1);
}
