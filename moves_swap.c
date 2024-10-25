/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gepavel <gepavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 19:42:46 by gepavel           #+#    #+#             */
/*   Updated: 2024/10/25 20:31:28 by gepavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_list **stk)
{
	t_list *aux;
	
	if ((*stk) == NULL || (*stk)->next == NULL )
		return ;
	aux = (*stk)->next;
	(*stk)->next = aux->next;
	aux->next = (*stk);
	*stk = aux;	
}

void	swap_sa(t_list **sta)
{
	swap(sta);
	ft_putstr("sa\n");
}

void	swap_sb(t_list **stb)
{
	swap(stb);
	ft_putstr("sb\n");
}

void	sswap_ss(t_list **sta, t_list **stb)
{
	swap(sta);
	swap(stb);
	ft_putstr("ss\n");
}