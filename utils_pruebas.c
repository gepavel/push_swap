#include "push_swap.h"

void	print_list(t_list *lst)
{
	t_list 		*aux = lst;
	if (!lst)
		return ;
	while (aux->next)
	{
		printf("VALUE: %ld:		index: %d\n", aux->value, aux->index);
		printf("VALUE: %ld:		index: %d\n", aux->next->value, aux->next->index);
		aux = aux->next;
		
	}
	
}