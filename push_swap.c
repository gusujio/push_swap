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

void    creat(t_spisok (*as)[], t_stack *ili)
{
	int i;
	int j;

	j = 0;
	i = ili->head_a;
	while (i < ili->tail_a)
	{
		(*as)[j].num = ili->mas_a[i];
		(*as)[j].next = NULL;
		(*as)[j].back = NULL;
		(*as)[j].weight = -1;
		i++;
		j++;
	}
}

int     equally(t_spisok (*as)[], int x)
{
	int         i;

}

int     twomax(t_stack **ili, t_spisok (*as)[])
{
	static int *ar = NULL;
	int i;

	if (!ar)
	{
		i = ((*ili)->tail_a - (*ili)->head_a + 1) * (int)sizeof(int);
		ar = ft_memalloc(i);
		ft_memcpy(ar = ft_memalloc(i), (*ili)->mas_a, i);
		sortar2(&ar,(*ili)->tail_a);
	}
	weight(ar, *as);
	return (ar != (*ili)->mas_a);// если уже отсорирован, то 0
}

void	push_swap(t_stack *ili)
{
	t_spisok as[ili->tail_a - ili->head_a + 2];

	creat(&as, ili);
	while (twomax(&ili, &as)) // поставит нужный вес
	{

	}
}