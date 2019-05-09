/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgysella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 09:53:05 by hgysella          #+#    #+#             */
/*   Updated: 2019/03/05 18:55:01 by hgysella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int		valid(char *s)
{
	if (ft_strcmp(s, "sa") == 0)
		return (1);
	else if (ft_strcmp(s, "sb") == 0)
		return (2);
	else if (ft_strcmp(s, "ss") == 0)
		return (3);
	else if (ft_strcmp(s, "pa") == 0)
		return (4);
	else if (ft_strcmp(s, "pb") == 0)
		return (5);
	else if (ft_strcmp(s, "ra") == 0)
		return (6);
	else if (ft_strcmp(s, "rb") == 0)
		return (7);
	else if (ft_strcmp(s, "rra") == 0)
		return (8);
	else if (ft_strcmp(s, "rrb") == 0)
		return (9);
	else if (ft_strcmp(s, "rrr") == 0)
		return (10);
	else if (ft_strcmp(s, "rr") == 0)
		return (11);
	return (0);
}

static void		double_op(t_sort *str, int c)
{
	if (c == 3)
	{
		swap_a(str);
		swap_b(str);
	}
	else if (c == 10)
	{
		rev_rotate_a(str);
		rev_rotate_b(str);
	}
	else if (c == 11)
	{
		rotate_a(str);
		rotate_b(str);
	}
}

static int		checker(t_sort *str, t_check *list)
{
	while (list)
	{
		if (list->ind_op == 1)
			swap_a(str);
		else if (list->ind_op == 2)
			swap_b(str);
		else if (list->ind_op == 4)
			push_a(str);
		else if (list->ind_op == 5)
			push_b(str);
		else if (list->ind_op == 6)
			rotate_a(str);
		else if (list->ind_op == 7)
			rotate_b(str);
		else if (list->ind_op == 8)
			rev_rotate_a(str);
		else if (list->ind_op == 9)
			rev_rotate_b(str);
		else
			double_op(str, list->ind_op);
		list = list->next;
	}
	if (!str->lb && is_sort(str->a, str->la))
		return (1);
	return (0);
}

static t_check	*read_op(t_sort *str, t_check *list)
{
	char	*op;
	int		i;
	t_check *new;

	while (get_next_line(0, &op))
	{
		if (!(i = valid(op)))
		{
			del_tsort(str);
			list_del(list);
			write(2, "Error\n", 6);
			exit(1);
		}
		new = create_list_op(op, i);
		list_push_back(&list, new);
	}
	return (list);
}

int				main(int ac, char **av)
{
	t_sort	*str;
	int		*a;
	int		k;
	t_check	*list;

	list = NULL;
	str = NULL;
	if (ac < 2)
		return (0);
	if (!(a = fill_a(ac, av)))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	k = (ac == 2) ? count_arg(av[1]) : ac - 1;
	str = create_str(k, a);
	list = read_op(str, list);
	if (checker(str, list))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	del_tsort(str);
	list_del(list);
	return (0);
}
