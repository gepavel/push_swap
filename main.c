/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuliki <chuliki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:41:20 by gepavel           #+#    #+#             */
/*   Updated: 2024/10/10 19:49:34 by chuliki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static void fill_stack_a(char *s, t_list **sta)
{
	char		 **arg;
	int			i;
	long int	nb;
	
	i = 0;
	arg = ft_split(s, ' ');
	if (!arg && *s)
		return;
	
	while (arg[i])
		ft_lst_add_back(sta, ft_lst_new((void *)ft_atoi(arg[i++])));
}

int		main(int ac, char **av)
{
	t_list	*sta = NULL;
//	t_list	*stb;
	int		i;

	i = 1;
	while (i < ac)
		fill_stack_a(av[i++], &sta);
	print_list(sta);


	return (0);
}