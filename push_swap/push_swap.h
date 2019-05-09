/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgysella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 18:58:36 by hgysella          #+#    #+#             */
/*   Updated: 2019/03/06 17:58:18 by hgysella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_check
{
	char			*name;
	int				ind_op;
	struct s_check	*next;
}					t_check;

typedef struct		s_sort
{
	int				*a;
	int				*b;
	int				la;
	int				lb;
	int				k_op;
	char			*op;
	int				*ka;
	int				lka;
}					t_sort;

int					count_arg(char *av);
int					*fill_a(int ac, char **av);
int					*my_atoi_m(char **str, int k);
int					*my_atoi_o(char *str, int j);
int					is_valid_arr(int *a, int k);
int					ft_isspase(char c);
int					is_sort(int *a, int l);
t_sort				*create_str(int k, int *a);
void				set_null(int *a, int l);
void				swap_a(t_sort *str);
void				swap_b(t_sort *str);
int					sort_three_a(t_sort *str);
int					sort_three(t_sort *str);
int					sort_two(t_sort *str);
void				rotate_a(t_sort *str);
void				rev_rotate_a(t_sort *str);
void				rotate_b(t_sort *str);
void				rev_rotate_b(t_sort *str);
void				push_a(t_sort *str);
void				push_b(t_sort *str);
int					is_sort(int *a, int l);
int					is_revsort(int *a, int l);
long long			calc_mid(int *a, int l);
int					check_mid(int *a, int l, long long mid);
int					sort_arr(t_sort *str);
int					bubble_sort(t_sort *str);
void				ft_print_arr(int *a, int k);
void				record_str(t_sort *str, char *s);
int					optim_rb(t_sort *str, char *s);
int					optim_ra(t_sort *str, char *s);
int					optim_p(t_sort *str, char *s);
int					optim_s(t_sort *str, char *s);
void				del_tsort(t_sort *str);
t_check				*create_list_op(char *op, int i);
void				list_push_back(t_check **list, t_check *new);
void				list_del(t_check *list);
void				del_tsort(t_sort *str);

#endif
