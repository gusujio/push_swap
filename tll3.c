/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tll3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusujio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 15:35:55 by gusujio           #+#    #+#             */
/*   Updated: 2020/01/14 15:35:59 by gusujio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int min3(t_stack *ili)
{
	int i;
	int j;
	int f;

	j = ili->mas_a[ili->head_a];
	i = ili->head_a;
	f = ili->head_a;
	while (i < ili->tail_a)
	{
		if (j > ili->mas_a[i])
		{
			j = ili->mas_a[i];
			f = i;
		}
		i++;
	}
	return (f);
}

void till3(t_stack **ili)
{
	int l;

	if ((*ili)->size_a >= 2)
	{
		if ((*ili)->mas_a[(*ili)->head_a] > (*ili)->mas_a[(*ili)->head_a + 1]
		|| (*ili)->mas_a[(*ili)->head_a + 1] > (*ili)->mas_a[(*ili)->head_a + 2])
		{
			ft_printf("sa\n");
			sa(ili);
		}
	}
	l = min3(*ili);
	fa(l, ili);
}
