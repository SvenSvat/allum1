/*
** my_getterm.c for test_env in /home/blanqu_a/Workspace/rendu/PSU_2014_my_select
** 
** Made by Adrien Blanquer
** Login   <blanqu_a@epitech.net>
** 
** Started on  Tue Jan  6 14:14:08 2015 Adrien Blanquer
** Last update Mon Feb  2 14:12:56 2015 Adrien Blanquer
*/

#include <stdlib.h>
#include "my.h"

char	*parsing(char *str)
{
  int	i;
  int	j;
  char	*tmp;

  i = 0;
  j = 0;
  if ((tmp = malloc(sizeof(char) * my_strlen(str))) == NULL)
    return (NULL);
  while (str[i] && str[i - 1] != '=')
    i++;
  while (str[i])
    tmp[j++] = str[i++];
  tmp[j] = '\0';
  return (tmp);
}

char	*my_getterm(char **env)
{
  int	i;

  i = 0;
  while (env[i])
    {
      if (my_strncmp("TERM", env[i], 4))
	return (parsing(env[i]));
      i++;
    }
  return (NULL);
}
