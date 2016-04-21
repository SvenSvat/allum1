/*
** ia.c for allum1 in /home/blanqu_a/Workspace/rendu/Allum1
** 
** Made by Adrien Blanquer
** Login   <blanqu_a@epitech.net>
** 
** Started on  Tue Feb  3 11:47:05 2015 Adrien Blanquer
** Last update Tue Feb 17 12:18:39 2015 Adrien Blanquer
*/

#include <stdio.h>
#include "my.h"

int	result(int ret, t_list *tmp)
{
  if (ret == 1)
    {
      clean_screen();
      my_show_list(tmp, how_many_data(tmp));
      my_putstr("\nPERDU");
      return (1);
    }
  else if (ret == 0)
    {
      my_putstr("\nGAGNE");
      return (1);
    }
  return (0);
}

int	check_entry(t_list *tmp, int total)
{
  if ((total = check_pyramide(tmp)) == 1)
    {
      my_putstr("GAGNE\n");
      return (1);
    }
  return (0);
}

int		ia_easy(t_list **list)
{
  t_list	*tmp;
  int		i;
  int		nb;

  i = 1;
  tmp = *list;
  if (check_entry(tmp, check_pyramide(tmp)) == 1)
    return (1);
  while ((i + 4) < check_pyramide(tmp))
    i += 4;
  nb = check_pyramide(tmp) - i;
  while (tmp != (*list)->prev && (tmp->data - nb) < 0)
    tmp = tmp->next;
  if ((tmp->data - nb) >= 0)
    tmp->data -= nb;
  else
    {
      tmp = *list;
      nb = 1;
      while (tmp != (*list)->prev && (tmp->data - nb) < 0)
	tmp = tmp->next;
      if ((tmp->data - nb) >= 0)
	tmp->data -= nb;
    }
  return (result(check_pyramide(tmp), tmp));
}

int		ia_hard(t_list **list)
{
  t_list	*tmp;
  int		i;

  tmp = *list;
  i = count_line(tmp);
  if (check_entry(tmp, check_pyramide(tmp)) == 1)
    return (1);
  while (tmp->data == 0)
    tmp = tmp->next;
  if (check_pyramide(tmp) == 5)
    ia_easy(&tmp);
  else if (i == 1)
    delete_allum(&tmp, tmp->data - 1);
  else if (i == 2)
    tmp = two_lines(tmp);
  else if (i == 3)
    tmp = three_lines(tmp);
  else if ((i > 1 && (i % 2) == 0))
    tmp = pair(tmp, (*list)->prev);
  else if (i > 1 && (i % 2) == 1)
    tmp = impair(tmp, (*list)->prev);
  return (result(check_pyramide(tmp), tmp));
}

int	ia_level(t_list	*list, int level)
{
  if (level == 1)
    return (ia_easy(&list));
  else
    return (ia_hard(&list));
}
