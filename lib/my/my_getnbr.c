/*
** my_getnbr.c for my_getnbr in /home/blanqu_a/recode
** 
** Made by Adrien Blanquer
** Login   <blanqu_a@epitech.net>
** 
** Started on  Fri Oct 24 13:25:58 2014 Adrien Blanquer
** Last update Tue Jan 27 11:59:32 2015 Adrien Blanquer
*/

int	set_mult(char *str, int tmp)
{
  int	mult;

  mult = 1;
  while (str[tmp] && (str[tmp] >= '0' && str[tmp] <= '9'))
    {
      mult *= 10;
      tmp++;
    }
  return (mult);
}

int	my_getnbr(char *str)
{
  int	mult;
  int	i;
  int	sign;
  int	tmp;

  i = 0;
  sign = 1;
  while (str[i] == '-' || str[i] == '+')
    {
      if (str[i++] == '-')
	sign = sign * (-1);
    }
  tmp = i + 1;
  mult = set_mult(str, tmp);
  tmp = 0;
  while (str[i] && (str[i] >= '0' && str[i] <= '9'))
    {
      tmp += (str[i++] - '0') * mult;
      mult /= 10;
    }
  tmp *= sign;
  return (tmp);
}
