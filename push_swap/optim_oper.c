/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_arr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgysella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 18:12:43 by hgysella          #+#    #+#             */
/*   Updated: 2019/03/06 17:53:47 by hgysella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		optim_rb(t_sort *str, char *s)
{
	char	*t;
	int		l;

	l = ft_strlen(str->op);
	if (ft_strcmp(s, "rb\n") == 0 && l > 3)
	{
		if (str->op[l - 2] == 'a' && str->op[l - 3] == 'r' &&\
				str->op[l - 4] == '\n')
		{
			t = ft_strsub(str->op, 0, l - 3);
			free(str->op);
			str->op = ft_strjoin(t, "rr\n");
			free(t);
			return (1);
		}
		else if (str->op[l - 2] == 'b' && str->op[l - 3] == 'r' &&\
				str->op[l - 4] == 'r' && l > 4)
		{
			t = ft_strsub(str->op, 0, l - 4);
			free(str->op);
			str->op = t;
			return (1);
		}
	}
	return (0);
}

int		optim_ra(t_sort *str, char *s)
{
	char	*t;
	int		l;

	l = ft_strlen(str->op);
	if (ft_strcmp(s, "ra\n") == 0 && l > 3)
	{
		if (str->op[l - 2] == 'b' && str->op[l - 3] == 'r' &&\
				str->op[l - 4] == '\n')
		{
			t = ft_strsub(str->op, 0, l - 3);
			free(str->op);
			str->op = ft_strjoin(t, "rr\n");
			free(t);
			return (1);
		}
		else if (str->op[l - 2] == 'a' && str->op[l - 3] == 'r' &&\
				str->op[l - 4] == 'r' && l > 4)
		{
			t = ft_strsub(str->op, 0, l - 4);
			free(str->op);
			str->op = t;
			return (1);
		}
	}
	return (0);
}

int		optim_p(t_sort *str, char *s)
{
	char	*t;
	int		l;

	l = ft_strlen(str->op);
	if (ft_strcmp(s, "pa\n") == 0 && l > 2)
		if (str->op[l - 2] == 'b' && str->op[l - 3] == 'p')
		{
			t = ft_strsub(str->op, 0, l - 3);
			free(str->op);
			str->op = t;
			return (1);
		}
	if (ft_strcmp(s, "pb\n") == 0 && l > 2)
		if (str->op[l - 2] == 'a' && str->op[l - 3] == 'p')
		{
			t = ft_strsub(str->op, 0, l - 3);
			free(str->op);
			str->op = t;
			return (1);
		}
	return (0);
}

int		optim_s(t_sort *str, char *s)
{
	char	*t;
	int		l;

	l = ft_strlen(str->op);
	if (ft_strcmp(s, "sa\n") == 0 && l > 2)
		if (str->op[l - 2] == 'b' && str->op[l - 3] == 's')
		{
			t = ft_strsub(str->op, 0, l - 3);
			free(str->op);
			str->op = ft_strjoin(t, "ss\n");
			free(t);
			return (1);
		}
	if (ft_strcmp(s, "sb\n") == 0 && l > 2)
		if (str->op[l - 2] == 'a' && str->op[l - 3] == 's')
		{
			t = ft_strsub(str->op, 0, l - 3);
			free(str->op);
			str->op = ft_strjoin(t, "ss\n");
			free(t);
			return (1);
		}
	return (0);
}
