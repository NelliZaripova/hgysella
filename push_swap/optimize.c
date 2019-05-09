/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgysella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 17:51:00 by hgysella          #+#    #+#             */
/*   Updated: 2019/03/06 17:56:51 by hgysella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_arr(int *a, int k)
{
	int i;

	i = 0;
	while (i < k)
	{
		ft_printf("%d ", a[i]);
		i++;
	}
}

int		optim_rrr(t_sort *str, char *s)
{
	char	*t;
	int		l;

	l = ft_strlen(str->op);
	if (ft_strcmp(s, "rra\n") == 0 && l > 4)
	{
		if (str->op[l - 2] == 'a' && str->op[l - 3] == 'r' &&\
				str->op[l - 4] == '\n')
		{
			t = ft_strsub(str->op, 0, l - 3);
			free(str->op);
			str->op = t;
			return (1);
		}
	}
	else if (ft_strcmp(s, "rrb\n") == 0 && l > 4)
		if (str->op[l - 2] == 'b' && str->op[l - 3] == 'r' &&\
				str->op[l - 4] == '\n')
		{
			t = ft_strsub(str->op, 0, l - 3);
			free(str->op);
			str->op = t;
			return (1);
		}
	return (0);
}

int		optim_rr(t_sort *str, char *s)
{
	char	*t;
	int		l;

	l = ft_strlen(str->op);
	if (ft_strcmp(s, "rra\n") == 0 && l > 3)
		if (str->op[l - 2] == 'b' && str->op[l - 3] == 'r' &&\
				str->op[l - 4] == 'r')
		{
			t = ft_strsub(str->op, 0, l - 4);
			free(str->op);
			str->op = ft_strjoin(t, "rrr\n");
			free(t);
			return (1);
		}
	if (ft_strcmp(s, "rrb\n") == 0 && l > 3)
		if (str->op[l - 2] == 'a' && str->op[l - 3] == 'p' &&\
				str->op[l - 4] == 'r')
		{
			t = ft_strsub(str->op, 0, l - 4);
			free(str->op);
			str->op = ft_strjoin(t, "rrr\n");
			free(t);
			return (1);
		}
	return (0);
}

void	record_str(t_sort *str, char *s)
{
	char	*tmp;

	if (!(optim_s(str, s)) && !(optim_p(str, s)) && !(optim_rrr(str, s)) &&
		!(optim_rr(str, s)) && !(optim_ra(str, s)) && !(optim_rb(str, s)))
	{
		if (!(tmp = ft_strjoin(str->op, s)))
			exit(1);
		free(str->op);
		str->op = tmp;
	}
}
