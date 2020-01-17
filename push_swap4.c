/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusujio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 17:32:26 by gusujio           #+#    #+#             */
/*   Updated: 2019/12/13 17:32:28 by gusujio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void fb(int x1, t_stack **ili)//на первое самым быстром способом в a
{
	if (x1 - (*ili)->head_b < (*ili)->size_b - (x1 - (*ili)->head_b))//влево быстрее, чем вправо
		ihb(ili, (*ili)->mas_b[x1]);
	else
		ihbr(ili, (*ili)->mas_b[x1]);
}

void fa(int x1, t_stack **ili)//на первое самым быстром способом в a
{
	if (x1 - (*ili)->head_a < (*ili)->size_a - (x1 - (*ili)->head_a))//влево быстрее, чем вправо
		iha(ili, (*ili)->mas_a[x1]);
	else
		ihar(ili, (*ili)->mas_a[x1]);
}

void iha(t_stack **ili, int x)//сдивагать влево пока x не станет перовой в a
{
	while ((*ili)->mas_a[(*ili)->head_a] != x)
	{
		ft_printf("ra\n");
		ra(ili);
	}
}
void ihbr(t_stack **ili, int x)//сдивагать вправо пока x не станет перовой в b
{
	while ((*ili)->mas_b[(*ili)->head_b] != x)
	{
		ft_printf("rrb\n");
		rrb(ili);
	}
}

void ihar(t_stack **ili, int x)//сдивагать вправо пока x не станет перовой
{

	while ((*ili)->mas_a[(*ili)->head_a] != x)
	{
		ft_printf("rra\n");
		rra(ili);
	}
}

void ihb(t_stack **ili, int x)//сдивагать влево пока x не станет перовой
{
	while ((*ili)->mas_b[(*ili)->head_b] != x)
	{
		ft_printf("rb\n");
		rb(ili);
	}
}