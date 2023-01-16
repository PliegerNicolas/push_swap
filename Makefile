# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nicolas <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/05 22:29:51 by nicolas           #+#    #+#              #
#    Updated: 2023/01/16 19:03:12 by nplieger         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_COMMON			:=		common.a
NAME_PUSH_SWAP		:=		push_swap.a
NAME_CHECKER		:=		checker.a
EXEC_PUSH_SWAP		:=		./push_swap
EXEC_CHECKER		:=		./checker

#------------------------------------------------#
#   PATHS                                        #
#------------------------------------------------#

SRC_DIR				:=		srcs
OBJ_DIR				:=		objs
INC_DIR				:=		includes
GET_NEXT_LINE_DIR	:=		get_next_line

#------------------------------------------------#
#   INGREDIENTS                                  #
#------------------------------------------------#

GET_NEXT_LINE		:=		$(GET_NEXT_LINE_DIR)/get_next_line.a

SRCS_COMMON			:=		args_verification/verify_given_args \
							args_verification/retrieve_int_and_verify \
							initialize/initialize_stacks \
							initialize/reverse_double_linked_stack \
							initialize/set_final_positions \
							initialize/int_args \
							sort/quicksort \
							sort/get_median \
							sort/small_sort \
							sort/sort_utils \
							free/free \
							utils/ft_putchar_fd \
							utils/ft_putstr_fd \
							utils/ft_putendl_fd \
							utils/ft_isdigit \
							utils/ft_index_atoi \
							utils/ft_swap \
							rules/swap \
							rules/push \
							rules/rotate \
							rules/reverse_rotate \
							rules/select_target_method \

SRCS_PUSH_SWAP		:=		push_swap \

SRCS_CHECKER		:=		checker/checker \
							checker/execute_rules \
							checker/initialize_stacks_checker \

SRCS_COMMON_C		:=		$(addsuffix .c, $(SRCS_COMMON))
SRCS_PUSH_SWAP_C	:=		$(addsuffix .c, $(SRCS_PUSH_SWAP))
SRCS_CHECKER_C		:=		$(addsuffix .c, $(SRCS_CHECKER))
CC_SRCS_COMMON_C	:=		$(addsuffix $(SRC_DIR)/, $(SRCS_COMMON_C))
CC_SRCS_PUSH_SWAP_C	:=		$(addprefix $(SRC_DIR)/, $(SRCS_PUSH_SWAP_C))
CC_SRCS_CHECKER_C	:=		$(addsuffix $(SRC_DIR)/, $(SRCS_CHECKER_C))

OBJS_COMMON			:=		$(SRCS_COMMON_C:%.c=$(OBJ_DIR)/%.o)
OBJS_PUSH_SWAP		:=		$(SRCS_PUSH_SWAP_C:%.c=$(OBJ_DIR)/%.o)
OBJS_CHECKER		:=		$(SRCS_CHECKER_C:%.c=$(OBJ_DIR)/%.o)

#------------------------------------------------#
#   COMMANDS                                     #
#------------------------------------------------#

CC					:=		gcc
AR					:=		ar -rcs
DIRS				:=		-I $(INC_DIR)
CFLAGS				:=		-Wall -Wextra -Werror -g
RM					:=		rm -f

#------------------------------------------------#
#   RECIPES                                      #
#------------------------------------------------#

all:				$(NAME_PUSH_SWAP)

common:	$(OBJS_COMMON)
	$(AR) $(NAME_COMMON) $(OBJS_COMMON)

$(NAME_PUSH_SWAP):			common $(OBJS_PUSH_SWAP)
	$(AR) $(NAME_PUSH_SWAP) $(OBJS_PUSH_SWAP) $(OBJS_COMMON)
	$(CC) $(CFLAGS) $(NAME_PUSH_SWAP) -o $(EXEC_PUSH_SWAP)

$(OBJS_COMMON):	$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(DIRS) -c $< -o $@

$(OBJS_PUSH_SWAP):	$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(DIRS) -c $< -o $@

$(OBJS_CHECKER):	$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(DIRS) -c $< -o $@

clean:
	$(RM) -r $(OBJ_DIR)

fclean:				clean
	make fclean -C $(GET_NEXT_LINE_DIR)
	$(RM) $(NAME_COMMON)
	$(RM) $(NAME_PUSH_SWAP)
	$(RM) $(NAME_CHECKER)
	$(RM) $(EXEC_PUSH_SWAP)
	$(RM) $(EXEC_CHECKER)

re:					fclean all

bonus:				all $(OBJS_CHECKER)
	make -C $(GET_NEXT_LINE_DIR)
	$(AR) $(NAME_CHECKER) $(OBJS_CHECKER) $(OBJS_COMMON)
	$(CC) $(CFLAGS) $(NAME_CHECKER) $(GET_NEXT_LINE) -o $(EXEC_CHECKER)

bonus_re:			fclean bonus

.PHONY: all clean fclean re bonus bonus_re
