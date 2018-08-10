/*
** algorithm.c for  in /home/zegher_a/Modules/C_Prog_Elem/CPE_2015_BSQ
** 
** Made by alexis zeghers
** Login   <zegher_a@epitech.net>
** 
** Started on  Thu Dec 17 16:37:34 2015 alexis zeghers
** Last update Mon Dec 21 14:05:00 2015 alexis zeghers
*/

#include "include/head.h"

int	find_max(char **tab, int r_c[2], int x_y[2], int max)
{
  int	i;
  int	j;
  int	stop;

  stop = 1;
  i = x_y[0];
  j = x_y[1];
  while ((stop == 1) && max <= r_c[1] && max <= r_c[0])
    {
      while (((j - x_y[1]) <= max) && (j <= r_c[0]) && (stop == 1))
	{
	  while (((i - x_y[0] <= max) && (i <= r_c[1]) && (stop == 1)))
	    {
	      if (tab[j][i] == 'o')
		stop = 0;
	      i++;
	    }
	  i = x_y[0];
	  j++;
	}
      j = x_y[1];
      if (stop == 1)
	max++;
    }
  return (max);
}

t_max	found_dot(char **tab, t_max sqr, int x_y[2], int r_c[2])
{
  int	max;

  max = 1;
  max = find_max(tab, r_c, x_y, max);
  if (max > sqr.size)
    {
      sqr.x = x_y[0];
      sqr.y = x_y[1];
      sqr.size = max;
    }
  return (sqr);
}

t_max	max_sqr(char **tab, int rows, int cols)
{
  int	x_y[2];
  int	r_c[2];
  t_max	sqr;
  int	stop;

  stop = 1;
  sqr.size = 0;
  x_y[0] = 0;
  x_y[1] = 0;
  r_c[0] = rows;
  r_c[1] = cols;
  while (x_y[1] < rows && stop == 1)
    {
      while (x_y[0] < cols && stop == 1)
	{
	  if (tab[x_y[1]][x_y[0]] == '.')
	    sqr = found_dot(tab, sqr, x_y, r_c);
	  x_y[0]++;
	  if (sqr.size >= (rows - x_y[1]))
	    stop = 0;
	}
      x_y[0] = 0;
      x_y[1]++;
    }
  return (sqr);
}
