/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusujio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 16:10:03 by gusujio           #+#    #+#             */
/*   Updated: 2019/12/02 16:10:14 by gusujio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void     sortar2(t_mas **ar, int n) // сортиорвка масива
{
	int i;
	int j;
	int tmp;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n - i)
		{
			if ((*ar)[j].x > (*ar)[j + 1].x)
			{
				tmp = (*ar)[j].x;
				(*ar)[j] = (*ar)[j + 1];
				(*ar)[j + 1].x = tmp;
			}
			j++;
		}
		i++;
	}
}

t_mas*     crar(t_stack **ili)
{
	t_mas   *ar;
	int     i;

	ar = (t_mas*)malloc((*ili)->size_a * (int)sizeof(t_mas));
	i = 0;
	while (i < (*ili)->tail_a)
	{
		ar[i].x = (*ili)->mas_a[i];
		i++;
	}
	sortar2(&ar, (*ili)->size_a - 1);
	return (ar);
}

void	push_swap(t_stack *ili)
{
	t_mas *ar;

	ar = crar(&ili);
	if (ili->size_a <= 3)
	{
		till3(&ili);
	}
	else if(ili->size_a > 3 && ili->size_a <= 5)
	{
		till5(ar, &ili);
	}
	else if(ili->size_a > 5)
	{
		sort1(ar, &ili);
		sort2(ar, &ili);
	}
}

int		main(int argc, char** argv)
{
	t_stack *ili;

	if (argc > 1)
	{
		push_swap(ili = ft_error(argc, argv));
	}
}