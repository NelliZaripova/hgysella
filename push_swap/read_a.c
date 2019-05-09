/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgysella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 16:07:44 by hgysella          #+#    #+#             */
/*   Updated: 2019/03/05 17:10:22 by hgysella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_sort	*create_str(int k, int *a)
{
	t_sort	*str;

	if (!(str = (t_sort*)malloc(sizeof(t_sort))))
	{
		free(a);
		exit(1);
	}
	str->a = a;
	str->la = k;
	str->lb = 0;
	str->lka = k;
	str->k_op = 0;
	if (!(str->b = (int *)malloc(sizeof(int) * k)) ||\
		!(str->ka = (int *)malloc(sizeof(int) * k)) ||\
		!(str->op = ft_strnew(0)))
	{
		free(str->a);
		free(str);
		exit(1);
	}
	set_null(str->ka, k);
	return (str);
}

int		count_arg(char *av)
{
	int	k;
	int	i;

	k = 0;
	i = 0;
	while (av[i + 1])
	{
		k += (ft_isdigit(av[i]) && ft_isspase(av[i + 1])) ? 1 : 0;
		i++;
	}
	k += ((ft_isdigit(av[i])) && (av[i + 1] == '\0')) ? 1 : 0;
	return (k);
}

int		is_valid_o(char *av)
{
	int	k;

	k = 0;
	while (*av)
	{
		if (ft_isspase(*av))
			av++;
		else if ((*av == '+' || *av == '-') && ft_isdigit(*(av++)))
			av++;
		else if (ft_isdigit(*av))
			av++;
		else
			return (0);
		k++;
	}
	return (k);
}

int		is_valid_m(char **av, int ac)
{
	int	i;
	int j;

	while (ac > 1)
	{
		i = 0;
		j = ac - 1;
		while (av[j][i] && ft_isspase(av[j][i]))
			i++;
		if ((av[j][i] == '+' || av[j][i] == '-') && av[j][i + 1])
			i++;
		while (av[j][i])
		{
			if (!(ft_isdigit(av[j][i])))
				return (0);
			i++;
		}
		ac--;
	}
	return (1);
}

int		*fill_a(int ac, char **av)
{
	int	*a;
	int	k;

	if (ac == 2)
	{
		if (!(is_valid_o(av[1])))
			return (NULL);
		k = count_arg(av[1]);
		if (!(a = my_atoi_o(av[1], k)))
			return (NULL);
	}
	else
	{
		if (!(is_valid_m(av, ac)) || !(a = my_atoi_m(av, ac - 1)))
			return (NULL);
		k = ac - 1;
	}
	if (!is_valid_arr(a, k))
		return (NULL);
	return (a);
}
