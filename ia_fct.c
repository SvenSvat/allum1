/*
** ia_fct.c for allum1 in /home/blanqu_a/Workspace/rendu/Allum1
** 
** Made by Adrien Blanquer
** Login   <blanqu_a@epitech.net>
** 
** Started on  Mon Feb 16 17:41:20 2015 Adrien Blanquer
** Last update Tue Feb 17 12:14:48 2015 Adrien Blanquer
*/

#include <stdio.h>
#include "my.h"

int		search_data(t_list *list, int nb)
{
  t_list	*tmp;

  tmp = list;
  while (tmp != list->prev)
    {
      if (tmp->data == nb)
	return (1);
      tmp = tmp->next;
    }
  if (tmp->data == nb)
    return (1);
  return (0);
}

void		*two_lines(t_list *list)
{
  if (check_pyramide(list) > 2)
    {
      if (search_data(list, 1) == 1)
	{
	  while (list->data < 2)
	    list = list->next;
	  delete_allum(&list, list->data);
	}
      else
	{
	  if (check_pyramide(list) > 1 && list->data > 2)
	    delete_allum(&list, list->data - 2);
	  else
	    delete_allum(&list, 1);
	}
    }
  else
    {
      while (list->data == 0)
	list = list->next;
      delete_allum(&list, 1);
    }
  return (list);
}

int		count_line(t_list *list)
{
  int		i;
  t_list	*tmp;

  tmp = list;
  i = 0;
  while (tmp != list->prev)
    {
      if (tmp->data > 0)
	i++;
      my_put_nbr(tmp->data);
      tmp = tmp->next;
    }
  my_put_nbr(tmp->data);
  if (tmp->data > 0)
    i++;
  return (i);
}

void	*pair(t_list *tmp, t_list *list)
{
  while (tmp->data == 0 && tmp != list)
    tmp = tmp->next;
  if (tmp->data > 1)
    delete_allum(&tmp, 1);
  else
    delete_allum(&tmp, tmp->data);
  return (tmp);
}

void	*impair(t_list *tmp, t_list *list)
{
  while (tmp->data == 0 && tmp != list)
    tmp = tmp->next;
  delete_allum(&tmp, tmp->data);
  return (tmp);
}

