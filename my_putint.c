/*
** my_putint.c for allum1 in /home/blanqu_a/Workspace/rendu/Allum1
** 
** Made by Adrien Blanquer
** Login   <blanqu_a@epitech.net>
** 
** Started on  Mon Feb  2 15:14:57 2015 Adrien Blanquer
** Last update Mon Feb  2 15:16:40 2015 Adrien Blanquer
*/

#include <unistd.h>
#include "my.h"

int	my_putint(int i)
{
  write(1, &i, 1);
  return (0);
}
