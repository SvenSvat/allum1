/*
** my_malloc.c for allum1 in /home/blanqu_a/Workspace/rendu/Allum1
** 
** Made by Adrien Blanquer
** Login   <blanqu_a@epitech.net>
** 
** Started on  Mon Feb  2 16:25:02 2015 Adrien Blanquer
** Last update Mon Feb  2 17:14:21 2015 Adrien Blanquer
*/

#include <stdlib.h>
#include "my.h"

void	clean(char *str, int nb)
{
  int	i;

  i = 0;
  while (i < nb)
    str[i++] = '\0';
}

char	*my_malloc(int size)
{
  char	*str;

  if ((str = malloc(sizeof(char) * (size + 1))) == NULL)
    exit(0);
  clean(str, size);
  return (str);
}
