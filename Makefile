# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/10 16:36:36 by mapandel          #+#    #+#              #
#    Updated: 2017/01/10 17:51:52 by vlanduyt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		fillit

#			Compilation

CC = 		clang
CFLAGS = 	-Wall -Wextra -Werror

#			Sources

SRC =		sources/main.c \

OBJ =		$(SRC:.c=.o)

#			Library Path

LIBPATH =	libft/libft.a

#			Colors

DEF =		\033[0m
GRA =		\033[1m
SOU =		\033[4m
BLI =		\033[5m
BLA =		\033[30m
RED =		\033[31m
GRE =		\033[32m
YEL =		\033[33m
BLU =		\033[34m
PUR =		\033[35m
CYA =		\033[36m
WHI =		\033[37m

#			Main Rules

$(NAME):
	@cd libft; $(MAKE) -f Makefile
	@echo "$(CYA)--::Compil Fillit::--$(DEF)"
	@make $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBPATH)

all: $(NAME)

standard:
	@cd libft; $(MAKE) -f Makefile standard
	@norminette -R CheckForbiddenSourceHeader $(SRC)

re: fclean all

glu: fclean all clean

#			Compilation Rules

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^

#			Clean Rules

clean:
	@cd libft; $(MAKE) -f Makefile clean
	@echo "$(PUR)--::Binary Delection::--$(DEF)"
	@rm -rf $(OBJ)

fclean: clean
	@echo "$(RED)--::Executable and Library Delection::--$(DEF)"
	@rm -rf $(NAME) $(LIBPATH)
