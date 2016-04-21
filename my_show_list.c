/*
** my_show_list.c for allum1 in /home/blanqu_a/Workspace/rendu/Allum1
** 
** Made by Adrien Blanquer
** Login   <blanqu_a@epitech.net>
** 
** Started on  Mon Feb  2 14:06:22 2015 Adrien Blanquer
** Last update Mon Feb 16 13:58:16 2015 Adrien Blanquer
*/

#include "my.h"

void	print_spaces(int nb)
{
  int	i;

  i = 0;
  while (i < nb)
    {
      my_putchar(' ');
      i++;
    }
}

void	print_allum(t_list *tmp)
{
  int	i;

  i = 0;
  while (i < tmp->data)
    {
      if (tmp->select == 1)
	{
	  set_mr();
	  while (i < tmp->nb)
	    {
	      my_putchar('|');
	      i++;
	    }
	  set_back();
	}
      if (i < tmp->data)
	my_putchar('|');
      i++;
    }
  if (tmp->select == 1 && tmp->data == 0)
    {
      set_mr();
      my_putchar(' ');
      set_back();
    }
}

void		my_show_list(t_list *list, int size)
{
  t_list	*tmp;

  tmp = list;
  while (tmp != list->prev)
    {
      print_spaces(size - 1);
      print_allum(tmp);
      tmp = tmp->next;
      size--;
      my_putchar('\n');
    }
  print_allum(tmp);
}
