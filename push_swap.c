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

void     sortar2(int **ar, int n) // сортиорвка масива
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
			if ((*ar)[j] > (*ar)[j + 1])
			{
				tmp = (*ar)[j];
				(*ar)[j] = (*ar)[j + 1];
				(*ar)[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

int     equally(struct s_spisok *ar, int len,  int x)
{
	int i;

	i = 0;
	while (i <= len)
	{
		if (ar[i].num == x)
			return (i);
		i++;
	}
	return (-1);
}

int*     crar(t_stack **ili)
{
	int *ar;
	int i;
	int j;

	i = (*ili)->tail_a - (*ili)->head_a  + (*ili)->tail_b - (*ili)->head_b ;
	ar = ft_memalloc(i * (int) sizeof(int));
	ar[i] = -1;
	j = (*ili)->head_a;
	i = 0;
	while (j < (*ili)->tail_a)
	{
		ar[i] = (*ili)->mas_a[j].num;
		i++;
		j++;
	}
	sortar2(&ar, (*ili)->tail_a - 1);
	return (ar);// если уже отсорирован, то 0
}

int     inferno(int *ar, t_stack **ili)
{
	group(ili);
	weight(ar, ili);
	obr_max(ili, ar);
	return (finish(ar, *ili));
}

void	push_swap(t_stack *ili)
{
	int j;
	int *ar;

	ar = crar(&ili);
	j = 0;
	while (inferno(ar, &ili))
	{
	    j++;
	}
	j = ili->head_a;
	while (j < ili->tail_a)
	{
		printf("a = %d = %d\n", ili->mas_a[j].num, ili->mas_a[j].weight);
		j++;
	}
	free(ar);
}