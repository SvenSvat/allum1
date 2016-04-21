/*
** main.c for allum1 in /home/blanqu_a/Workspace/rendu/Allum1
** 
** Made by Adrien Blanquer
** Login   <blanqu_a@epitech.net>
** 
** Started on  Mon Feb  2 12:36:23 2015 Adrien Blanquer
** Last update Mon Feb 16 14:55:41 2015 Adrien Blanquer
*/

#include <curses.h>
#include <term.h>
#include <stdlib.h>
#include "my.h"

int	init_main(int argc, char **env)
{
  char	*term;

  if (argc != 1)
    {
      my_putstr("Usage: ./allum1.\n");
      return (0);
    }
  if ((term = my_getterm(env)) == NULL)
    return (0);
  if (tgetent(NULL, term) == -1)
    return (0);
  mod_raw();
  return (1);
}

int			main(int argc, char **argv, char **env)
{
  struct termios	save;
  t_list		*list;
  t_menu		*ptr;
  int			i;

  (void)argv;
  if (tcgetattr(0, &save) == -1)
    return (0);
  if (init_main(argc, env) == 0)
    return (0);
  ptr = menu();
  list = NULL;
  i = 0;
  while (i < ptr->nb_line)
    {
      init_list(&list);
      i++;
    }
  clean_screen();
  allum(list, ptr);
  my_putchar('\n');
  mod_canon(save);
  return (0);
}
