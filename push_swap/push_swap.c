/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgysella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 12:35:44 by hgysella          #+#    #+#             */
/*   Updated: 2019/03/05 14:11:11 by hgysella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			sort_a(t_sort *str, long long mid)
{
	int	i;

	i = 0;
	if (is_sort(str->a, str->la) || str->la == 3)
		return (1);
	if (!check_mid(str->a, str->la, mid))
		mid = calc_mid(str->a, str->la);
	while (check_mid(str->a, str->la, mid) && str->la > 3 &&\
			!is_sort(str->a, str->la))
	{
		i += (str->a[0] < mid) ? 1 : 0;
		if (str->a[0] < mid)
			push_b(str);
		else
		{
			rotate_a(str);
			if (str->b[0] < mid / 2 && str->lb < str->la)
				rotate_b(str);
		}
	}
	str->ka[str->lka - 1] = i;
	str->lka--;
	sort_a(str, mid);
	return (str->lka);
}

int			push_sort(t_sort *str, int k)
{
	while (k > 0)
	{
		push_a(str);
		sort_three(str);
		k--;
	}
	return (0);
}

void		sort_rev_b(t_sort *str, int k, int l)
{
	while (k--)
		push_a(str);
	str->ka[l] = 0;
}

int			sort_b(t_sort *str, int k, int l, long long mid)
{
	int i;
	int	j;

	if (k <= 3)
		str->ka[l] = 0;
	while (k > 3)
	{
		i = 0;
		j = 0;
		mid = calc_mid(str->b, k);
		while (i + j < k)
		{
			(str->b[0] > mid) ? i++ : j++;
			(str->b[0] > mid) ? push_a(str) : rotate_b(str);
		}
		str->ka[l] = j;
		l--;
		k = i;
		while (j--)
			rev_rotate_b(str);
		while (i--)
			push_b(str);
	}
	push_sort(str, k);
	return (k);
}

int			sort_arr(t_sort *str)
{
	long long	mid;
	int			k;
	int			l;

	if (is_revsort(str->a, str->la) && str->lb == 0 && str->la < 100)
		bubble_sort(str);
	if (is_sort(str->a, str->la) && str->lb == 0)
		return (1);
	mid = calc_mid(str->a, str->la);
	sort_a(str, mid);
	if (str->la == 3)
		sort_three_a(str);
	while (str->lb)
	{
		l = 0;
		while (str->ka[l] == 0 && str->lb)
			l++;
		k = str->ka[l];
		(is_revsort(str->b, k) && k > 3) ? sort_rev_b(str, k, l) :\
			sort_b(str, k, l, mid);
	}
	return (0);
}
