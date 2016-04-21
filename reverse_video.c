/*
** reverse_video.c for allum1 in /home/blanqu_a/Workspace/rendu/Allum1
** 
** Made by Adrien Blanquer
** Login   <blanqu_a@epitech.net>
** 
** Started on  Mon Feb  2 15:08:47 2015 Adrien Blanquer
** Last update Tue Feb  3 14:52:01 2015 Adrien Blanquer
*/

#include <stdlib.h>
#include <term.h>
#include <curses.h>
#include <termios.h>
#include "my.h"

void	set_mr()
{
  char	*res;

  if ((res = tgetstr("mr", NULL)) == NULL)
    exit(0);
  if ((tputs(res, 0, my_putint)) == ERR)
    exit(0);
}

void	set_back()
{
  char	*res;

  if ((res = tgetstr("me", NULL)) == NULL)
    exit(0);
  if ((tputs(res, 0, my_putint)) == ERR)
    exit(0);
}
