/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetrinew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgysella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 15:11:54 by hgysella          #+#    #+#             */
/*   Updated: 2018/12/15 17:44:19 by hgysella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_list_push_back(t_elem **begin_list, t_elem *new)
{
	t_elem	*q;

	if (!(*begin_list))
		*begin_list = new;
	else
	{
		q = *begin_list;
		while (q->next)
			q = q->next;
		q->next = new;
	}
}

t_elem	*ft_tetrinew(char *str, char sym, int x, int y)
{
	t_elem	*elem;

	if (!(elem = (t_elem *)malloc(sizeof(t_elem))))
		return (NULL);
	elem->str = str;
	elem->sym = sym;
	elem->x = x;
	elem->y = y;
	elem->next = NULL;
	return (elem);
}

void	ft_free_tetrik(t_elem **tetrik)
{
	t_elem	*q;
	t_elem	*t;

	q = *tetrik;
	while (q)
	{
		t = q;
		q = q->next;
		ft_strdel(&(t->str));
		free(t);
	}
}
