/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgysella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 16:05:58 by hgysella          #+#    #+#             */
/*   Updated: 2019/03/05 12:37:03 by hgysella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			is_sort(int *a, int l)
{
	int		i;

	i = 0;
	while (i < l - 1)
	{
		if (a[i] > a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int			is_revsort(int *a, int l)
{
	int		i;

	i = 0;
	while (i < l - 1)
	{
		if (a[i] < a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

long long	calc_mid(int *a, int l)
{
	int			i;
	long long	mid;

	mid = 0;
	i = 0;
	while (i < l)
	{
		mid += a[i];
		i++;
	}
	return (mid / i);
}

int			check_mid(int *a, int l, long long mid)
{
	int i;

	i = 0;
	while (i < l)
	{
		if (a[i] < mid)
			return (1);
		i++;
	}
	return (0);
}
