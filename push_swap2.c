/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusujio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 15:14:17 by gusujio           #+#    #+#             */
/*   Updated: 2019/12/03 15:14:19 by gusujio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int finish(int *ar, t_stack *ili)//проверка что он уже отсортирован
{
	int i;

	i = 0;
	while (ar[0] != ili->mas_a[ili->head_a].num && i++ != ili->tail_a)
		ra(&ili);
	if (ar[0] != ili->mas_a[ili->head_a].num)
		return (1);
	i = 0;
	while (i < ili->tail_a - )
	return (i);//1 - продрлжить
}

void                    group(t_stack **ili)
{
	int i;

	i = (*ili)->head_a;
	while (i < (*ili)->tail_a)
	{
		if ((*ili)->mas_a[i].indexa == (*ili)->mas_a[i + 1].indexa - 1)
		{
			(*ili)->mas_a[i].next = &((*ili)->mas_a[i + 1]);
			(*ili)->mas_a[i + 1].back = &((*ili)->mas_a[i]);
		}
		i++;
	}
	i--;
	if ((*ili)->mas_a[(*ili)->head_a].indexa + 1 == (*ili)->mas_a[i].indexa
	|| (*ili)->mas_a[(*ili)->head_a].indexa - 1 == (*ili)->mas_a[i].indexa)
	{
		(*ili)->mas_a[i].next = &((*ili)->mas_a[(*ili)->head_a]);
		(*ili)->mas_a[(*ili)->head_a].back = &((*ili)->mas_a[i]);
	}
}

void    twomax_b(struct s_spisok **pop, t_stack **ili)
{
	int l;

	l = (*ili)->head_b;
	while (l < (*ili)->tail_b)
	{
		if ((*ili)->mas_b[l].weight <= (*pop)->weight && (*ili)->mas_b[l].weight > 0)
		{
			if ((*ili)->mas_b[l].weight == (*pop)->weight)
			{
				if ((*ili)->mas_b[l].indexa < (*pop)->indexa)
				{
					(*pop) = &((*ili)->mas_b[l]);
				}
			}
			else
				(*pop) = &((*ili)->mas_b[l]);
		}
		l++;
	}
}

int zmmm(struct s_spisok *ar,int s, int f)
{
	int l;

	l = s;
	while (l <= f)
	{
		if (ar[l].weight != 0)
			return (l);
		l++;
	}
	return (-1);
}
void    twomax_a(struct s_spisok **pop, t_stack **ili)
{
	int l;

	l = (*ili)->head_a;
	(*pop) = (t_spisok *)malloc(sizeof(t_spisok));
	ft_memcpy(*pop, &(*ili)->mas_a[zmmm((*ili)->mas_a, (*ili)->head_a, (*ili)->tail_a)], sizeof(t_spisok) + 1);
	while (l < (*ili)->tail_a)
	{
		if ((*ili)->mas_a[l].weight <= (*pop)->weight && (*ili)->mas_a[l].weight > 0)
		{
			if ((*ili)->mas_a[l].weight == (*pop)->weight)
			{
				if ((*ili)->mas_a[l].indexa < (*pop)->indexa)
				{
					(*pop) = &((*ili)->mas_a[l]);
				}
			}
			else
				(*pop) = &((*ili)->mas_a[l]);
		}
		l++;
	}
}

void    obr_max(t_stack **ili, int *ar)
{
	t_spisok *pop;
	t_spisok *pop2;
	int i;

	twomax_a(&pop, ili);
	twomax_b(&pop, ili);
	i = equally((*ili)->mas_a, (*ili)->tail_a, ar[pop->indexa + 1]);
	pop2 = (t_spisok *)malloc(sizeof(t_spisok));
	if (i == -1)
		ft_memcpy(pop2, &(*ili)->mas_b[equally((*ili)->mas_b, (*ili)->tail_b, ar[pop->indexa + 1])], sizeof(t_spisok));
	else
		ft_memcpy(pop2, &(*ili)->mas_a[i], sizeof(t_spisok));
	i = (*ili)->head_a;
	while (i < (*ili)->tail_a)
	{
		printf("a = %d = %d\n", (*ili)->mas_a[i].num, (*ili)->mas_a[i].weight);
		i++;
	}
	i = (*ili)->head_b;
	while (i < (*ili)->tail_b)
	{
		printf("b = %d = %d\n", (*ili)->mas_b[i].num, (*ili)->mas_b[i].weight);
		i++;
	}
	printf("--%d %d--\n", pop->num, pop2->num);
	swap(pop, pop2, ili);
}