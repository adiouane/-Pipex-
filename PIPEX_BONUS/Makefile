# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adiouane <adiouane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/06 19:08:34 by adiouane          #+#    #+#              #
#    Updated: 2022/03/27 18:40:54 by adiouane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

NAME_B = pipex_bonus

SRC = mandatory/utlis_pipex.c mandatory/children.c mandatory/pipex.c mandatory/free_m.c mandatory/error_m.c\

SRC_F = func/ft_split.c func/ft_strchr.c func/ft_strjoin.c \
	func/ft_strlen.c func/ft_strncmp.c func/ft_strnstr.c\

SRC_B = bonus/pipex_bonus.c bonus/utlis_pipex_bonus.c \
	bonus/child_bonus.c bonus/here_doc_bonus.c bonus/init_pipex_bonus.c \
	bonus/get_next_line_bonus.c bonus/free.c bonus/error.c \

CFLAGS = -Wall -Wextra -Werror 

all: $(NAME)

$(NAME): $(SRC) $(SRC_F) 
		@echo "\033[0;32mcompiling..."
		@$(CC) $(CFLAGS) $(SRC) $(SRC_F)  -o $(NAME)
		@echo "\033[0;33mDone!"

$(NAME_B):  $(SRC_B) $(SRC_F)
		@echo "\033[0;32mcompiling..."
		@$(CC) $(CFLAGS) $(SRC_B) $(SRC_F) -o $(NAME_B)
		@echo "\033[0;33mDone!"

bonus: $(NAME_B)

clean:
		@echo "\033[0;32mcleaning..."
		
fclean: clean
		@echo "\033[0;32mcleaning..."
		@rm -f $(NAME)
		@rm -f $(NAME_B)
		@echo "\033[0;33mDone!"

re:fclean all

.PHONY: all clean fclean re