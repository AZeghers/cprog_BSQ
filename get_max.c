/*
** get_max.c for  in /home/zegher_a/Modules/C_Prog_Elem/CPE_2015_BSQ
** 
** Made by alexis zeghers
** Login   <zegher_a@epitech.net>
** 
** Started on  Thu Dec 17 16:39:04 2015 alexis zeghers
** Last update Mon Dec 21 13:47:32 2015 alexis zeghers
*/

#include "include/head.h"

int		get_cols(char *path, int rows)
{
  struct stat	st;
  int		i;
  int		cols;
  int		tmp;

  tmp = rows;
  i = 2;
  stat(path, &st);
  while (tmp >= 10)
    {
      tmp = tmp / 10;
      i++;
    }
  if (((st.st_size - i) % rows) != 0)
    put_err(3);
  cols = ((st.st_size) - i) / rows - 1;
  return (cols);
}

int	get_rows(int fd)
{
  char	buff[12];
  int	stop;
  int	i;
  int	rows;

  i = 0;
  stop = 1;
  while (i < 12)
    buff[i++] = 0;
  i = 0;
  while (stop)
    {
      read(fd, &buff[i], 1);
      if (buff[i] == 0)
	put_err(3);
      if (buff[i] == '\n')
	stop = 0;
      i++;
    }
  rows = getnbr(buff);
  return (rows);
}
