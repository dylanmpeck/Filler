# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpeck <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/06 18:25:31 by dpeck             #+#    #+#              #
#    Updated: 2018/10/22 21:23:11 by dpeck            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = dpeck.filler

SRC_PATH = src/
INC_PATH = includes/
OBJ_PATH = obj/

SRC = filler.c \
	  adjacent_values.c \
	  heat_map.c \
	  check_validity.c \
	  place.c

HEADER = includes/filler.h
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))
INC_LFT = $(addprefix -I, includes/libft/)

OBJ_NAME = $(subst .c,.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	make -C includes/libft/
	gcc -Wall -Wextra -Werror -o $(NAME) $(OBJ) -L includes/libft/ -lft

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	gcc -Wall -Wextra -Werror $(INC) $(INC_LFT) -o $@ -c $<

test: $(OBJ)
	gcc -o $(NAME) $(OBJ) -L includes/libft/ -lft

clean:
	make -C includes/libft/ clean
	/bin/rm -rf $(OBJ_PATH)

fclean: clean
	make -C includes/libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all
