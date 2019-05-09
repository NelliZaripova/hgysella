/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgysella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 11:55:37 by hgysella          #+#    #+#             */
/*   Updated: 2018/12/01 15:07:39 by hgysella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

static char	*ft_write(const char *s, char c, size_t *i)
{
	size_t	j;
	char	*tmp;

	j = 0;
	while (s[*i] && s[*i] == c)
		(*i)++;
	while (s[*i] && s[*i] != c)
	{
		j++;
		(*i)++;
	}
	if (!(tmp = (char*)malloc(sizeof(char) * (j + 1))))
		return (NULL);
	(*i) = (*i) - j;
	j = 0;
	while (s[*i] && s[*i] != c)
	{
		tmp[j] = s[*i];
		(*i)++;
		j++;
	}
	tmp[j] = '\0';
	return (tmp);
}

static void	*ft_free(char **d)
{
	size_t	i;

	i = 0;
	while (d[i])
	{
		ft_strdel(&d[i]);
		i++;
	}
	ft_strdel(d);
	return (d);
}

char		**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	k;
	size_t	j;
	char	**d;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = 0;
	k = ft_count_words(s, c);
	if (!(d = (char**)malloc(sizeof(char*) * (k + 1))))
		return (NULL);
	while (j < k)
	{
		if (!(d[j] = ft_write(s, c, &i)))
			return (ft_free(d));
		j++;
	}
	d[j] = NULL;
	return (d);
}
