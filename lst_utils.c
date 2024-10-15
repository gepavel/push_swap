/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gepavel <gepavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:23:18 by chuliki           #+#    #+#             */
/*   Updated: 2024/10/15 13:28:19 by gepavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lst_new(int cont)
{
	t_list		*new;
	
	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->value = cont;
	new->index = 0;
	new->next = NULL;
	return (new);
}

void	ft_lst_add_back(t_list **lst, t_list *new)
{
	t_list	*aux;
	
	if (!lst || !new)
		return ;
	aux = *lst;
	if (!(aux))
	{
		*lst = new;
		return ;
	}
	while (aux->next != NULL)
		aux = aux->next;
	aux->next = new;
}
static void	free_stack(t_list **stk)
{
	t_list *aux;
	if (stk == NULL || *stk == NULL)
		return ;
	while (*stk)
	{
		aux = (*stk)->next;
		free(*stk);
		*stk = aux;
	}
	*stk = NULL;
}

void	ft_free_stk(t_list **sta, t_list **stb)
{
	if (sta == NULL || *sta != NULL)
		free_stack(sta);
	if (stb == NULL || *stb != NULL)
		free_stack(stb);
	write (1, "Error\n", 6);
}