#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nfruneau <nfruneau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/15 17:19:23 by nfruneau          #+#    #+#              #
#    Updated: 2016/06/16 14:58:29 by nfruneau         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME 	=	ft_nm

NAME2 	=	ft_otool

CC 		=	gcc

CFLAGS 	=	-Wall -Wextra -Werror -g

LIBDIR	=	libft/

SRCS 	= 	srcs/ft_nm/ft_nm.c \
		 	srcs/ft_nm/load_arch.c \
			srcs/ft_nm/init_data.c \
			srcs/ft_nm/parse_cmd.c \
			srcs/ft_nm/section_list_64.c \
			srcs/ft_nm/section_list_32.c \
			srcs/ft_nm/sort_list.c \
			srcs/ft_nm/sym_print.c \
			srcs/ft_nm/sym_list_64.c \
			srcs/ft_nm/sym_list_32.c \
			srcs/ft_nm/arch_list.c \
			srcs/ft_nm/handle_fat.c \

SRCS2 	= 	srcs/ft_otool/ft_otool.c \
		 	srcs/ft_otool/load_arch.c \
			srcs/ft_otool/init_data.c \
			srcs/ft_otool/parse_cmd.c \
			srcs/ft_otool/section_list_64.c \
			srcs/ft_otool/section_list_32.c \
			srcs/ft_otool/print.c \
			srcs/ft_otool/arch_list.c \
			srcs/ft_otool/handle_fat.c \

OBJ 	=	$(SRCS:.c=.o)

OBJ2 	=	$(SRCS2:.c=.o)

all:		lib $(NAME) $(NAME2)

lib:
			make -C $(LIBDIR)

$(NAME):	$(OBJ)
			@echo "\033[32m[build $(NAME)] \033[0m" | tr -d '\n'
			$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L $(LIBDIR) -lft
			@echo "\033[32m[$(NAME) ready]\033[0m"

$(NAME2):	$(OBJ2)
			@echo "\033[32m[build $(NAME2)] \033[0m" | tr -d '\n'
			$(CC) $(CFLAGS) -o $(NAME2) $(OBJ2) -L $(LIBDIR) -lft
			@echo "\033[32m[$(NAME2) ready]\033[0m"

%.o:		%.c
			@echo "\033[36m[ofile] \033[0m" | tr -d '\n'
			$(CC) $(CFLAGS) -o $@ -c $<

clean:
			@echo "\033[31m[clean srcs] \033[0m" | tr -d '\n'
			rm -rf $(OBJ)
			rm -rf $(OBJ2)
			make -C $(LIBDIR) clean

fclean:		clean
			@echo "\033[31m[fclean $(NAME)] \033[0m" | tr -d '\n'
			rm -rf $(NAME)
			rm -rf $(NAME2)
			make -C $(LIBDIR) fclean

re:			fclean all
