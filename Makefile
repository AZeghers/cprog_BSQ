##
## Makefile for  in /home/zegher_a/bin
## 
## Made by alexis zeghers
## Login   <zegher_a@epitech.net>
## 
## Started on  Fri Nov 20 13:42:25 2015 alexis zeghers
## Last update Sat Dec 19 16:44:39 2015 alexis zeghers
##

CC	=	gcc

SRCS	=	bsq.c \
		my_getnbr.c \
		get_max.c \
		algorithm.c

OBJS	=	$(SRCS:.c=.o)

NAME	=	bsq

all	:	$(NAME)

$(NAME)	:	$(OBJS)
		$(CC) -o $(NAME) $(SRCS)

clean	:
		rm -f $(OBJS)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
