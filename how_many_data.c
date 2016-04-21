/*
** how_many_data.c for allum1 in /home/blanqu_a/Workspace/rendu/Allum1
** 
** Made by Adrien Blanquer
** Login   <blanqu_a@epitech.net>
** 
** Started on  Tue Feb  3 14:18:25 2015 Adrien Blanquer
** Last update Tue Feb  3 14:20:44 2015 Adrien Blanquer
*/

#include "my.h"

int		how_many_data(t_list *list)
{
  int		cpt;
  t_list	*tmp;

  cpt = 0;
  tmp = list;
  while (tmp != list->prev)
    {
      tmp = tmp->next;
      cpt++;
    }
  return (cpt);
}
