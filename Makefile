##
## EPITECH PROJECT, 2017
## my_ls
## File description:
## 
##

SRCS	=	myls.c	\
		my_put_octal.c	\
		lib/my/my_putchar.c	\
		lib/my/my_strlen.c	\
		lib/my/my_putstr.c	\
		lib/my/my_put_nbr.c

OBJS	=	$(SRCS:.c=.o)

CFLAGS  =	-I./include

NAME	=	my_ls

all:	$(NAME)

$(NAME):	$(OBJS)
	gcc -o $(NAME) $(OBJS) -g

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:	all
