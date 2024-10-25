/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gepavel <gepavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:06:15 by gepavel           #+#    #+#             */
/*   Updated: 2024/10/25 20:34:03 by gepavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_is_sort(t_list *stk)
{
	while (stk->next)
	{
		if (stk->value > stk->next->value)
			return (0);
		stk = stk->next;	
	}
	return (1);
}

void	ft_sort_tree(t_list **sta, t_list **stb)
{
	
}

void	push_swap(t_list **sta, t_list **stb, int len)
{
	if (len == 2 && !ft_is_sort(*sta))
		swap_sa(sta);
	if (len == 3)
		ft_sort_tree(sta, stb);
	if(len > 3)
		return ;
	stb = NULL;
}