# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/11 14:28:45 by hcorrea-          #+#    #+#              #
#    Updated: 2023/04/21 10:59:34 by hcorrea-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN			=	\033[0;32m
RED				=	\033[0;31m
YELLOW			=	\033[0;33m
END				=	\033[0m

NAME	=	phonebook

SRCS	=	phonebookMain.cpp	\
				phonebook.cpp			\
				contact.cpp				\
				
OBJS	=	${SRCS:.cpp=.o}

CC		=	c++
CFLAGS	=	-Wall -Wextra -Werror -std=c++98

all:		$(NAME)
			@echo "$(GREEN)PhoneBook successfully compiled!$(END)"
			@sleep 0.5
			@clear

.cpp.o:
			@$(CC) $(CFLAGS) -c $< -o $(<:.cpp=.o)

$(NAME):	$(OBJS)
			@clear
			@echo "$(YELLOW)Compiling PhoneBook...$(END)"
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