/*
** ia_fct2.c for allum1 in /home/blanqu_a/Workspace/rendu/Allum1
** 
** Made by Adrien Blanquer
** Login   <blanqu_a@epitech.net>
** 
** Started on  Tue Feb 17 12:19:03 2015 Adrien Blanquer
** Last update Tue Feb 17 12:28:18 2015 Adrien Blanquer
*/

#include "my.h"

void	*three_lines(t_list *list)
{
  if (search_data(list, 1) == 1)
    {
      while (list->data != 1)
	list = list->next;
      delete_allum(&list, 1);
    }
  else
    {
      while (list->data < 2)
	list = list->next;
      delete_allum(&list, list->data - 1);
    }
  return (list);
}
