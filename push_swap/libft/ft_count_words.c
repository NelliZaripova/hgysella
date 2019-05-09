/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgysella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 21:27:18 by hgysella          #+#    #+#             */
/*   Updated: 2018/12/01 16:15:20 by hgysella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

int		ft_count_words(const char *s, char c)
{
	size_t	i;
	size_t	k;
	size_t	n;

	i = 0;
	k = 0;
	n = 0;
	if (s[n] == '\0')
		return (0);
	while (s[n])
		n++;
	if (s[0] != c)
		k++;
	while (i < n - 1)
	{
		if (s[i] == c && s[i + 1] != c)
			k++;
		i++;
	}
	return (k);
}
