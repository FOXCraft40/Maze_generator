/*
** gen.h for generator dante header in /home/fox/epitech/generator
** 
** Made by Fernand Matignon
** Login   <fernand.matignon@epitech.eu>
** 
** Started on  Mon May 15 05:32:49 2017 Fernand Matignon
** Last update Wed May 31 13:24:48 2017 Fernand Matignon
*/

#ifndef GEN_H_
#define GEN_H_

int	STAR;
int	g_debug;

void	my_putchar(char);
void	my_putstr(char *);
void	my_puttab(char **);
void	my_d_puttab(char **, int, int);
void	my_generator(int, int, int);
void	my_undo(int *, int *, int, int);
void	my_bait(int);
int	my_rand(int);
int     my_is_ok(char **, int, int);
char	**my_timeout(char **, int, int);
char	**first_path(char **);
char	**create_maze(int, int);
char	**draw_path(char **, int, int);
char    **no_perfect_maze(char **, int, int);
char    **draw_path_really(char **, int, int);

#endif
