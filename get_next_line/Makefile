# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nicolas <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/13 03:35:01 by nicolas           #+#    #+#              #
#    Updated: 2023/01/17 12:22:04 by nplieger         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				:=		get_next_line.a

#------------------------------------------------#
#   PATHS                                        #
#------------------------------------------------#

SRC_DIR				:=		srcs
OBJ_DIR				:=		objs
INC_DIR				:=		includes

#------------------------------------------------#
#   INGREDIENTS                                  #
#------------------------------------------------#

SRCS				:=		get_next_line \
							get_next_line_utils \
						
SRCS_C				:=		$(addsuffix .c, $(SRCS))
CC_SRCS_C			:=		$(addsuffix $(SRC_DIR)/, $(SRCS_C))

OBJS				:=		$(SRCS_C:%.c=$(OBJ_DIR)/%.o)

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

all:				$(NAME)

$(NAME):			$(OBJS)
	$(AR) $(NAME) $(OBJS)

$(OBJS):			$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(DIRS) -c $< -o $@

$(OBJS_BONUS):			$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(DIRS) -c $< -o $@

clean:
	$(RM) -r $(OBJ_DIR)

fclean:				clean
	$(RM) $(NAME)

re:					fclean all

.PHONY: all clean fclean re

