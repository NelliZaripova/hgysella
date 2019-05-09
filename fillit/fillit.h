/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgysella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 13:53:34 by hgysella          #+#    #+#             */
/*   Updated: 2018/12/19 13:59:48 by hgysella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct	s_elem
{
	char			*str;
	char			sym;
	int				x;
	int				y;
	struct s_elem	*next;
}				t_elem;

t_elem			*ft_read_map(int	fd);
char			*ft_swap_str(char *s);
void			ft_create_map(t_elem *tetrik);

char			**ft_matrixnew(size_t size_x, size_t size_y);
void			del_elem(t_elem *tetrik, char **matrix, int width, int height);
void			ft_matrixdel(char **s);

t_elem			*ft_tetrinew(char *str, char sym, int x, int y);
void			ft_list_push_back(t_elem **begin_list, t_elem *new);
void			ft_free_tetrik(t_elem **tetrik);

void			ft_print(char **arr, int x, int y);

#endif
