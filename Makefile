#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkaminsk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/22 12:01:45 by vkaminsk          #+#    #+#              #
#    Updated: 2017/02/22 12:44:15 by vkaminsk         ###   ########.fr        #
#                                                                              #
#******************************************************************************#
NAME		=	filler
CC          =	gcc
CFLAGS		=	-Wall -Wextra -Werror

CFILES		=	main.c subfunc.c core.c

OFILES		=	$(CFILES:.c=.o)


all: $(NAME)

$(NAME): $(OFILES)
	$(MAKE) -C ./libft
	$(CC) -Iheaders $(CFLAGS) -o $(NAME) $(OFILES) libft/libft.a
clean:
	/bin/rm -rf $(OFILES) *~
	$(MAKE) -C ./libft clean

fclean:
	/bin/rm -rf $(OFILES) *~
	$(MAKE) -C ./libft fclean
	/bin/rm -rf $(NAME)

re: fclean all

.PHONY: all clean re fclean