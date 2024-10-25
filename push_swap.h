#ifndef PUSH_SWAP_HEADER
# define PUSH_SWAP_HEADER

#  include <stdlib.h>
#  include <unistd.h>
#  include <stdio.h>
#  include <limits.h>

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list 	*next;
} 					t_list;





//############## FUNCS #################//






void			swap_sa(t_list **sta);
void			swap_sb(t_list **stb);
void			swap_ss(t_list **sta, t_list **stb);

void			ft_sort_tree(t_list **sta, t_list **stb);
int				ft_is_sort(t_list *stk);
void			push_swap(t_list **sta, t_list **stb, int len);
void			put_index(t_list *stk, int	len);

int				ft_list_size(t_list *lst);
t_list			*ft_lst_new(int cont);
void			ft_lst_add_back(t_list **lst, t_list *new);
void			ft_free_exit(t_list **sta, t_list **stb);
void			free_stack(t_list **stk);

long int		ft_atoi(char *s);
void			ft_putstr(char *str);
char			**ft_split(const char *str, char c);

//############## FUNCS PRUEBA #################//





void			print_list(t_list **lst);

#endif