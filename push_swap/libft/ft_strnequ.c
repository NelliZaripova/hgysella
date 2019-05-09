/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgysella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:24:23 by hgysella          #+#    #+#             */
/*   Updated: 2018/12/02 13:42:35 by hgysella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	if (!n)
		return (1);
	while (s1[i] && s2[i] && i < n)
	{
		if (s1[i] == s2[i])
			i++;
		else
			return (0);
	}
	if ((s1[i] && !s2[i]) || (!s1[i] && s2[i]))
		return (0);
	return (1);
}
