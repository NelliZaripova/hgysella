/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srcs14.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 18:16:27 by jritchie          #+#    #+#             */
/*   Updated: 2019/08/02 20:18:14 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	quote(t_asm *ch, char *str)
{
	size_t	i;
	int		n;
	int		k;

	i = 0;
	n = 0;
	k = 0;
	if (ft_strncmp(str, ".comment", 8) == 0)
	{
		while (i < ft_strlen(str))
		{
			if (n >= 2 && str[i] != ' ')
				k++;
			if (str[i] == '"')
				n++;
			i++;
		}
	}
	if (k > 0)
	{
		close(ch->fd);
		error_clear_exit(ch, "Error with number of comments", 0, NULL);
	}
}

void	check_end_symbol(t_asm *ch)
{
	char	c[2];

	c[0] = 0;
	if (lseek(ch->fd, -1, 2) == -1L)
	{
		close(ch->fd);
		error_clear_exit(ch, "Error. Empty file", 0, NULL);
	}
	if (read(ch->fd, c, 1) <= 0)
	{
		close(ch->fd);
		error_clear_exit(ch, "Error reading", 0, NULL);
	}
	if (c[0] != '\n' && ch->tmp != 0)
	{
		close(ch->fd);
		error_clear_exit(ch,
		"Error with end of file", 0, NULL);
	}
}

uint	pratoui(char **src, int *pr_nb)
{
	short int			sign;
	unsigned long long	number;

	number = 0;
	*pr_nb = 0;
	while (*src[0] == ' ' || *src[0] == '\t' || *src[0] == '\n' ||\
			*src[0] == '\v' || *src[0] == '\f' || *src[0] == '\r')
		src[0]++;
	sign = (*src[0] == '-') ? -1 : 1;
	src[0] += (*src[0] == '-' || *src[0] == '+') ? 1 : 0;
	while ('0' <= *src[0] && *src[0] <= '9')
	{
		*pr_nb += 1;
		number *= 10;
		number += ((int)*src[0] - '0');
		src[0]++;
	}
	*pr_nb = (number > UINT ||\
			(!*pr_nb && (*src[0] < '0' || '9' < *src[0]))) ? -1 : *pr_nb;
	number *= sign;
	return ((*pr_nb < 0) ? 0 : (uint)number);
}
