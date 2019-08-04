/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ltoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 20:19:57 by jritchie          #+#    #+#             */
/*   Updated: 2019/08/01 21:26:24 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "disasm_func.h"
#include "asm.h"

static int		nbrlen_base(unsigned long long int nbr, int base)
{
	int			i;

	i = 0;
	if (!nbr)
		return (1);
	while (nbr)
	{
		nbr /= base;
		i++;
	}
	return (i);
}

char			*ltoa_base(long long int n, int base)
{
	char		*hex;
	int			i;
	int			l;
	char		*res;

	if (n == (-9223372036854775807 - 1) && base == 10)
		return (strdup_("-9223372036854775808"));
	if (n == 0)
		return (strdup_("0"));
	i = 0;
	hex = "0123456789abcdef";
	l = nbrlen_base(ft_abs(n), base) + ((n < 0 && base == 10) ? 1 : 0);
	res = ft_strnew(l);
	(n < 0 && base == 10) ? res[i++] = '-' : (0);
	n < 0 ? n *= -1 : (0);
	while (n)
	{
		res[--l] = hex[n % base];
		n /= base;
	}
	return (res);
}
