/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5till100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusujio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 21:10:50 by gusujio           #+#    #+#             */
/*   Updated: 2020/01/13 21:10:53 by gusujio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <zconf.h>
#include "checker.h"

void dpop(int x, int y, const t_mas *ar)
{
	printf("ar = \n");
	while (x < y)
	{
		printf("x = %d w = %d\n", ar[x].x, ar[x].w);
		x++;
	}
}

void dpop2(t_stack **ili)
{
	printf("ili a= \n");
	int x = (*ili)->head_a;
	int y = (*ili)->tail_a;
	while (x < y)
	{
		printf("%d ",  (*ili)->mas_a[x]);
		x++;
	}
	printf("\n");
}

void dpop3(t_stack **ili)
{
	printf("ili b = \n");
	int x = (*ili)->head_b;
	int y = (*ili)->tail_b;
	while (x < y)
	{
		printf("%d ",  (*ili)->mas_b[x]);
		x++;
	}
	printf("\n");
}

int     equally(t_stack **ili, int x)
{
	int i;

	i = (*ili)->head_b;
	while (i <= (*ili)->tail_b)
	{
		if ((*ili)->mas_b[i] == x)
			return (i);
		i++;
	}
	return (-1);
}

int stack(t_stack **ili, t_mas *ar, int k)
{
	int t;
	int h;
	t_mas sa;

	h = ((*ili)->size_b / k) * k;
	t = h + k;
	sa.w = 2147483647;
	while (h < t && h <= (*ili)->size_a + (*ili)->size_b)
	{
		if (sa.w > ar[h].w && ar[h].i != -1)
			sa = ar[h];
		h++;
	}
	return (sa.i);
}

void  weight(t_stack **ili, t_mas **ar, int k)
{
	int t;
	int h;
	int i;

	h = ((*ili)->size_b / k) * k;
	t = h + k;
	while (h < t && h <= (*ili)->size_a + (*ili)->size_b)
	{
		i = aequally(ili, (*ar)[h].x) - (*ili)->head_a;
		if ( i == -1)
		{
			printf("error\n");
			exit(0);
		}
		if (i > (*ili)->size_a - i)
			(*ar)[h].w = (*ili)->size_a - i;
		else
			(*ar)[h].w = i;
		(*ar)[h].i = i + (*ili)->head_a;
		h++;
	}

}

void sort1(t_mas *ar, t_stack **ili)
{
	int k;
	int i;

	k = (*ili)->size_a > 100 ? (*ili)->size_a / 11 : (*ili)->size_a / 5;
	dpop2(ili);
	while ((*ili)->size_a > 0)
	{
		weight(ili, &ar, k);
		i = stack(ili, ar, k);
		fa(i, ili);
		printf("pb\n");
		pb(ili);
	}
}

void sort2(t_mas *ar, t_stack **ili)
{
	int i;
	int l;

	i = (*ili)->size_b;
	while (--i >= 0)
	{
		l = equally(ili, ar[i].x);
		fb(l, ili);
		printf("pa\n");
		pa(ili);
	}
}
