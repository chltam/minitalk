# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: htam <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/17 15:14:38 by htam              #+#    #+#              #
#    Updated: 2023/01/17 15:14:40 by htam             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
SERVER := server
CLIENT := client
CC := cc
CFLAGS := -Werror -Wextra -Wall
INC := ./ft_printf/libftprintf.a
FTPRINTF := ./ft_printf/libftprintf.a


$(SERVER): server.c $(FTPRINTF)
	cc $(CFLAGS) server.c $(INC) -o $(SERVER)

$(CLIENT): client.c $(FTPRINTF) 
	cc $(CFLAGS) client.c $(INC) -o $(CLIENT)

$(FTPRINTF):
	make -C ft_printf

all: $(SERVER) $(CLIENT)

clean:
	rm -f $(SERVER)
	rm -f $(CLIENT)
fclean:
	make fclean -C ft_printf
	rm -f $(SERVER)
	rm -f $(CLIENT)
re: fclean all

.PHONY: all