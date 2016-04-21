/*
** clear_screen.c for my_select in /home/blanqu_a/Workspace/rendu/PSU_2014_my_select
** 
** Made by Adrien Blanquer
** Login   <blanqu_a@epitech.net>
** 
** Started on  Sun Jan 11 16:08:54 2015 Adrien Blanquer
** Last update Sun Jan 11 16:09:27 2015 Adrien Blanquer
*/

#include <term.h>
#include <termios.h>
#include <stdlib.h>
#include "my.h"

void	clean_screen()
{
  char	*res;

  res = NULL;
  res = tgetstr("cl", NULL);
  if (res == NULL)
    exit(0);
  tputs(res, 0, my_putint);
}
