# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daehlee <daehlee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/12 19:40:32 by daehlee           #+#    #+#              #
#    Updated: 2023/12/18 17:40:40 by daehlee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a

SRCS := format_c_s.c format_digit.c format_hex.c format_pointer.c  format_u.c ft_printf.c
OBJS := $(SRCS:.c=.o)

CC := cc
CFLAGS := -Wall -Wextra -Werror -c

OBJF = $(OBJS)

all : $(NAME)

$(NAME) : $(OBJF)
	ar cr $@ $^

%.o : %.c
	$(CC) $(CFLAGS) $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
