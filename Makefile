name= ps
cc= clang
cflags= -Wall -Werror -Wextra -g3 -fsanitize=address
##makelib = ar rcs
##namelib = push_swap.a
src=	main.c		split.c		utils.c			lst_utils.c
src_p=	utils_pruebas.c
obj-P=	$(src_p:.c=.o)
obj = $(src:.c=.o)

all:$(name)

$(name): $(src) $(obj) $(src_p) $(obj_p)
##	@$(makelib) $(namelib) $(obj) $(obj_p)
	@$(CC) $(cflags) $(src) $(src_p) $(namelib) -o $(name)

clean:
	@rm -rf $(obj)

fclean: clean
	@rm -rf $(name)

re: fclean all

.PHONY:
