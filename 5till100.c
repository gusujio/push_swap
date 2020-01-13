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

#include "checker.h"

int stack(int *h, int x, const int *ar, int *j)
{
	int t;
	int i;

	i = *h;
	t = *h - 20;
	while (i > t && i >= 0)
	{
		if (ar[*h] == x)
		{
			(*j)++;
			if (*j == 20)
				*h -= 20;
			return (1);
		}
		i--;
	}
	return (0);
}

void sort1(int *ar, t_stack **ili)
{
	int j;
	int h;

	h = (*ili)->size_a;
	j = 0;
	while ((*ili)->size_a > 0)
	{
		if (stack(&h, (*ili)->mas_a[(*ili)->head_a].num, ar, &j))
		{
			if (j == 20)
				j = 0;
			pb(ili);
		}
		else
			ra(ili);
	}
}

void sort2(t_stack **ili)
{

}
