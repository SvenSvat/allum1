/*
** allum.c for allum1 in /home/blanqu_a/Workspace/rendu/Allum1
** 
** Made by Adrien Blanquer
** Login   <blanqu_a@epitech.net>
** 
** Started on  Mon Feb  2 15:28:49 2015 Adrien Blanquer
** Last update Tue Feb 17 12:46:17 2015 Adrien Blanquer
*/

#include <termios.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

void		change_select(t_list *list)
{
  t_list	*tmp;

  tmp = list->next;
  list->select = 1;
  while (tmp != list)
    {
      tmp->select = 0;
      tmp = tmp->next;
    }
  list = tmp;
}

int		check_pyramide(t_list *list)
{
  t_list	*tmp;
  int		total;

  tmp = list;
  total = 0;
  while (tmp != list->prev)
    {
      total += tmp->data;
      tmp = tmp->next;
    }
  total += tmp->data;
  return (total);
}

void			allum(t_list *list, t_menu *ptr)
{
  char			*buff;
  t_list		*tmp;

  tmp = list;
  buff = my_malloc(3);
  while (check_pyramide(tmp) > 0)
    {
      clean(buff, 4);
      clean_screen();
      my_show_list(list, ptr->nb_line);
      if (read(0, buff, 3) <= 0)
      	break;
      if (gere_key(buff, &tmp) == 1)
	if (ia_level(tmp, ptr->level) == 1)
	  break;
    }
}
