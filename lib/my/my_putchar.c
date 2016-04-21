/*
** my_putchar.c for allum1 in /home/blanqu_a/Workspace/rendu/Allum1
** 
** Made by Adrien Blanquer
** Login   <blanqu_a@epitech.net>
** 
** Started on  Mon Feb  2 13:55:24 2015 Adrien Blanquer
** Last update Mon Feb  2 13:56:27 2015 Adrien Blanquer
*/

#include <unistd.h>
#include "my.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}
