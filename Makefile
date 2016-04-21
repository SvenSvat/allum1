##
## Makefile for allum1 in /home/blanqu_a/Workspace/rendu/Allum1
## 
## Made by Adrien Blanquer
## Login   <blanqu_a@epitech.net>
## 
## Started on  Mon Feb  2 11:33:57 2015 Adrien Blanquer
## Last update Tue Feb 17 12:25:54 2015 Adrien Blanquer
##

SRC	= main.c \
	  my_getterm.c \
	  init_list.c \
	  my_show_list.c \
	  reverse_video.c \
	  my_putint.c \
	  allum.c \
	  clear_screen.c \
	  term_mod.c \
	  my_malloc.c \
	  gere_key.c \
	  delete_allum.c \
	  ia.c \
	  ia_fct.c \
	  ia_fct2.c \
	  how_many_data.c \
	  menu.c

SRCLIB	= lib/my/my_strlen.c \
	  lib/my/my_strncmp.c \
	  lib/my/my_putchar.c \
	  lib/my/my_put_nbr.c \
	  lib/my/my_putstr.c \
	  lib/my/my_getnbr.c

OBJ	= $(SRC:.c=.o)

OBJLIB	= $(SRCLIB:.c=.o)

NAME	= allum1

LIB	= libmy.a

CFLAGS	=+ -I./include -Wall -Wextra -Werror -g

LDFLAGS	= -L./lib/my/ -lmy -lncurses

CC 	= cc -o

all: $(NAME)

$(NAME): $(OBJLIB) $(OBJ)
	ar rc $(LIB) $(OBJLIB)
	ranlib $(LIB)
	mv $(LIB) lib/my/
	$(CC) $(NAME) $(OBJ) $(LDFLAGS)

clean:
	rm -f $(OBJ)
	rm -f $(OBJLIB)

fclean: clean
	rm -f $(NAME)
	rm -f lib/my/$(LIB)

re: fclean all

.PHONY: all clean fclean re
