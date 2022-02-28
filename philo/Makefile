# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nosterme <nosterme@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/28 14:19:57 by nosterme          #+#    #+#              #
#    Updated: 2022/02/28 17:25:58 by nosterme         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= main.c init.c routine.c exit.c utils.c message.c eat.c fork.c
OBJS		= $(SRCS:.c=.o)
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
LIBS		= -lpthread
RM			= rm -f
NAME		= philo

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re