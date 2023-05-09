GREEN			=	\033[0;32m
RED				=	\033[0;31m
YELLOW			=	\033[0;33m
END				=	\033[0m

NAME	=	diamondtrap

SRCS	=	main.cpp 				\
				ClapTrap.cpp		\
				ScavTrap.cpp		\
				FragTrap.cpp		\
				DiamondTrap.cpp	\

OBJS	=	${SRCS:.cpp=.o}

CC		=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98

all:		$(NAME)
			@echo "$(GREEN)DiamondTrap successfully compiled!$(END)"
			@sleep 0.5
			@clear

.cpp.o:
			@$(CC) $(CFLAGS) -c $< -o $(<:.cpp=.o)

$(NAME):	$(OBJS)
			@clear
			@echo "$(YELLOW)Compiling DiamondTrap...$(END)"
			@$(CC) $(OBJS) $(CFLAGS) -o $(NAME)

clean:
			@$(RM)  $(OBJS)
			@clear
			@echo "$(RED)All objects deleted!$(END)"

fclean:		clean
			@$(RM) $(NAME)
			@echo "$(RED)All executables deleted!$(END)"
			@sleep 0.5
			@clear

re:			fclean all

.PHONY:		all clean fclean re