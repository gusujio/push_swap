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
	while (i < (*ili)->size_a + (*ili)->size_b - 1) //(*ili)->tail_a - (*ili)->head_a + (*ili)->tail_b - (*ili)->head_b
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
				z = (*ili)->tail_a / 2 > x ? x : (*ili)->tail_a - x + 1;
				(*ili)->mas_a[x].weight = z + y;
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
			if (&((*ili)->mas_a[x]) + 1 == &((*ili)->mas_a[y]))//если уже отсортировано
				(*ili)->mas_a[x].weight = 0;
			else if ((z = ft_mod(x - y)) == 2 || z == 1) //если растояние межу ними 1 или 2 и можно просто z раз свапнуть
				(*ili)->mas_a[x].weight = z + (x > y) - (z == 1);
			(*ili)->mas_a[y].weight = -1;
		}
		i++;
	}
}

void swap1(t_spisok *x1, t_spisok *x2, t_stack **ili)
{
	printf("swap1\n");
}

int nearswap(t_spisok *x1, t_spisok *x2, t_stack **ili)
{
	if (ft_mod(x1->indexi - x2->indexi) == 1 &&
	((*ili)->mas_a[(*ili)->head_a].num == x2->num ||
	(*ili)->mas_a[(*ili)->head_a].num == x1->num))
	{
		sa(ili);
		ft_printf("sa\n");
		return (1);
	}
	return (0);
}
void swap2(t_spisok *x1, t_spisok *x2, t_stack **ili)
{
	if (!nearswap(x1, x2, ili))
	{
		if (x1->indexi > (*ili)->tail_a - (x1->indexi + 1) + x2->indexi)//ставим в конец
		{
			if (x1->indexi < (*ili)->tail_a - x1->indexi)//влево быстрее, чем вправо ????
				ita(ili, x1->num);
			else
				itar(ili, x1->num);
			till_xa(ili, x2->num);
			//устанавливаем x1 в конец и все что между в стек
		}
		else // ставим в начало
		{
			iha(ili, x1->num);
			if (!nearswap(x1, x2, ili))
				till_xa(ili, x2->num);
			//ставим x1 в начало и меняем с соседним
		}
	}
}

void swap3(t_spisok *x1, t_spisok *x2, t_stack **ili)//x1 в b
{
	if (x1->num > x2->num)//ставим в конец
	{
		if (x2->indexi < (*ili)->tail_a - x2->indexi)//влево быстрее, чем вправо
			ita(ili, x2->num);
		else
			itar(ili, x2->num);
	}
	else // ставим в начало
		iha(ili, x2->num);
	till_xb(ili, x1->num);
	if ((*ili)->mas_a[(*ili)->head_a].num > (*ili)->mas_a[(*ili)->head_a + 1].num
	&& (*ili)->mas_a[(*ili)->head_a].num != x1->num
	&& (*ili)->mas_a[(*ili)->tail_a].num != x2->num)
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
		if (x1->num > x2->num)
			swap2(x1, x2, ili);
		else
			swap2(x2, x1, ili);
	}
	else
	{
		if (x1->a_b)
			swap3(x1, x2, ili);
		else
			swap3(x2, x1, ili);
	}
}