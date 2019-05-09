/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgysella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 12:37:43 by hgysella          #+#    #+#             */
/*   Updated: 2019/03/05 12:38:42 by hgysella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_case_four(t_sort *str)
{
	swap_a(str);
	if (str->b[0] < str->b[1])
		swap_b(str);
	rotate_a(str);
	swap_a(str);
	if (str->b[0] < str->b[1])
		swap_b(str);
	rev_rotate_a(str);
	if (str->b[0] < str->b[str->lb - 1])
		rev_rotate_b(str);
}

void	sort_case_three(t_sort *str)
{
	rotate_a(str);
	swap_a(str);
	if (str->b[0] < str->b[1])
		swap_b(str);
	rev_rotate_a(str);
	if (str->b[0] < str->b[str->lb - 1])
		rev_rotate_b(str);
}

void	sort_case_two(t_sort *str)
{
	rotate_a(str);
	swap_a(str);
	if (str->b[0] < str->b[1])
		swap_b(str);
	rev_rotate_a(str);
	if (str->b[0] < str->b[str->lb - 1])
		rev_rotate_b(str);
	swap_a(str);
	if (str->b[0] < str->b[1])
		swap_b(str);
}

void	sort_case_one(t_sort *str)
{
	swap_a(str);
	if (str->b[0] < str->b[1])
		swap_b(str);
	rotate_a(str);
	swap_a(str);
	if (str->b[0] < str->b[1])
		swap_b(str);
	rev_rotate_a(str);
	if (str->b[0] < str->b[str->lb - 1])
		rev_rotate_b(str);
	swap_a(str);
	if (str->b[0] < str->b[1])
		swap_b(str);
}

int		sort_three(t_sort *str)
{
	if (str->a[0] < str->a[1] && str->a[1] < str->a[2])
		return (1);
	else if (str->a[0] > str->a[1] && str->a[1] > str->a[2]\
				&& str->a[0] > str->a[2])
		sort_case_one(str);
	else if (str->a[0] > str->a[1] && str->a[1] < str->a[2]\
				&& str->a[0] < str->a[2])
	{
		swap_a(str);
		if (str->b[0] < str->b[1])
			swap_b(str);
	}
	else if (str->a[0] < str->a[1] && str->a[1] > str->a[2]\
			&& str->a[0] > str->a[2])
		sort_case_two(str);
	else if (str->a[0] < str->a[1] && str->a[1] > str->a[2])
		sort_case_three(str);
	else if (str->a[0] > str->a[1] && str->a[0] > str->a[2]\
			&& str->a[1] < str->a[2])
		sort_case_four(str);
	return (1);
}
