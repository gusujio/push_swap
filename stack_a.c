/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusujio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 22:22:24 by gusujio           #+#    #+#             */
/*   Updated: 2019/11/29 22:22:26 by gusujio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void shr_a(t_stack **st) //двигает вправо
{
	int i;
	int b;
	int b2;

	i = (*st)->head_a;
	b2 = (*st)->mas_a[(*st)->head_a];
	while (i <= (*st)->tail_a)
	{
		b = (*st)->mas_a[i + 1];
		(*st)->mas_a[i + 1] = b2;
		b2 = b;
		i++;
	}
}

void sa(t_stack **st)
{
	int b;

	if ((*st)->size_a > 1)
	{
		b = (*st)->mas_a[(*st)->head_a];
		(*st)->mas_a[(*st)->head_a] = (*st)->mas_a[(*st)->head_a + 1];
		(*st)->mas_a[(*st)->head_a + 1] = b;
	}
}

void pa(t_stack **st)
{
	if ((*st)->size_b)
	{
		shr_a(st);
		(*st)->mas_a[(*st)->head_a] = (*st)->mas_b[(*st)->head_b];
		(*st)->mas_b[(*st)->head_b] = 0;
		(*st)->size_a++;
		(*st)->tail_a++;
		(*st)->head_b++;
		(*st)->size_b--;
	}
}

void ra(t_stack **st)
{
	int a;
	int i;
	int b;
	int b2;

	a = (*st)->mas_a[(*st)->head_a];
	i = (*st)->tail_a;
	b2 = (*st)->mas_a[i];
	while ((*st)->head_a < i)
	{
		b = (*st)->mas_a[i - 1];
		(*st)->mas_a[i - 1] = b2;
		b2 = b;
		i--;
	}
	(*st)->mas_a[(*st)->tail_a] = a;
}

void rra(t_stack **st)
{
	int b;

	b = (*st)->mas_a[(*st)->tail_a];
	shr_a(st);
	(*st)->mas_a[(*st)->head_a] = b;
	(*st)->mas_a[(*st)->tail_a + 1] = 0;
}