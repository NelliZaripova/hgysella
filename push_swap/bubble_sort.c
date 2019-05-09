/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buble_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgysella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 14:49:28 by hgysella          #+#    #+#             */
/*   Updated: 2019/03/04 17:59:33 by hgysella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		search_min(int *a, int len)
{
	int		i;
	int		min;

	i = 0;
	min = a[i];
	while (i < len)
	{
		min = (a[i] < min) ? a[i] : min;
		i++;
	}
	return (min);
}

int		search_max(int *a, int len)
{
	int		i;
	int		max;

	i = 0;
	max = a[i];
	while (i < len)
	{
		max = (a[i] > max) ? a[i] : max;
		i++;
	}
	return (max);
}

int		bubble_sort_a(t_sort *str, int la)
{
	int		min;
	int		i;

	i = 0;
	if (str->lb == la)
		return (1);
	min = search_min(str->a, str->la);
	while (str->a[i] != min)
		i++;
	if (i < str->la / 2)
		while (i)
		{
			rotate_a(str);
			i--;
		}
	else
		while (str->la - i)
		{
			rev_rotate_a(str);
			i++;
		}
	push_b(str);
	bubble_sort_a(str, la);
	return (1);
}

int		bubble_sort(t_sort *str)
{
	if (bubble_sort_a(str, str->la - 1))
		while (str->lb > 0)
			push_a(str);
	return (1);
}
