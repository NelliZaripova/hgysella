/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgysella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 14:18:33 by hgysella          #+#    #+#             */
/*   Updated: 2018/11/30 18:15:30 by hgysella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	unsigned int	i;
	unsigned int	l;
	char			*new;

	new = NULL;
	if (s == NULL)
		return (NULL);
	i = 0;
	l = ft_strlen(s);
	new = (char*)malloc(sizeof(char) * (l + 1));
	if (new == NULL)
		return (NULL);
	while (s[i])
	{
		new[i] = f(s[i]);
		i++;
	}
	new[i] = '\0';
	return (new);
}
