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
	return (0);
}

int*     crar(t_stack **ili)
{
	static int *ar = NULL;
	int i;

	if (!ar)
	{
		i = ((*ili)->tail_a - (*ili)->head_a + 1) * (int)sizeof(int);
		ar = ft_memalloc(i);
		i = (*ili)->head_a;
		while (i <= (*ili)->tail_a)
		{
			ar[i] = (*ili)->mas_a[i].num;
			i++;
		}
		sortar2(&ar,(*ili)->tail_a);
	}
	return (ar);// если уже отсорирован, то 0
}

int     inferno(int *ar, t_stack **ili)
{
	weight(ar, ili);
	group(ili);
	obr_max(ili, ar);
	return (finish(ar, *ili));// если уже отсорирован, то 0
}

void	push_swap(t_stack *ili)
{
	int i;
	int j;
	int *ar;

	j = 3;
	while (j--)
	{
		i = ili->head_a;
		while (i <= ili->tail_a)
		{
			printf("%d = %d\n", ili->mas_a[i].num, ili->mas_a[i].weight);
			i++;
		}
		inferno(ar = crar(&ili), &ili);
	}
}