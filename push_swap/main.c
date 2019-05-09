/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgysella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 10:56:55 by hgysella          #+#    #+#             */
/*   Updated: 2019/03/06 18:01:36 by hgysella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int ac, char **av)
{
	t_sort	*str;
	int		*a;
	int		k;

	str = NULL;
	if (ac < 2)
		return (0);
	if (!(a = fill_a(ac, av)))
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	k = (ac == 2) ? count_arg(av[1]) : ac - 1;
	str = create_str(k, a);
	(str->la == 3) ? sort_three_a(str) : sort_arr(str);
	ft_printf("%s", str->op);
	del_tsort(str);
	return (0);
}
