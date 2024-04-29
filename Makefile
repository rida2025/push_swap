# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-jira <mel-jira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/06 16:08:04 by mel-jira          #+#    #+#              #
#    Updated: 2023/12/24 12:08:35 by mel-jira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

BONUS_NAME = checker

SRC_C =	check_allnumbers.c	\
		check_input.c	\
		check_valid.c	\
		ft_atoi.c	\
		ft_checkouflow.c	\
		ft_free_stack.c \
		ft_split.c	\
		ft_strjoin.c	\
		ft_strlen.c	\
		ft_substr.c	\
		get_tabs.c	\
		init_stack.c	\
		is_stack_sorted.c	\
		join_all_strs.c	\
		ft_strcmp.c \
		last_check.c	\
		main.c	\
		sort_2.c	\
		sort_3.c	\
		sort_5.c	\
		sort_100.c	\
		sort_all.c	\
		sort_stack.c \
		sort_utilits1.c \
		sort_utilits2.c \
		stack_utilitis1.c \
		stack_utilitis2.c \
		stack_utilitis3.c 

BONUS_C = 	check_allnumbers.c	\
			check_input.c	\
			check_valid.c	\
			ft_atoi.c	\
			ft_checkouflow.c	\
			ft_free_stack.c \
			ft_split.c	\
			ft_strjoin.c	\
			ft_strlen.c	\
			ft_substr.c	\
			get_tabs.c	\
			init_stack.c	\
			is_stack_sorted.c	\
			join_all_strs.c	\
			last_check.c	\
			sort_utilits1.c \
			sort_utilits2.c \
			stack_utilitis1.c \
			stack_utilitis2.c \
			stack_utilitis3.c \
			get_next_line.c \
			get_next_line_utils.c \
			ft_strcmp.c \
			ft_calloc.c \
			checker.c \
			checker_helper.c

COMPILER = cc

FLAGS = -Wall -Wextra -Werror

OBJC = $(SRC_C:.c=.o)
OBJ_BC = $(BONUS_C:.c=.o)

all: $(NAME)

$(NAME): $(OBJC)
	$(COMPILER) $(FLAGS)  $(OBJC) -o $(NAME)

bonus: $(OBJ_BC)
	$(COMPILER) $(FLAGS) $(OBJ_BC) -o $(BONUS_NAME) 

%.o : %.c push_swap.h get_next_line.h
	$(COMPILER) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJC) $(OBJ_BC)

fclean: clean
	rm -rf $(NAME) $(BONUS_NAME)

re: fclean all
