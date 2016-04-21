/*
** init_list.c for allum1 in /home/blanqu_a/Workspace/rendu/Allum1
** 
** Made by Adrien Blanquer
** Login   <blanqu_a@epitech.net>
** 
** Started on  Mon Feb  2 12:45:19 2015 Adrien Blanquer
** Last update Mon Feb 16 13:53:17 2015 Adrien Blanquer
*/

#include <stdlib.h>
#include "my.h"

int		init_list(t_list **list)
{
  t_list	*elem;
  static int	data = 1;

  if ((elem = malloc(sizeof(t_list))) == NULL)
    return (-1);
  elem->data = data;
  elem->select = 0;
  elem->nb = 1;
  if (*list == NULL)
    {
      *list = elem;
      (*list)->prev = *list;
      (*list)->next = *list;
      (*list)->select = 1;
    }
  elem->next = *list;
  elem->prev = (*list)->prev;
  (*list)->prev->next = elem;
  (*list)->prev = elem;
  data += 2;
  return (0);
}
