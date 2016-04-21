/*
** my_strncmp.c for my_select in /home/blanqu_a/Workspace/rendu/PSU_2014_my_select
** 
** Made by Adrien Blanquer
** Login   <blanqu_a@epitech.net>
** 
** Started on  Tue Jan  6 15:01:20 2015 Adrien Blanquer
** Last update Tue Jan  6 15:02:42 2015 Adrien Blanquer
*/

#include "my.h"

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;

  i = 0;
  while (i < n)
    {
      if (s1[i] != s2[i])
	return (0);
      i++;
    }
  return (1);
}
