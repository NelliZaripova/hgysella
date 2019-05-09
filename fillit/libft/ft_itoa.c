/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgysella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 12:10:24 by hgysella          #+#    #+#             */
/*   Updated: 2018/12/01 13:51:30 by hgysella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		ft_len(int div)
{
	int	k;

	k = 0;
	if (div == -2147483648)
		return (11);
	if (div <= 0)
	{
		div *= -1;
		k++;
	}
	while (div > 0)
	{
		k++;
		div = div / 10;
	}
	return (k);
}

static	char	*ft_negative(int n, int k, char *s)
{
	if (n == -2147483648)
	{
		s[k] = 8 + '0';
		n = -214748364;
		k--;
	}
	if (n == 0)
		s[0] = '0';
	else
	{
		s[0] = '-';
		n *= -1;
		while (k > 0)
		{
			s[k] = n % 10 + '0';
			n = n / 10;
			k--;
		}
	}
	return (s);
}

char			*ft_itoa(int n)
{
	char	*s;
	int		k;

	k = ft_len(n);
	s = (char*)malloc(sizeof(char) * (k + 1));
	if (s == NULL)
		return (NULL);
	s[k] = '\0';
	if (n <= 0)
		s = ft_negative(n, k - 1, s);
	else
		while (k-- > 0)
		{
			s[k] = n % 10 + '0';
			n = n / 10;
		}
	return (s);
}
