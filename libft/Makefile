#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nfruneau <nfruneau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/22 16:49:05 by nfruneau          #+#    #+#              #
#    Updated: 2016/06/16 19:52:27 by nfruneau         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC 		=	gcc

CCFLAGS =	-Wall -Wextra -Werror

NAME 	=	libft.a

SRCS 	= 	ft_atoi.c \
			ft_bzero.c \
			ft_find_char.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_isspace.c \
			ft_itoa.c \
			ft_memalloc.c \
			ft_memccpy.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memdel.c \
			ft_memmove.c \
			ft_memset.c \
			ft_putchar.c \
			ft_putchar_fd.c \
			ft_putendl.c \
			ft_putendl_fd.c \
			ft_putnbr.c \
			ft_putnbr_fd.c \
			ft_putstr.c \
			ft_putstr_fd.c \
			ft_strcat.c \
			ft_strchr.c \
			ft_strclr.c \
			ft_strcmp.c \
			ft_strcpy.c \
			ft_strdel.c \
			ft_strdup.c \
			ft_strequ.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlen.c \
			ft_strlcat.c\
			ft_strmap.c \
			ft_strmapi.c \
			ft_strncat.c \
			ft_strncmp.c \
			ft_strncpy.c \
			ft_strndup.c \
			ft_strnequ.c \
			ft_strnew.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strrev.c \
			ft_strstr.c \
			ft_strsplit.c \
			ft_strsub.c \
			ft_strtrim.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_lstnew.c \
			ft_lstdelone.c \
			ft_lstdel.c \
			ft_lstadd.c \
			ft_lstiter.c \
			ft_lstmap.c \

OBJ 	=	$(SRCS:.c=.o)

$(NAME): 	$(OBJ)
			@echo "\033[32m[build $(NAME)] \033[0m" | tr -d '\n'
			ar rc $(NAME) $(OBJ)
			ranlib $(NAME)
			@echo "\033[32m[$(NAME) ready]\033[0m"

all:		$(NAME)

check:
			ar -t $(NAME)

%.o:		%.c
			@echo "\033[36m[ofile] \033[0m" | tr -d '\n'
			$(CC) $(CCFLAGS) -o $@ -c $<

clean:
			@echo "\033[31m[clean srcs] \033[0m" | tr -d '\n'
			rm -rf $(OBJ)

fclean:		clean
			@echo "\033[31m[fclean $(NAME)] \033[0m" | tr -d '\n'
			rm -rf $(NAME)

re:			fclean all
