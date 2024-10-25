/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gepavel <gepavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:41:20 by gepavel           #+#    #+#             */
/*   Updated: 2024/10/25 13:10:44 by gepavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
static void ft_free(char **s, int len)
{
	while (--len >= 0)
		free(s[len]);
	free(s);
}
*/

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
	int				i;
	
	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if(s[i])
	{
		while (s[i])
		{
			if (s[i] > '9' || s[i] < '0')
				return (0);
			i++;
		}
		nb = ft_atoi(s);
		if (nb < INT_MIN || nb > INT_MAX)
			return (0);
	}
	else
		return (0);
	return (1);
}

static void	fill_stack_a(char *s, t_list **sta)
{
	char		**arg;
	int			i;

	i = 0;
	arg = ft_split(s, ' ');
	while (arg[i])
	{
		if (ft_check_int(arg[i]) && !(ft_check_dup(sta, ft_atoi(arg[i]))))
			ft_lst_add_back(sta, ft_lst_new((int)ft_atoi(arg[i])));
		else
			ft_free_exit(sta, NULL);
		free(arg[i++]);
	}
	free(arg);
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
	
	
	free_stack(&sta);
	return (0);
}
