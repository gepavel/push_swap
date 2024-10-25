/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gepavel <gepavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:09:24 by gepavel           #+#    #+#             */
/*   Updated: 2024/10/25 20:12:49 by gepavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_index(t_list *stk, int	len)
{
	t_list		*aux;
	t_list		*big;
	int			min;

	while (len > 0)
	{
		aux = stk;
		min = INT_MIN;
		big = NULL;
		while(aux)
		{
			if (aux->value >= min && aux->index == 0)
			{
				min = aux->value;	
				big = aux;
			}
			aux = aux->next;
		}
		if (!aux)
			big->index = len--;
		
	}
}

long int	ft_atoi(char *s)
{
	int			sign;
	long int	n;

	sign = 1;
	n = 0;
	if (*s == '+')
		s++;
	else if (*s == '-')
	{
		sign = -1;
		s++;
	}
	while (*s)
		n = n * 10 + (*s++ - '0');
	return (n * sign);
}

void		ft_putstr(char *str)
{
	int			i;

	i = -1;
	while(str[++i])
		write(1, &str[i], 1);
}