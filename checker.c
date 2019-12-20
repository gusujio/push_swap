/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gusujio <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 19:26:23 by gusujio           #+#    #+#             */
/*   Updated: 2019/11/30 17:28:36 by gusujio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int stisnum(const char *s)//строка = числу?
{
	int i;

	i = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

int     ft_double(char **ar, char *s)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (ar[i])
	{
		if (ft_strequ(ar[i], s))
			j++;
		i++;
	}
	i = ft_strlen(s) >= 10;
	return (j == 1 && ft_strcmp(s, "2147483647") < 0 && i);
}

void    initial(int argc, t_stack **ili)
{
	int i;

	i = 4 * argc * (int)sizeof(struct s_spisok);
	*ili = (t_stack *)malloc(sizeof(struct s_stack));
	ft_bzero(*ili, sizeof(struct s_stack));
	(*ili)->mas_b = (t_spisok*)malloc(i);
	(*ili)->mas_a = (t_spisok*)malloc(i);
	ft_bzero((*ili)->mas_b, i);
	ft_bzero((*ili)->mas_a, i);
	(*ili)->tail_a = argc - 1;
}

t_stack *ft_error(int argc, char **argv)
{
	int i;
	t_stack *ili;

	initial(argc, &ili);
	i = 1;
	while (argv[i])
	{
		if (ft_strchr(argv[i], '.') || ft_double(argv, argv[i])
		|| argv[i][0] == '-' || !stisnum(argv[i]))
		{
			ft_printf("Error\n");
			exit(0);
		}
		ili->mas_a[i - 1].num = ft_atoi(argv[i]);
		ili->size_a++;
		ili->mas_a[i - 1].indexi = i - 1;
		i++;
	}
	return (ili);
}

int		main(int argc, char** argv)
{
	t_stack *ili;

	if (argc > 1)
	{
		push_swap(ili = ft_error(argc, argv));
		checker(ili);
	}
}