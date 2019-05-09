/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgysella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 14:35:33 by hgysella          #+#    #+#             */
/*   Updated: 2018/12/19 14:03:34 by hgysella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void
	ft_xy(int *x, int *y, char *str)
{
	int		i;

	i = 0;
	while (str[i + 1])
	{
		if (i < 15 && str[i] == '#' && str[i + 1] == '#' \
				&& str[i + 5] == '#' && str[i + 6] == '#')
		{
			*x = 2;
			*y = 2;
			break ;
		}
		if (str[i] == '#' && str[i + 1] == '#')
			(*x)++;
		if (i < 16 && str[i] == '#' && str[i + 5] == '#')
			(*y)++;
		i++;
	}
}

static t_elem
	*ft_str_to_list(char *s, char sym)
{
	t_elem	*elem;
	char	*str;
	int		x;
	int		y;

	x = 1;
	y = 1;
	if (!(str = ft_strsub(s, 0, 20)))
		return (NULL);
	ft_xy(&x, &y, str);
	str = ft_swap_str(str);
	if (!(elem = ft_tetrinew(str, sym, x, y)))
	{
		ft_strdel(&str);
		return (NULL);
	}
	return (elem);
}

static int
	count_touches(char *s)
{
	int	t;
	int i;

	i = 0;
	t = 0;
	while (s[i])
	{
		if (s[i] == '#')
		{
			if (s[i + 1] == '#')
				t++;
			if (i > 0 && s[i - 1] == '#')
				t++;
			if (i < 16 && s[i + 5] == '#')
				t++;
			if (i > 4 && s[i - 5] == '#')
				t++;
		}
		i++;
	}
	if (t == 6 || t == 8)
		return (1);
	return (0);
}

static int
	ft_valid_sym(char *s)
{
	int	sym;
	int	n;
	int	t;
	int	i;

	sym = 0;
	n = 0;
	t = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '#')
			sym++;
		else if (s[i] == '.')
			t++;
		else if (s[i] == '\n')
			n++;
		else
			return (0);
		i++;
	}
	if (sym == 4 && t == 12 && n > 3 && n < 6 && s[0] != '\n')
		return (1);
	return (0);
}

t_elem
	*ft_read_map(int fd)
{
	char	buff[22];
	int		ret;
	char	sym;
	t_elem	*tetrik;
	t_elem	*head;

	head = NULL;
	sym = 'A';
	while ((ret = read(fd, buff, 21)) > 0)
	{
		buff[ret] = '\0';
		if (ret < 20 || !ft_valid_sym(buff) || !count_touches(buff))
			return (NULL);
		if (!(tetrik = ft_str_to_list(buff, sym)))
			return (NULL);
		sym++;
		ft_list_push_back(&head, tetrik);
	}
	if (buff[20] == '\n' || sym > 'Z')
	{
		ft_free_tetrik(&head);
		return (NULL);
	}
	else
		return (head);
}
