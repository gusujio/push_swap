/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3till5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusujio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 16:38:04 by gusujio           #+#    #+#             */
/*   Updated: 2020/01/14 16:38:07 by gusujio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int     aequally(t_stack **ili, int x)
{
	int i;

	i = (*ili)->head_a;
	while (i < (*ili)->tail_a)
	{
		if ((*ili)->mas_a[i] == x)
			return (i);
		i++;
	}
	return (-1);
}

void revers(int *x, int *y)
{
	int z;

	z = *x;
	*x = *y;
	*y = z;
}
void till5(t_mas *ar, t_stack **ili)
{
	int min;
	int max;
	int s1;
	int s2;

	min = aequally(ili, ar[0].x);
	max = aequally(ili, ar[(*ili)->tail_a - 1].x);
	s1 = min > (*ili)->tail_a - min ? (*ili)->tail_a - min : min;
	s2 = max > (*ili)->tail_a - max ? (*ili)->tail_a - max : max;
	if (s1 < s2)
		revers(&s1, &s2);
	fa(min, ili);
	printf("pb\n");
	pb(ili);
	max = aequally(ili, ar[(*ili)->tail_a - 1].x);
	fa(max, ili);
	printf("pb\n");
	pb(ili);
	till3(ili);
	pa(ili);
	printf("pa\n"); //  10
	if ((*ili)->mas_a[(*ili)->head_a] == ar[(*ili)->tail_a - (*ili)->head_a].x)
	{
			printf("ra\n");
		ra(ili);
	}
	pa(ili);
	printf("pa\n");
	if ((*ili)->mas_a[(*ili)->head_a] == ar[(*ili)->tail_a - 1].x)
	{
		printf("rra\n");
		rra(ili);
	}
}
