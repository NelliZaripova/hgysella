/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list_op.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgysella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 11:24:42 by hgysella          #+#    #+#             */
/*   Updated: 2019/03/05 17:06:51 by hgysella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_check	*create_list_op(char *op, int i)
{
	t_check	*list_op;

	list_op = (t_check *)malloc(sizeof(t_check));
	list_op->name = op;
	list_op->ind_op = i;
	list_op->next = NULL;
	return (list_op);
}

void	list_push_back(t_check **list, t_check *new)
{
	t_check	*q;

	if (!(*list))
		*list = new;
	else
	{
		q = *list;
		while (q->next)
			q = q->next;
		q->next = new;
	}
}

void	list_del(t_check *list)
{
	t_check *t;

	while (list)
	{
		t = list;
		list = list->next;
		free(t->name);
		free(t);
	}
	free(list);
}

void	set_null(int *a, int l)
{
	int	i;

	i = 0;
	while (i < l)
	{
		a[i] = 0;
		i++;
	}
}

void	del_tsort(t_sort *str)
{
	free(str->op);
	free(str->a);
	free(str->b);
	free(str->ka);
	free(str);
}
