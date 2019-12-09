/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusujio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 12:29:25 by gusujio           #+#    #+#             */
/*   Updated: 2019/11/30 12:29:26 by gusujio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void ss(t_stack **st)
{
	sa(st);
	sb(st);
}

void rr(t_stack **st)
{
	ra(st);
	rb(st);
}

void rrr(t_stack **st)
{
	rra(st);
	rrb(st);
}

/*
int main()
{
	t_stack *ili;
	ili = (t_stack *)malloc(sizeof(struct s_stack));
	ili->mas_a = (int *)malloc(80);
	ft_bzero(ili->mas_a, 80);
	ili->mas_a[0] = 2;
	ili->mas_a[1] = 1;
	ili->mas_a[2] = 3;
	ili->mas_a[3] = 6;
	ili->mas_a[4] = 5;
	ili->mas_a[5] = 8;
	ili->size_a = 6;
	ili->head_a = 0;
	ili->tail_a = 5;

	ili->mas_b = (int *)malloc(80);
	ft_bzero(ili->mas_b, 80);
	ili->size_b = 0;
	ili->head_b = 0;
	ili->tail_b = 0;
	ft_printf("a = %1.10mb = %1.10m\n", &ili->mas_a, &ili->mas_b);
	sa(&ili);
	ft_printf("a = %1.10mb = %1.10m\n", &ili->mas_a, &ili->mas_b);
	pb(&ili);
	pb(&ili);
	pb(&ili);
	ft_printf("a = %1.10mb = %1.10m\n", &ili->mas_a, &ili->mas_b);
	ra(&ili);
	rb(&ili);
	ft_printf("a = %1.10mb = %1.10m\n", &ili->mas_a, &ili->mas_b);
	rra(&ili);
	rrb(&ili);
	ft_printf("a = %1.10mb = %1.10m\n", &ili->mas_a, &ili->mas_b);
	sa(&ili);
	ft_printf("a = %1.10mb = %1.10m\n", &ili->mas_a, &ili->mas_b);
	pa(&ili);
	pa(&ili);
	pa(&ili);
	ft_printf("a = %1.10mb = %1.10m\n", &ili->mas_a, &ili->mas_b);
	ft_printf("%d %d %d", ili->head_b, ili->tail_b, ili->size_b);
}
 */