/*
** my_put_nbr.c for my_put_nbr in /home/blanqu_a/recode
** 
** Made by Adrien Blanquer
** Login   <blanqu_a@epitech.net>
** 
** Started on  Fri Oct 24 11:25:31 2014 Adrien Blanquer
** Last update Wed Jan 28 11:07:31 2015 Adrien Blanquer
*/

#include "my.h"

void	my_put_nbr(int nb)
{
  int	div;

  if (nb >= 0 && nb <= 9)
    my_putchar(nb + 48);
  if (nb > 9)
    {
      div = 1;
      while (nb / div >= 10)
	div *= 10;
      while (div > 0)
	{
	  my_putchar(((nb / div) % 10) + 48);
	  div /= 10;
	}
    }
}
