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

int onliit(const char *s, char c)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] != c)
			return (0);
		i++;
	}
	return (1);
}
int stisnum(const char *s)//строка = числу?
{
	int i;

	i = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i]) && s[0] != '-')
			return (0);
		i++;
	}
	if (s[0] == '-' && ft_strlen(s) == 1)
		return (0);
	if (onliit(s, '0') && ft_strlen(s) > 1)
		return (0);
	if (s[0] == '-' && s[1] == '0')
		return (0);
	return (1);
}

int     ft_double(char **ar, char *s)
{
	int i;
	int j;
	int l;

	i = 1;
	j = 0;
	while (ar[i])
	{
		if (ft_strequ(ar[i], s))
			j++;
		i++;
	}
	l = ft_strlen(s);
	if ((s[0] != '-' && ft_strcmp(s, "2147483647") > 0) && l == 10)
		return (1);
	if (s[0] == '-' && ft_strcmp(s + 1, "2147483648") > 0 && l == 11)
		return (1);
	if ((l > 10 && s[0] != '-') || (l > 11 && s[0] == '-'))
		return (1);
	return (j != 1 );
}

void    initial(int argc, t_stack **ili)
{
	int i;

	i = 4 * argc * (int)sizeof(int*);
	*ili = (t_stack *)malloc(sizeof(struct s_stack));
	ft_bzero(*ili, sizeof(struct s_stack));
	(*ili)->mas_b = (int*)malloc(i);
	(*ili)->mas_a = (int*)malloc(i);
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
		 || !stisnum(argv[i]))
		{
			ft_printf("Error\n");
			exit(0);
		}
		ili->mas_a[i - 1] = ft_atoi(argv[i]);
		ili->size_a++;
		i++;
	}
	return (ili);
}