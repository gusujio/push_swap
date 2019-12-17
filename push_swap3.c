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

void    weight_b(int x, int y, t_stack **ili, int ar)
{
	int z;

	if (x < 0)
		x = equally((*ili)->mas_b, (*ili)->tail_b, ar);
	if (y < 0)
		y = equally((*ili)->mas_b, (*ili)->tail_b, ar);


}

void    weight(int *ar, t_stack **ili)
{
	int i;
	int x;
	int y;
	int z;

	i = 0;
	while (i <= (*ili)->tail_a)
	{
		x = equally((*ili)->mas_a, (*ili)->tail_a, ar[i]);
		(*ili)->mas_a[x].indexa = i;
		y =  equally((*ili)->mas_a, (*ili)->tail_a, ar[i + 1]);
		z = x > y ? (*ili)->tail_a - x + y : (*ili)->tail_a - y + x;
		if (x < 0 || y < 0)
		{
			if (x < 0)
			{
				x = equally((*ili)->mas_b, (*ili)->tail_b, ar[i]);
				y = (*ili)->tail_a / 2 > y ? y : (*ili)->tail_a - y + 1;
				(*ili)->mas_a[x].weight = x + y;
			}
		}
		else if ((y > x ? y - 1 : x - 1) <= z)//если вправо двигаться быстрее, чем влево
		{
			if (x < y)
				(*ili)->mas_a[x].weight = y - 1 - x; // индекс с 0
			else if (x - y - 1 == 1)
				(*ili)->mas_a[x].weight = y + 3;
			else
				(*ili)->mas_a[x].weight = y + 1 + (x - y - 1) + 1;//1 + x
		}
		else
		{
			if (x < y)
				(*ili)->mas_a[x].weight += 2;
			(*ili)->mas_a[x].weight += z;
		}
		i++;
	}
	(*ili)->mas_a[x].weight = -1;
}
void swap1(int x1, int x2, t_stack **ili)
{
	printf("swap1\n");
}

void swap2(int x1, int x2, t_stack **ili)
{
	if (x1 - 1 > (*ili)->tail_a - x1 + x2)// если лево бысрее, чем вправо
	{
		ita(ili, x1);
		till_xa(ili, x2);
		//устанавливаем x1 в конец и все что между в стек
	}
	else
	{
		//ставим x1 в начало и меняем с соседним
	}
}

void swap3(int x1, int x2, t_stack **ili)
{
	ita(ili, x2);
	till_xb(ili, x1);
	swap2(x1,x2, ili);
	printf("swap3\n");
}

void swap(int x1, int x2, t_stack **ili)
{
	int x;
	int y;

	x = equally((*ili)->mas_a, (*ili)->tail_a, x1);
	y = equally((*ili)->mas_a, (*ili)->tail_a, x2);
	if (x == -1 && y == -1)//если оба в b
	{
		swap1(x1, x2, ili);
	}
	else if (x != -1 && y != -1)// если оба находится в а
	{
		swap2(x1, x2, ili);
	}
	else
	{
		if (x == -1)
			swap3(x1, x2, ili);
		else
			swap3(x2, x1, ili);
	}
}