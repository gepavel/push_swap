/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuliki <chuliki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:41:20 by gepavel           #+#    #+#             */
/*   Updated: 2024/10/15 17:33:01 by chuliki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void ft_free(char **s, int len)
{
	while (--len >= 0)
		free(s[len]);
	free(s);
}

static int	ft_check_dup(t_list **stk, int nb)
{
	t_list *aux;

	aux = *stk;
	while (aux)
	{
		if (aux->value == nb)
			return (1);
		aux = aux->next;
	}
	return (0);
}

static int	ft_check_int(char *s)
{
	long int		nb;
	
	if(*s)
	{
		if (*s == '+' || *s == '-')
			s++;
		while (*s)
		{
			if (*s > '9' || *s < '0')
				return (0);
			s++;
		}
		nb = ft_atoi(s);
		if (nb < INT_MIN || nb > INT_MAX)
			return 0;
	}
	return (1);
}

static void	fill_stack_a(char *s, t_list **sta)
{
	char		**arg;
	int			i;
	int 		error;

	i = 0;
	arg = ft_split(s, ' ');
	if (!arg || !s)
		return ;
	while (arg[i] || !error)
	{
		if (ft_check_int(arg[i]))
		{
			if (ft_check_dup(sta, ft_atoi(arg[i])))
				error = 1;
			ft_lst_add_back(sta, ft_lst_new((int)ft_atoi(arg[i])));
		}
		else
			error = 1;
		i++;
	}	
	ft_free(arg, i);
	if (error == 1)
		ft_free_stk(sta, NULL);	
}

int	main(int ac, char **av)
{
	t_list	*sta = NULL;
//	t_list	*stb;
	int		i;
	
	i = 1;
	while (i < ac)
		fill_stack_a(av[i++], &sta);
	print_list(&sta);
//	stb = NULL;
	return (0);
}
