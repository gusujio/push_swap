/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusujio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 15:43:18 by gusujio           #+#    #+#             */
/*   Updated: 2019/11/30 15:43:20 by gusujio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int     check_str2(t_stack **ili, char *s)
{
	int b;

	b = 0;
	if (ft_strequ(s, "pb"))
		pb(ili);
	else if (ft_strequ(s, "ra"))
		ra(ili);
	else if (ft_strequ(s, "rb"))
		rb(ili);
	else if (ft_strequ(s, "rr"))
		rr(ili);
	else if (ft_strequ(s, "rra"))
		rra(ili);
	else if (ft_strequ(s, "rrb"))
		rrb(ili);
	else if (ft_strequ(s, "rrr"))
		rrr(ili);
	else
		b = 1;
	return (b);
}

void    check_str(t_stack **ili, char *s)
{
	if (!s)
		return;
	if (ft_strequ(s, "sa"))
		sa(ili);
	else if (ft_strequ(s, "sb"))
		sb(ili);
	else if (ft_strequ(s, "ss"))
		ss(ili);
	else if (ft_strequ(s, "pa"))
		pa(ili);
	else if (check_str2(ili, s))
	{
		ft_printf("Error\n");
		exit(0);
	}
}

int norm(t_stack *ili)
{
	int i;

	if (ili->size_b || ili->tail_b != ili->head_b)
		return (1);
	i = 0;
	while (ili->head_a + i < ili->tail_a)
	{
		if (ili->mas_a[ili->head_a].num < ili->mas_a[ili->head_a + 1].num)
			return (0);
		i++;
	}
	return (1);
}

void     checker(t_stack *ili)
{
	char    *l;

	while (get_next_line(0, &l))
	{
		check_str(&ili, l);
		ft_strdel(&l);
	}
	if (norm(ili))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}