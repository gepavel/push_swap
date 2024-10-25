#include "push_swap.h"

void	print_list(t_list **lst)
{
	t_list 		*aux = *lst;
	if (!lst || !(*lst))
	{
		printf("no hay ni lista ni elementos en ella\n");
		return ;
	}
	int	i = 1;
	while (aux)
	{
		printf("%d-VALUE:%d:		index:%d\n", i++, aux->value, aux->index);
		aux = aux->next;
	}
	printf("pintada la lista con exito");
}