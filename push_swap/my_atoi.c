/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgysella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 11:56:31 by hgysella          #+#    #+#             */
/*   Updated: 2019/03/05 17:46:53 by hgysella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_rez(int r, int f, int *a)
{
	if (((unsigned int)r > 2147483647 && f == 1) ||\
			((unsigned int)r > 2147483648 && f == -1))
	{
		free(a);
		return (0);
	}
	return (1);
}

int	is_valid_arr(int *a, int k)
{
	int	i;
	int	j;

	i = 0;
	while (i < k)
	{
		j = i + 1;
		while (j < k)
		{
			if (a[i] == a[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_isspase(char c)
{
	if (c == ' ' || c == '\n' || c == '\v' ||
		c == '\f' || c == '\r' || c == '\t')
		return (1);
	return (0);
}

int	*my_atoi_m(char **s, int k)
{
	int	rez;
	int	f;
	int	i;
	int	*a;

	a = (int*)malloc(sizeof(int) * k);
	while (k > 0)
	{
		i = 0;
		rez = 0;
		while (s[k][i] && ft_isspase(s[k][i]))
			i++;
		f = (s[k][i] == '-') ? -1 : 1;
		i += (s[k][i] && (s[k][i] == '+' || s[k][i] == '-')) ? 1 : 0;
		while (s[k][i] >= '0' && s[k][i] <= '9')
		{
			rez = rez * 10 + s[k][i] - '0';
			if (!(is_valid_rez(rez, f, a)))
				return (NULL);
			i++;
		}
		a[k - 1] = f * rez;
		k--;
	}
	return (a);
}

int	*my_atoi_o(char *str, int k)
{
	int		rez;
	int		f;
	int		i;
	int		j;
	int		*a;

	i = 0;
	j = 0;
	a = (int*)malloc(sizeof(int) * k);
	while (j < k)
	{
		rez = 0;
		while (str[i] && ft_isspase(str[i]))
			i++;
		f = (str[i] == '-') ? -1 : 1;
		i += (str[i] && (str[i] == '+' || str[i] == '-')) ? 1 : 0;
		while (str[i] >= '0' && str[i] <= '9')
		{
			rez = rez * 10 + str[i++] - '0';
			if (!(is_valid_rez(rez, f, a)))
				return (NULL);
		}
		a[j++] = f * rez;
	}
	return (a);
}
