/*
** delete_allum.c for allum1 in /home/blanqu_a/Workspace/rendu/Allum1
** 
** Made by Adrien Blanquer
** Login   <blanqu_a@epitech.net>
** 
** Started on  Mon Feb  2 16:47:45 2015 Adrien Blanquer
** Last update Tue Feb 17 12:09:25 2015 Adrien Blanquer
*/

#include <stdlib.h>
#include "my.h"

int	delete_allum(t_list **list, int nb)
{
  (*list)->nb = 1;
  if (nb == 0)
    return (0);
  if ((*list)->data - nb >= 0 && (check_pyramide(*list) - nb) > 0)
    {
      (*list)->data -= nb;
      return (1);
    }
  return (0);
}
