/*
** check.c for check for generator in /home/fox/epitech/generator
**
** Made by Fernand Matignon
** Login   <fernand.matignon@epitech.eu>
**
** Started on  Thu May 11 16:04:43 2017 Fernand Matignon
** Last update Wed May 31 13:31:30 2017 Fernand Matignon
*/

#include <stdlib.h>
#include <unistd.h>
#include "gen.h"

char	**my_timeout(char **maze, int y, int x)
{
  int	w;
  int	i;

  i = 0;
  w = 0;
  x = x / 2;
  y = y / 2;
  while (i < y)
    {
      maze[w][i] = '*';
      i++;
    }
  while (w < x)
    {
      maze[w][i] = '*';
      w++;
    }
  while (maze[w][i] != '\0')
    {
      maze[w][i] = '*';
      i++;
    }
  return (maze);
}

char	**no_perfect_maze(char **maze, int abs, int y)
{
  int	luck;
  int	i;
  int	x;

  luck = 0;
  while (luck != (abs + y + y))
    {
      x = my_rand(y);
      i = my_rand(abs);
      maze[x][i] = '*';
      luck++;
    }
  return (maze);
}

void	my_undo(int *x, int *i, int r, int k)
{
  if (k == 1)
    {
      if (r == 0)
        *i += 1;
      else if (r == 1)
        *x += 1;
      else if (r == 2)
        *i -= 1;
      else if (r == 3)
        *x -= 1;
    }
  else if (k == 2)
    {
      if (r == 0)
	*i -= 1;
      else if (r == 1)
	*x -= 1;
      else if (r == 2)
	*i += 1;
      else if (r == 3)
	*x += 1;
    }
}

char	**draw_path_really(char **maze, int x, int i)
{
  int	res;
  int	r;
  int	omg;

  res = 0;
  omg = 0;
  while ((res <= 20) && (omg < 10))
    {
      if (res == -1)
	omg++;
      r = my_rand(4);
      my_undo(&x, &i, r, 1);
      if (x < 0)
	x = -x;
      if (i < 0)
	i = -i;
      res = my_is_ok(maze, x, i);
      if (((res == 10) || (res == 6) || (res == 20) || (res == 0) || (res == 12)) && (STAR++))
	{
	  maze[x][i] = '*';
	  if (g_debug == 1)
	    {
	      my_putstr("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
          my_putstr("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	      my_d_puttab(maze, x, i);
          usleep(20000);
	    }
	}
      else
	my_undo(&x, &i, r, 2);
    }
  return (maze);
}

int	my_is_ok(char **maze, int x, int i)
{
  int	ok;

  ok = 0;
  if ((maze[x] != NULL) && (maze[x][i] != '\0'))
    {
      if (maze[x][i] == '*')
	return (-1);
      if ((maze[x][i] == 'X') && (maze[x][i + 1] == '*'))
	ok += 6;
      if (maze[x][i - 1] == '*')
	ok += 6;
      if (maze[x + 1] == NULL);
      else if (maze[x + 1][i] == '*')
	ok += 10;
      if (x == 0);
      else if (maze[x - 1][i] == '*')
	ok += 10;
    }
  else
    ok = 84;
  return (ok);
}
