/*
** gere_key.c for allum1 in /home/blanqu_a/Workspace/rendu/Allum1
** 
** Made by Adrien Blanquer
** Login   <blanqu_a@epitech.net>
** 
** Started on  Mon Feb  2 16:38:06 2015 Adrien Blanquer
** Last update Tue Feb 17 12:34:30 2015 Adrien Blanquer
*/

#include <stdlib.h>
#include "my.h"

int	gere_key(char *buff, t_list **tmp)
{
  if (buff[1] == '[' && buff[2] == 'A')
    {
      (*tmp)->nb = 1;
      *tmp = (*tmp)->prev;
      change_select(*tmp);
    }
  if (buff[1] == '[' && buff[2] == 'B')
    {
      (*tmp)->nb = 1;
      *tmp = (*tmp)->next;
      change_select(*tmp);
    }
  if (buff[1] == '[' && buff[2] == 'C')
    if ((*tmp)->nb < (*tmp)->data)
      (*tmp)->nb++;
  if (buff[1] == '[' && buff[2] == 'D')
    if ((*tmp)->nb > 1)
      (*tmp)->nb--;
  if (buff[0] == '\n')
    return (delete_allum(tmp, (*tmp)->nb));
  return (0);
}
