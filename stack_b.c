/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusujio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 12:28:17 by gusujio           #+#    #+#             */
/*   Updated: 2019/11/30 12:28:19 by gusujio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void shr_b(t_stack **st) //двигает вправо
{
	int i;
	int b;
	int b2;

	i = (*st)->head_b;
	b2 = (*st)->mas_b[(*st)->head_b];
	while (i <= (*st)->tail_b)
	{
		b = (*st)->mas_b[i + 1];
		(*st)->mas_b[i + 1] = b2;
		b2 = b;
		i++;
	}
}

void sb(t_stack **st)
{
	int b;

	if ((*st)->size_b > 1)
	{
		b = (*st)->mas_b[(*st)->head_b];
		(*st)->mas_b[(*st)->head_b] = (*st)->mas_b[(*st)->head_b + 1];
		(*st)->mas_b[(*st)->head_b + 1] = b;
	}
}



void pb(t_stack **st)
{
	if ((*st)->size_a)
	{
		shr_b(st);
		(*st)->mas_b[(*st)->head_b] = (*st)->mas_a[(*st)->head_a];
		(*st)->mas_a[(*st)->head_a] = 0;
		(*st)->size_b++;
		(*st)->tail_b++;
		(*st)->head_a++;
		(*st)->size_a--;
	}
}

void rb(t_stack **st)
{
	int a;
	int i;
	int b;
	int b2;

	a = (*st)->mas_b[(*st)->head_b];
	i = (*st)->tail_b;
	b2 = (*st)->mas_b[i];
	while ((*st)->head_b < i)
	{
		b = (*st)->mas_b[i - 1];
		(*st)->mas_b[i - 1] = b2;
		b2 = b;
		i--;
	}
	(*st)->mas_b[(*st)->tail_b] = a;
}

void rrb(t_stack **st)
{
	int b;

	b = (*st)->mas_b[(*st)->tail_b];
	shr_b(st);
	(*st)->mas_b[(*st)->head_b] = b;
	(*st)->mas_b[(*st)->tail_b + 1] = 0;
}