/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgysella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 19:17:28 by hgysella          #+#    #+#             */
/*   Updated: 2018/12/19 14:01:38 by hgysella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void
	ft_swap(char *a, char *b)
{
	char c;

	c = *a;
	*a = *b;
	*b = c;
}

static void
	ft_swap_row(char *s)
{
	int i;

	while (1)
	{
		if (s[0] == '.' && s[1] == '.' &&
			s[2] == '.' && s[3] == '.')
		{
			i = 0;
			while (i < 15)
			{
				ft_swap(&s[i], &s[i + 5]);
				ft_swap(&s[i + 1], &s[i + 6]);
				ft_swap(&s[i + 2], &s[i + 7]);
				ft_swap(&s[i + 3], &s[i + 8]);
				i += 5;
			}
		}
		else
			break ;
	}
}

static void
	ft_swap_col(char *s)
{
	int i;

	i = 0;
	while (1)
	{
		if (s[0] == '.' && s[5] == '.' &&
			s[10] == '.' && s[15] == '.')
		{
			i = 0;
			while (i < 3)
			{
				ft_swap(&s[i], &s[i + 1]);
				ft_swap(&s[i + 5], &s[i + 6]);
				ft_swap(&s[i + 10], &s[i + 11]);
				ft_swap(&s[i + 15], &s[i + 16]);
				i++;
			}
		}
		else
			break ;
	}
}

char
	*ft_swap_str(char *s)
{
	ft_swap_col(s);
	ft_swap_row(s);
	return (s);
}
