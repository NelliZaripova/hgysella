/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 15:06:36 by jwinthei          #+#    #+#             */
/*   Updated: 2019/08/01 17:05:09 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw.h"

void			op_lld(t_cw *cw, size_t i_car)
{
	if (cw_codage_validator(cw, i_car, LLD))
		return ;
	cw->car[i_car]->reg[cw->arg[1]] = cw->arg[0];
	cw->car[i_car]->carry = (cw->arg[0]) ? 0 : 1;
	cw->car[i_car]->pc = PCV(cw->car[i_car]->pc + cw->step);
}
