/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuliki <chuliki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:23:18 by chuliki           #+#    #+#             */
/*   Updated: 2024/10/10 19:47:18 by chuliki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lst_new(void *cont)
{
	t_list		*new;
	
	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->value = (long int)cont;
	new->next = NULL;
	return (new);
}

void	ft_lst_add_back(t_list **lst, t_list *new)
{
	t_list	*aux;
	
	if (!lst || !new)
		return ;
	if (!(*lst))
		*lst = new;
		return ;
	aux = *lst;
	while (aux && aux->next)
		aux = aux->next;
	aux->next = new;
}