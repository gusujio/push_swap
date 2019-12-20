/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusujio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 16:14:41 by gusujio           #+#    #+#             */
/*   Updated: 2019/12/13 16:14:43 by gusujio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void    weight(int *ar, t_stack **ili)
{
	int i;
	int x;
	int y;
	int z;

	i = 0;
	while (i < (*ili)->tail_a - 1) //(*ili)->tail_a - (*ili)->head_a + (*ili)->tail_b - (*ili)->head_b
	{
		x = equally((*ili)->mas_a, (*ili)->tail_a, ar[i]);
		(*ili)->mas_a[x].indexa = i;
		y = equally((*ili)->mas_a, (*ili)->tail_a, ar[i + 1]);
		if (x < 0 || y < 0)
		{
			if (x < 0)
			{
				x = equally((*ili)->mas_b, (*ili)->tail_b, ar[i]) - 1;
				y = (*ili)->tail_a / 2 > y ? y : (*ili)->tail_a - y + 1;
				(*ili)->mas_a[x].weight = x + y;
			}
			else if (y < 0)
			{
				y = equally((*ili)->mas_b, (*ili)->tail_b, ar[i + 1]) - 1;
				x = (*ili)->tail_a / 2 > x ? x : (*ili)->tail_a - x + 1;
				(*ili)->mas_a[x].weight = x + y;
			}
		}
		else
		{
			if (x > y)
			{
				(*ili)->mas_a[x].weight = x - (*ili)->head_a; //растояние оперций если идти влево и так их соединить
				z = (((*ili)->tail_a - (*ili)->head_a) - (x - (*ili)->head_a) - 1) * 2 + y - (*ili)->head_a; //растояние оперций если идти вправо
				if ((*ili)->mas_a[x].weight > z)
					(*ili)->mas_a[x].weight = z;
				if (x == (*ili)->tail_a && y == (*ili)->head_a) // если последние и можно свапнуть
					(*ili)->mas_a[x].weight += 2;
			}
			else
			{
				(*ili)->mas_a[x].weight = y - (*ili)->head_a; //растояние оперций если идти влево
				z = ((*ili)->tail_a - (*ili)->head_a) - y + x - 1; //растояние оперций если идти вправо
				if ((*ili)->mas_a[x].weight > z)
					(*ili)->mas_a[x].weight = z;
				if (y == (*ili)->tail_a - 1 && x == (*ili)->head_a)
					(*ili)->mas_a[x].weight += 2;
			}
			if ((z = ft_mod(x - y)) == 2 || z == 1) //если растояние межу ними 1 или 2 и можно просто z раз свапнуть
				(*ili)->mas_a[x].weight = z + (x > y) - (z == 1);

		}
		i++;
	}
	(*ili)->mas_a[y].weight = -1;
}

void swap1(t_spisok *x1, t_spisok *x2, t_stack **ili)
{
	printf("swap1\n");
}

void swap2(t_spisok *x1, t_spisok *x2, t_stack **ili)
{
	if (x1->indexi > (*ili)->tail_a - (x1->indexi + 1) + x2->indexi)// если лево бысрее, чем вправо
	{
		ita(ili, x1->num);
		till_xa(ili, x2->num);
		//устанавливаем x1 в конец и все что между в стек
	}
	else
	{
		iha(ili, x1->num);
		till_xa(ili, x2->num);
		//ставим x1 в начало и меняем с соседним
	}
}

void swap3(t_spisok *x1, t_spisok *x2, t_stack **ili)
{
	iha(ili, x2->num);
	till_xb(ili, x1->num);
	if ((*ili)->mas_a[(*ili)->head_a].num > (*ili)->mas_a[(*ili)->head_a + 1].num)
		sa(ili);
}

void swap(t_spisok *x1, t_spisok *x2, t_stack **ili)
{

	if (x1->a_b && x2->a_b)//если оба в b
	{
		swap1(x1, x2, ili);
	}
	else if (!x1->a_b && !x2->a_b)// если оба находится в а
	{
		swap2(x1, x2, ili);
	}
	else
	{
		if (x1->a_b)
			swap3(x1, x2, ili);
		else
			swap3(x2, x1, ili);
	}
}