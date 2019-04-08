/*
** main.c for Main generator Dante in /home/fox/epitech/generator
**
** Made by Fernand Matignon
** Login   <fernand.matignon@epitech.eu>
**
** Started on  Sat May  6 16:57:18 2017 Fernand Matignon
** Last update Wed May 31 13:29:32 2017 Fernand Matignon
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "gen.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i++;
    }
}

void	my_d_puttab(char **tab, int c, int y)
{
  int   x;
  int	i;

  x = 0;
  while (tab[x] != NULL)
    {
      i = 0;
      while (tab[x][i] != '\0')
	{
	  if ((x == c) && (i == y))
	    {
	      my_putstr("\033[31m");
	      my_putchar(tab[x][i]);
	      my_putstr("\033[0m");
	    }
	  else
	    my_putchar(tab[x][i]);
	  i++;
	}
      my_putchar('\n');
      x++;
    }
}

void	my_puttab(char **tab)
{
  int	x;

  x = 0;
  while (tab[x] != NULL)
    {
      my_putstr(tab[x]);
      my_putchar('\n');
      x++;
    }
}

void    my_bait(int x)
{
  int   b;

  b = 0;
  while (b < x)
    {
      my_putchar('*');
      b++;
    }
  b = 0;
  my_putchar('\n');
  while (b < x - 1)
    {
      my_putchar('X');
      b++;
    }
  my_putstr("*\n");
}

int	main(int ac, char **av)
{
  char	buffer[10];

  printf("Voulez vous afficher le debug (beaucoup plus lent !) (yes/No)\n");
  buffer[read(0, buffer, 4)] = '\0';
  if (strcmp(buffer, "yes\n") == 0)
      g_debug = 1;
  if (ac < 3 || ac > 4)
    return (0);
  if (atoi(av[2]) == 2)
    my_bait(atoi(av[1]));
  else if (ac == 3)
    my_generator(atoi(av[1]), atoi(av[2]), -1);
  else
    my_generator(atoi(av[1]), atoi(av[2]), strcmp(av[3], "perfect"));
  return (0);
}
