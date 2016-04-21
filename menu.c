/*
** menu.c for allum1 in /home/blanqu_a/Workspace/rendu/Allum1
** 
** Made by Adrien Blanquer
** Login   <blanqu_a@epitech.net>
** 
** Started on  Tue Feb  3 15:15:04 2015 Adrien Blanquer
** Last update Tue Feb 17 13:00:11 2015 Adrien Blanquer
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int	gere_key_level(int cpt, char *buff)
{
  if ((buff[1] == '[' && buff[2] == 'A') && cpt < 2)
    cpt++;
  if ((buff[1] == '[' && buff[2] == 'C') && cpt < 2)
    cpt++;
  if ((buff[1] == '[' && buff[2] == 'B') && cpt > 1)
    cpt--;
  if ((buff[1] == '[' && buff[2] == 'D') && cpt > 1)
    cpt--;
  return (cpt);
}

int	gere_key_menu(int cpt, char *buff)
{
  if ((buff[1] == '[' && buff[2] == 'A') && cpt < 20)
    cpt++;
  if ((buff[1] == '[' && buff[2] == 'C') && cpt < 20)
    cpt++;
  if ((buff[1] == '[' && buff[2] == 'B') && cpt > 0)
    cpt--;
  if ((buff[1] == '[' && buff[2] == 'D') && cpt > 0)
    cpt--;
  return (cpt);
}

void	chose_level(t_menu *ptr, char *buff)
{
  clean(buff, 4);
  ptr->level = 1;
  while (*buff != '\n')
  {
    clean(buff, 4);
    clean_screen();
    my_putstr("Nombre de lignes: ");
    my_put_nbr(ptr->nb_line);
    my_putstr("\nNiveau 1: Facile / Niveau 2: Difficile: ");
    my_put_nbr(ptr->level);
    read(0, buff, 3);
    ptr->level = gere_key_level(ptr->level, buff);
  }
}

void			*menu()
{
  t_menu		*ptr;
  char			*buff;

  if ((ptr = malloc(sizeof(t_menu))) == NULL)
    return (NULL);
  ptr->nb_line = 6;
  buff = my_malloc(3);
  while (buff[0] != '\n')
    {
      clean(buff, 4);
      clean_screen();
      my_putstr("Nombre de lignes: ");
      my_put_nbr(ptr->nb_line);
      if (read(0, buff, 3) <= 0)
	break;
      ptr->nb_line = gere_key_menu(ptr->nb_line, buff);
    }
  ptr->level = 1;
  chose_level(ptr, buff);
  clean(buff, 4);
  my_putstr("\nPour commencer, appuyez sur entrée.\n");
  while (*buff != '\n')
    if (read(0, buff, 3) <= 0)
      break;
  return (ptr);
}
