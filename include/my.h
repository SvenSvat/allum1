/*
** my.h for allum1 in /home/blanqu_a/Workspace/rendu/Allum1
** 
** Made by Adrien Blanquer
** Login   <blanqu_a@epitech.net>
** 
** Started on  Mon Feb  2 11:35:26 2015 Adrien Blanquer
** Last update Tue Feb 17 12:24:27 2015 Adrien Blanquer
*/

#ifndef MY_H_
# define MY_H_

#include <termios.h>

typedef struct		s_list
{
  int			nb;
  int			data;
  int			select;
  struct	s_list	*next;
  struct	s_list	*prev;
}			t_list;

typedef struct	s_menu
{
  int		nb_line;
  int		level;
}		t_menu;

void	my_putchar(char);
void	my_put_nbr(int);
void	my_putstr(char *);
void	my_show_list(t_list *, int);
void	set_mr(void);
void	set_back(void);
void	allum(t_list *, t_menu *);
void	clean_screen(void);
void	mod_raw(void);
void	mod_canon(struct termios);
void	clean(char *, int);
void	change_select(t_list *);
void	cursor_on(void);
void	cursor_off(void);
void	*menu(void);
void	*two_lines(t_list *);
void	*three_lines(t_list *);
void	*pair(t_list *, t_list *);
void	*impair(t_list *, t_list *);
char	*my_getterm(char **);
char	*my_malloc(int);
int	count_line(t_list *);
int	search_data(t_list *, int);
int	ia_level(t_list *, int);
int	gere_key(char *, t_list **);
int	delete_allum(t_list **, int);
int	check_pyramide(t_list *);
int	init_list(t_list **);
int	my_strlen(char *);
int	my_strncmp(char *, char *, int);
int	my_getnbr(char *);
int	my_putint(int);
int	how_many_data(t_list *);

#endif	/* !MY_H_ */
