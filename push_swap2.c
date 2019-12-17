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
	return (i);
}

void                    group(t_stack **ili)
{
	int i;

	i = (*ili)->head_a;
	while (i <= (*ili)->tail_a)
	{
		if ((*ili)->mas_a[i].indexa == (*ili)->mas_a[i + 1].indexa - 1)
		{
			(*ili)->mas_a[i].next = &((*ili)->mas_a[i + 1]);
			(*ili)->mas_a[i + 1].back = &((*ili)->mas_a[i]);
		}
		i++;
	}
}

void    twomax_b(struct s_spisok **pop, t_stack **ili)
{
	int l;

	l = (*ili)->head_b;
	while (l < (*ili)->tail_b)
	{
		if ((*ili)->mas_b[l].weight <= (*pop)->weight && (*ili)->mas_b[l].weight != -1)
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

void    twomax_a(struct s_spisok **pop, t_stack **ili)
{
    int l;

    l = (*ili)->head_a;
    while (l <= (*ili)->tail_a)
    {
        if ((*ili)->mas_a[l].weight <= (*pop)->weight && (*ili)->mas_a[l].weight != -1)
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
	struct s_spisok *pop;

	pop = (struct s_spisok *)malloc(sizeof(struct s_spisok));
	pop->indexa = 100;
	pop->weight = 100;
	twomax_a(&pop, ili);
	twomax_b(&pop, ili);
	printf("--%d %d--\n", pop->num, ar[pop->indexa + 1]);
	swap(pop->num,ar[pop->indexa + 1], ili);
}

