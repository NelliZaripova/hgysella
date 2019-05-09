/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_a.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgysella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 19:44:08 by hgysella          #+#    #+#             */
/*   Updated: 2019/03/04 19:44:17 by hgysella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_sort *str)
{
	if (str->la > 1)
	{
		ft_swap(&str->a[0], &str->a[1]);
		record_str(str, "sa\n");
		str->k_op++;
	}
}

void	rotate_a(t_sort *str)
{
	int	i;

	i = 0;
	while (i < str->la - 1)
	{
		ft_swap(&str->a[i], &str->a[i + 1]);
		i++;
	}
	record_str(str, "ra\n");
	str->k_op++;
}

void	rev_rotate_a(t_sort *str)
{
	int	i;

	i = str->la - 1;
	while (i > 0)
	{
		ft_swap(&str->a[i], &str->a[i - 1]);
		i--;
	}
	record_str(str, "rra\n");
	str->k_op++;
}

void	push_a(t_sort *str)
{
	int	i;

	if (str->lb < 1)
		return ;
	str->la++;
	str->a[str->la - 1] = str->b[0];
	i = str->la - 1;
	while (i > 0)
	{
		ft_swap(&str->a[i], &str->a[i - 1]);
		i--;
	}
	i = 0;
	while (i < str->lb - 1)
	{
		ft_swap(&str->b[i], &str->b[i + 1]);
		i++;
	}
	str->lb--;
	record_str(str, "pa\n");
	str->k_op++;
}

int		sort_three_a(t_sort *str)
{
	if (str->a[0] < str->a[1] && str->a[1] < str->a[2])
		return (1);
	else if (str->a[0] < str->a[1] && str->a[1] > str->a[2]\
				&& str->a[0] < str->a[2])
	{
		rev_rotate_a(str);
		swap_a(str);
	}
	else if (str->a[0] > str->a[1] && str->a[1] < str->a[2]\
				&& str->a[0] < str->a[2])
		swap_a(str);
	else if (str->a[0] < str->a[1] && str->a[1] > str->a[2])
		rev_rotate_a(str);
	else if (str->a[0] > str->a[1] && str->a[1] > str->a[2])
	{
		rotate_a(str);
		swap_a(str);
	}
	else if (str->a[0] > str->a[1] && str->a[1] < str->a[2])
		rotate_a(str);
	return (0);
}
