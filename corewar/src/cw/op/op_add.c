/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 15:05:41 by jwinthei          #+#    #+#             */
/*   Updated: 2019/07/31 20:44:07 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw.h"

void			op_add(t_cw *cw, size_t i_car)
{
	if (cw_codage_validator(cw, i_car, ADD))
		return ;
	cw->pos = cw->car[i_car]->reg[cw->arg[0]] +\
										cw->car[i_car]->reg[cw->arg[1]];
	cw->car[i_car]->reg[cw->arg[2]] = cw->pos;
	cw->car[i_car]->carry = (cw->pos) ? 0 : 1;
	cw->car[i_car]->pc = PCV(cw->car[i_car]->pc + cw->step);
}
