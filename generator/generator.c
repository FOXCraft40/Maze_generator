/*
** generator.c for Generator Dante in /home/fox/epitech/generator
**
** Made by Fernand Matignon
** Login   <fernand.matignon@epitech.eu>
**
** Started on  Tue May  9 03:35:02 2017 Fernand Matignon
** Last update Wed May 31 13:22:38 2017 Fernand Matignon
*/

#include <stdlib.h>
#include <time.h>
#include "gen.h"

char		**create_maze(int abs, int y)
{
  int		i;
  int		x;
  char		**maze;

  x = 0;
  maze = malloc(sizeof(char *) * (y + 1));
  while (x != y)
    {
      i = 0;
      maze[x] = malloc(sizeof(char) * abs + 1);
      while (i != abs)
	maze[x][i++] = 'X';
      maze[x][i - 1] = '*';
      maze[x++][i] = '\0';
    }
  maze[x] = NULL;
  return (maze);
}

int		my_rand(int mod)
{
  srand(rand() + time(NULL));
  return (rand() % mod);
}

char		**first_path(char **maze)
{
  maze[0][0] = '*';
  maze = draw_path_really(maze, 0, 0);
  return (maze);
}

char		**draw_path(char **maze, int abs, int y)
{
  int		rand_x;
  int		rand_i;

  maze = first_path(maze);
  while ((STAR * 100) / (abs * y) < 50)
    {
      rand_x = my_rand(y);
      rand_i = my_rand(abs);
      if ((maze[rand_x][rand_i] == '*') && (rand_i < abs -1))
	maze = draw_path_really(maze, rand_x, rand_i);
    }
  return (maze);
}

void		my_generator(int x, int y, int perfect)
{
  char		**maze;

  maze = create_maze(x, y);
  maze = draw_path(maze, x, y);
  if (perfect != 0)
    maze = no_perfect_maze(maze, x, y);
  my_putstr("\n\n\nMaze Generated : \n\n");
  my_puttab(maze);
}
