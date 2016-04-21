/*
** term_mod.c for allum1 in /home/blanqu_a/Workspace/rendu/Allum1
** 
** Made by Adrien Blanquer
** Login   <blanqu_a@epitech.net>
** 
** Started on  Mon Feb  2 15:42:05 2015 Adrien Blanquer
** Last update Tue Feb  3 14:14:13 2015 Adrien Blanquer
*/

#include <term.h>
#include <curses.h>
#include <termios.h>
#include <stdlib.h>
#include "my.h"

void	cursor_off()
{
  char	*res;

  if ((res = tgetstr("vi", NULL)) == NULL)
    exit(0);
  if (tputs(res, 0, my_putint) == ERR)
    exit(0);
}

void	cursor_on()
{
  char	*res;

  if ((res = tgetstr("ve", NULL)) == NULL)
    exit(0);
  if (tputs(res, 0, my_putint) == ERR)
    exit(0);
}

void			mod_raw()
{
  struct termios	t;

  if (tcgetattr(0, &t) == -1)
    exit(0);
  t.c_lflag &= ~(ECHO | ICANON);
  t.c_cc[VMIN] = 1;
  t.c_cc[VTIME] = 0;
  if (tcsetattr(0, TCSANOW, &t) == -1)
    exit(0);
  cursor_off();
}

void	mod_canon(struct termios save)
{
  if (tcsetattr(0, TCSANOW, &save) == -1)
    exit(0);
  cursor_on();
}
