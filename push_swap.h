#ifndef PUSH_SWAP_HEADER
# define PUSH_SWAP_HEADER

#  include <stdlib.h>
#  include <unistd.h>
#  include <stdio.h>
#  include <limits.h>

typedef struct s_list
{
	long int		value;
	int				index;
	struct s_list 	*next;
} 					t_list;





//############## FUNCS #################//





t_list			*ft_lst_new(void *cont);
void			ft_lst_add_back(t_list **lst, t_list *new);
long int		ft_atoi(char *s);
char			**ft_split(char *str, char c);

//############## FUNCS PRUEBA #################//

void			print_list(t_list *lst);

#endif