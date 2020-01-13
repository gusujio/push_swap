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

void fa(t_spisok *x1, t_stack **ili)//на первое самым быстром способом в a
{
	if (x1->indexi < (*ili)->tail_a - x1->indexi)//влево быстрее, чем вправо
		iha(ili, x1->num);
	else
		ihar(ili, x1->num);
}

void fb(t_spisok *x1, t_stack **ili)//на первое самым быстром способом в a
{
	if (x1->indexi < (*ili)->tail_b - x1->indexi)//влево быстрее, чем вправо
		ihb(ili, x1->num);
	else
		ihbr(ili, x1->num);
}

void ta(t_spisok *x1, t_stack **ili)//на последнее место самым быстром способом в a
{
	if (x1->indexi < (*ili)->tail_a - x1->indexi)//влево быстрее, чем вправо
		ita(ili, x1->num);
	else
		itar(ili, x1->num);
}

void tb(t_spisok *x1, t_stack **ili)//на последнее место самым быстром способом в b
{
	if (x1->indexi < (*ili)->tail_b - x1->indexi)//влево быстрее, чем вправо
		itb(ili, x1->num);
	else
		itbr(ili, x1->num);
}

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

void iha(t_stack **ili, int x)//сдивагать влево пока x не станет перовой в a
{
	while ((*ili)->mas_a[(*ili)->head_a].num != x)
	{
		ft_printf("rra\n");
		rra(ili);
	}
}
void ihb(t_stack **ili, int x)//сдивагать влево пока x не станет перовой в b
{
	while ((*ili)->mas_b[(*ili)->head_b].num != x)
	{
		ft_printf("rrb\n");
		rrb(ili);
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

void ihbr(t_stack **ili, int x)//сдивагать вправо пока x не станет перовой
{
	while ((*ili)->mas_b[(*ili)->head_b].num != x)
	{
		ft_printf("rb\n");
		rb(ili);
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

void itb(t_stack **ili, int x)//сдивагать влево пока x не станет последней
{
	while ((*ili)->mas_b[(*ili)->tail_b].num != x)
	{
		ft_printf("rb\n");
		rb(ili);
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

void itbr(t_stack **ili, int x)//сдивагать вправо пока x не станет последней
{
	while ((*ili)->mas_b[(*ili)->tail_b - 1].num != x)
	{
		ft_printf("rrb\n");
		rrb(ili);
	}
}

