/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srcs15.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 12:01:32 by dspider-          #+#    #+#             */
/*   Updated: 2019/08/01 21:23:37 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	my_answer(t_asm *ch, char *msg)
{
	ft_printf("Problem with %s\n", msg);
	close(ch->fd);
	exit(0);
}

void	test(t_asm *ch, char *text, int i, int sl)
{
	if (ft_strstr(text, ".name") == NULL || ft_strstr(text, ".comment") == NULL)
		my_answer(ch, "lack of comment or name");
	while (*text)
	{
		if (*text == '#')
			sl = 1;
		else if (*text == ',')
			i = 0;
		else if (i >= 0)
			if (ft_isalnum(*text) == 1)
				i++;
		if (*text == '\n')
		{
			if (i == 0 && sl == 0)
				my_answer(ch, "comma in the end of sense");
			else
				i = -1;
			sl = 0;
		}
		text++;
	}
}

int		check_for_commands(char *text, int i)
{
	while (*text)
	{
		if (*text == '\"')
			i++;
		text++;
		if (i == 4)
			break ;
	}
	if (ft_strstr(text, "live") != NULL || ft_strstr(text, "aff")
	!= NULL || ft_strstr(text, "lldi") != NULL)
		return (1);
	if (ft_strstr(text, "lfork") != NULL || ft_strstr(text, "xor")
	!= NULL || ft_strstr(text, "sub") != NULL)
		return (1);
	if (ft_strstr(text, "sti") != NULL || ft_strstr(text, "lldi")
	!= NULL || ft_strstr(text, "ldi") != NULL)
		return (1);
	if (ft_strstr(text, "lld") != NULL || ft_strstr(text, "and")
	!= NULL || ft_strstr(text, "zjmp") != NULL)
		return (1);
	if (ft_strstr(text, "ld") != NULL || ft_strstr(text, "or") != NULL)
		return (1);
	if (ft_strstr(text, "add") != NULL || ft_strstr(text, "st") != NULL)
		return (1);
	return (-1);
}

void	length(t_asm *ch, char *text)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (i < 4 && *text)
	{
		if (*text == '\"' && (i == 1 || i == 3))
		{
			if (len > PROG_NAME_LENGTH && i == 1)
				my_answer(ch, "lenght of name");
			if (len > COMMENT_LENGTH && i == 3)
				my_answer(ch, "lenght of devis");
			if (i == 3)
				return ;
			len = 0;
			i++;
		}
		if (i == 1 || i == 3)
			len++;
		if (*text == '\"' && (i == 0 || i == 2))
			i++;
		text++;
	}
}

void	additional_check(t_asm *ch, char *file, int i)
{
	char	*full_text;
	char	str[5 + 1];
	char	*tmp;

	open_file(ch, file);
	full_text = NULL;
	while ((i = read(ch->fd, str, 5)) > 0)
	{
		tmp = NULL;
		str[i] = '\0';
		tmp = strjoin_(full_text, str);
		ft_strdel(&full_text);
		full_text = strdup_(tmp);
		ft_strdel(&tmp);
	}
	if (i < 0)
		my_answer(ch, "opening file");
	if (i == 0 && full_text == NULL)
		my_answer(ch, "lack of text");
	test(ch, full_text, -1, 0);
	length(ch, full_text);
	if (check_for_commands(full_text, 0) < 0)
		my_answer(ch, "lack of commands");
	ft_strdel(&full_text);
	close(ch->fd);
}
