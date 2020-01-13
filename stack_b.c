/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusujio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 12:28:17 by gusujio           #+#    #+#             */
/*   Updated: 2019/11/30 12:28:19 by gusujio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void shr_b(t_stack **st) //двигает вправо
{
	int i;
	struct s_spisok *b;
	struct s_spisok *b2;

	i = (*st)->head_b;
	b =  (struct s_spisok *)malloc(sizeof(struct s_spisok*));
	b2 = (struct s_spisok *)malloc(sizeof(struct s_spisok*));
	ft_memcpy(&b2, &(*st)->mas_b[(*st)->head_b], sizeof(struct s_spisok*));
	while (i <= (*st)->tail_b)
	{
		ft_memcpy(&b, &(*st)->mas_b[i + 1], sizeof(struct s_spisok*));
		ft_memcpy(&(*st)->mas_b[i + 1], &b2,  sizeof(struct s_spisok*));
		ft_memcpy(&b2, &b, sizeof(struct s_spisok*));
		i++;
	}
}

void sb(t_stack **st)
{
	int b;

	if ((*st)->size_b > 1)
	{
		b = (*st)->mas_b[(*st)->head_b].num;
		(*st)->mas_b[(*st)->head_b] = (*st)->mas_b[(*st)->head_b + 1];
		(*st)->mas_b[(*st)->head_b + 1].num = b;
	}
}



void pb(t_stack **st)
{
	if ((*st)->size_a)
	{
		shr_b(st);
		ft_memcpy( &(*st)->mas_b[(*st)->head_b] ,&(*st)->mas_a[(*st)->head_a], sizeof(t_spisok));
		(*st)->mas_a[(*st)->head_a].num = 0;
		(*st)->size_b++;
		(*st)->tail_b++;
		(*st)->head_a++;
		(*st)->size_a--;
	}
}

void rb(t_stack **st)
{
	int a;
	int i;
	int b;
	int b2;

	a = (*st)->mas_b[(*st)->head_b].num;
	i = (*st)->tail_b;
	b2 = (*st)->mas_b[i].num;
	while ((*st)->head_b < i)
	{
		b = (*st)->mas_b[i - 1].num;
		(*st)->mas_b[i - 1].num = b2;
		b2 = b;
		i--;
	}
	(*st)->mas_b[(*st)->tail_b].num = a;
}

void rrb(t_stack **st)
{
	int b;

	b = (*st)->mas_b[(*st)->tail_b].num;
	shr_b(st);
	(*st)->mas_b[(*st)->head_b].num = b;
	(*st)->mas_b[(*st)->tail_b + 1].num = 0;
}