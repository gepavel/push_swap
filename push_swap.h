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



long int		ft_atoi(char *s);
char			**ft_split(char *str, char c);


#endif