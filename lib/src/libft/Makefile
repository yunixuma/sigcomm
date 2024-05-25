# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/16 16:52:37 by ykosaka           #+#    #+#              #
#    Updated: 2022/01/11 21:28:33 by Yoshihiro K      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
SRCH	= libft.h
OBJ1	= ft_isalpha.o ft_isdigit.o ft_isalnum.o ft_isascii.o ft_isprint.o \
		  ft_strlen.o ft_memset.o ft_bzero.o ft_memcpy.o ft_memmove.o \
		  ft_strlcpy.o ft_strlcat.o ft_toupper.o ft_tolower.o ft_strchr.o \
		  ft_strrchr.o ft_strncmp.o ft_memchr.o ft_memcmp.o ft_strnstr.o ft_atoi.o \
		  ft_calloc.o ft_strdup.o
OBJ2	= ft_substr.o ft_strjoin.o ft_strtrim.o ft_split.o ft_itoa.o \
		  ft_strmapi.o ft_striteri.o ft_putchar_fd.o ft_putstr_fd.o \
		  ft_putendl_fd.o ft_putnbr_fd.o
OBJB	= ft_lstnew.o ft_lstadd_front.o ft_lstsize.o ft_lstlast.o \
		  ft_lstadd_back.o ft_lstdelone.o ft_lstclear.o ft_lstiter.o ft_lstmap.o
CFLAGS	= -Wall -Wextra -Werror
CC		= gcc
AR		= ar rcs
RM		= rm -f
OBJS 		= $(OBJ1) $(OBJ2)
ifdef WITH_BONUS
	OBJS += $(OBJB)
endif

all: $(NAME)
$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)
bonus: 
	make WITH_BONUS=1
%.o: %.c $(SRCH)
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	$(RM) $(OBJ1) $(OBJ2) $(OBJB)
fclean: clean
	$(RM) $(NAME)
re: fclean all

.PHONY: all bonus clean fclean re
