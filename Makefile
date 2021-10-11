# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjose-ye <mjose-ye@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/07 18:41:15 by edpaulin          #+#    #+#              #
#    Updated: 2021/10/11 19:36:41 by mjose-ye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libftprintf.a

HEADER 			=	ft_printf.h

SRCS			=	ft_printf.c \
					ft_types.c \
					ft_print_utils.c

OBJS			=	${SRCS:.c=.o}

CC				=	clang

CFLAGS			=	-Wall -Wextra -Werror -c

all:		$(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) $(HEADER)

clean:
	rm -f $(OBJS)

fclean:		clean
	rm -f $(NAME)

re:			fclean all
