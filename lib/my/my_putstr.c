/*
** my_putstr.c for allum1 in /home/blanqu_a/Workspace/rendu/Allum1
** 
** Made by Adrien Blanquer
** Login   <blanqu_a@epitech.net>
** 
** Started on  Mon Feb  2 14:03:55 2015 Adrien Blanquer
** Last update Mon Feb  2 14:04:49 2015 Adrien Blanquer
*/

#include <unistd.h>
#include "my.h"

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    write(1, &str[i++], 1);
}
