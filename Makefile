NAME = pipex
FLAGS = - Wall  -Wextra -Werror
RM = rm -f
SRC = pipex.c\

OBJECT = ${SRC:.c=.o}
all: $(NAME)
$(NAME) : $(OBJECT)
		make -C libft
		cc $(OBJECT) ./libft/libft.a -o $(NAME)

clean:
	make clean -C ./libft
	$(RM) $(OBJECT)
	$(RM) $(BOBJECT) 
	
fclean:
	make fclean -C ./libft
	$(RM) $(OBJECT) 
	$(RM) $(BOBJECT)
	$(RM) $(NAME)
	$(RM) $(BONUS)

re: fclean all