/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwinthei <jwinthei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 15:06:10 by jwinthei          #+#    #+#             */
/*   Updated: 2019/07/31 20:45:30 by jwinthei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw.h"

void			op_ld(t_cw *cw, size_t i_car)
{
	if (cw_codage_validator(cw, i_car, LD))
		return ;
	cw->car[i_car]->reg[cw->arg[1]] = cw->arg[0];
	cw->car[i_car]->carry = (cw->arg[0]) ? 0 : 1;
	cw->car[i_car]->pc = PCV(cw->car[i_car]->pc + cw->step);
}
