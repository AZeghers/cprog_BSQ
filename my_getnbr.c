/*
** my_getnbr.c for  in /home/zegher_a/Modules/C_Prog_Elem/CPE_2015_BSQ
** 
** Made by alexis zeghers
** Login   <zegher_a@epitech.net>
** 
** Started on  Sun Dec 20 17:44:34 2015 alexis zeghers
** Last update Sun Dec 20 17:52:53 2015 alexis zeghers
*/

#include "include/head.h"

int	getnbr(char *str)
{
  int	count;
  int	s;
  int	nbr;

  s = 1;
  count = 0;
  while (str[count] != '\0' && (str[count] == '+' || str[count] == '-'))
    {
      if (str[count] == '-')
	s = s * -1;
      count = count + 1;
    }
  str = str + count;
  nbr = 0;
  count = 0;
  while (str[count] >= '0' && str[count] <= '9')
    {
      nbr = nbr * 10;
      nbr = nbr + (str[count] - '0');
      count = count + 1;
    }
  return (nbr * s);
}
