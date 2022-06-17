# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zoukaddo <zoukaddo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/16 22:08:46 by zoukaddo          #+#    #+#              #
#    Updated: 2022/06/17 19:41:45 by zoukaddo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

AR = ar rs

NAME = philo


SRCS =  src/utils.c  src/tasks.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) main.c $(SRCS) -o $(NAME)
	
clean:
	rm -rf 
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re