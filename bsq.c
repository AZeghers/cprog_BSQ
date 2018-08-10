/*
** bsq.c for  in /home/zegher_a/Modules/C_Prog_Elem/CPE_2015_BSQ
** 
** Made by alexis zeghers
** Login   <zegher_a@epitech.net>
** 
** Started on  Wed Dec 16 11:24:12 2015 alexis zeghers
** Last update Mon Dec 21 13:33:43 2015 alexis zeghers
*/

#include "include/head.h"

void	put_err(int type)
{
  if (type == 1)
    {
      write(2, "Invalid argument or number of arguments\n", 40);
      exit(1);
    }
  else if (type == 2)
    {
      write(2, "The allocation failed\n", 22);
      exit(2);
    }
  else
    {
      write(2, "Invalid map\n", 12);
      exit(3);
    }
}

char	**str_to_tab(int fd, int rows, int cols, char **tab)
{
  int	i;
  int	tmp;

  i = 0;
  if ((tab = malloc(sizeof(char *) * rows + 2)) == NULL)
    put_err(2);
  while (i < rows)
    {
      if ((tab[i] = malloc(sizeof(char) * cols + 2)) == NULL)
	put_err(2);
      read(fd, tab[i], cols);
      read(fd, &tmp, 1);
      tab[i][cols] = 'o';
      tab[i][cols + 1] = 0;
      i++;
    }
  if (tmp != '\n')
    put_err(3);
  if ((tab[rows] = malloc(sizeof(char) * cols + 1)) == NULL)
    put_err(2);
  i = -1;
  while (++i < cols)
    tab[rows][i] = 'o';
  return (tab);
}

void	free_this(char **tab, int rows)
{
  int	i;

  i = -1;
  while (++i <= rows)
    free(tab[i]);
  free(tab);
}

void	draw_tab(char **tab, t_max sqr, int rows, int cols)
{
  int	x;
  int	y;
  int	i;

  i = -1;
  x = sqr.x;
  y = sqr.y;
  while ((y - sqr.y) < sqr.size)
    {
      while ((x - sqr.x) < sqr.size)
	{
	  tab[y][x] = 'x';
	  x++;
	}
      x = sqr.x;
      y++;
    }
  while (++i < rows)
    {
      write(1, tab[i], cols);
      write(1, "\n", 1);
    }
}

int	main(int argc, char **argv)
{
  int	fd;
  int	rows;
  char	**tab;
  int	cols;
  t_max	sqr;

  fd = 0;
  if (((fd = open(argv[1], O_RDONLY)) == -1) || argc == 1)
    put_err(1);
  rows = get_rows(fd);
  if (rows == 0)
    put_err(3);
  cols = get_cols(argv[1], rows);
  tab = str_to_tab(fd, rows, cols, tab);
  sqr = max_sqr(tab, rows, cols);
  draw_tab(tab, sqr, rows, cols);
  free_this(tab, rows);
  close(fd);
  return (0);
}
