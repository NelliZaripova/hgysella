/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_b.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgysella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 19:43:58 by hgysella          #+#    #+#             */
/*   Updated: 2019/03/04 19:44:05 by hgysella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_b(t_sort *str)
{
	if (str->lb > 1)
	{
		ft_swap(&str->b[0], &str->b[1]);
		record_str(str, "sb\n");
		str->k_op++;
	}
}

void	rotate_b(t_sort *str)
{
	int	i;

	i = 0;
	while (i < str->lb - 1)
	{
		ft_swap(&str->b[i], &str->b[i + 1]);
		i++;
	}
	record_str(str, "rb\n");
	str->k_op++;
}

void	rev_rotate_b(t_sort *str)
{
	int	i;

	i = str->lb - 1;
	while (i > 0)
	{
		ft_swap(&str->b[i], &str->b[i - 1]);
		i--;
	}
	record_str(str, "rrb\n");
	str->k_op++;
}

void	push_b(t_sort *str)
{
	int	i;

	if (str->la < 1)
		return ;
	str->lb++;
	str->b[str->lb - 1] = str->a[0];
	i = str->lb - 1;
	while (i > 0)
	{
		ft_swap(&str->b[i], &str->b[i - 1]);
		i--;
	}
	i = 0;
	while (i < str->la - 1)
	{
		ft_swap(&str->a[i], &str->a[i + 1]);
		i++;
	}
	str->la--;
	record_str(str, "pb\n");
	str->k_op++;
}
