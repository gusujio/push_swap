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

void till_xa(t_stack **ili, int x)//кидает в b элементы до x.
{
	while ((*ili)->mas_a[(*ili)->head_a].num != x)
	{
		(*ili)->mas_a[(*ili)->head_a].a_b = 1;
		ft_printf("pb\n");
		pb(ili);
	}
}

void till_xb(t_stack **ili, int x)//кидает в a элементы до x.
{
	while ((*ili)->mas_b[(*ili)->head_b].num != x)
	{
		(*ili)->mas_a[(*ili)->head_a].a_b = 0;
		ft_printf("pa\n");
		pa(ili);
	}
	(*ili)->mas_b[(*ili)->head_b].a_b = 0;
	ft_printf("pa\n");
	pa(ili);
}

void iha(t_stack **ili, int x)//сдивагать влево пока x не станет перовой
{
	while ((*ili)->mas_a[(*ili)->head_a].num != x)
	{
		ft_printf("rra\n");
		rra(ili);
	}
}

void ihar(t_stack **ili, int x)//сдивагать вправо пока x не станет перовой
{
	while ((*ili)->mas_a[(*ili)->head_a].num != x)
	{
		ft_printf("ra\n");
		ra(ili);
	}
}

void ihb(t_stack **ili, int x)//сдивагать пока x не станет перовой
{
	while ((*ili)->mas_b[(*ili)->head_b].num != x)
	{
		ft_printf("rra\n");
		rrb(ili);
	}
}

void ita(t_stack **ili, int x)//сдивагать влево пока x не станет последней
{
	while ((*ili)->mas_a[(*ili)->tail_a - 1].num != x)
	{
		ft_printf("ra\n");
		ra(ili);
	}
}

void itar(t_stack **ili, int x)//сдивагать вправо пока x не станет последней
{
	while ((*ili)->mas_a[(*ili)->tail_a - 1].num != x)
	{
		ft_printf("rra\n");
		rra(ili);
	}
}

void itb(t_stack **ili, int x)//сдивагать пока x не станет последней
{
	while ((*ili)->mas_b[(*ili)->tail_b].num != x)
	{
		ft_printf("ra\n");
		rb(ili);
	}
}

int l_o_r(t_stack *ili, int x) // 1 - left, 0 - right
{
	return ((ili->tail_a - ili->head_a) / 2 > x);
}

