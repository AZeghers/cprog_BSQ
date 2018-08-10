/*
** head.h for  in /home/zegher_a/Modules/C_Prog_Elem/CPE_2015_BSQ
** 
** Made by alexis zeghers
** Login   <zegher_a@epitech.net>
** 
** Started on  Thu Dec 17 16:41:24 2015 alexis zeghers
** Last update Sat Dec 19 16:38:29 2015 alexis zeghers
*/

#ifndef HEAD_H_
# define HEAD_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

typedef struct	s_max
{
  int		x;
  int		y;
  int		size;
}		t_max;

/*
** Memory, main and error handling
*/

void	put_err(int type);
char	**str_to_tab(int fd, int rows, int cols, char **tab);
void	free_this(char **tab, int rows);
void	draw_tab(char **tab, t_max sqr, int rows, int cols);

/*
** Initialisation
*/

int	get_rows(int fd);
int	get_cols(char *path, int rows);
int	getnbr(char *str);

/*
** Algorithm
*/

t_max	max_sqr(char **tab, int rows, int cols);
int	find_max(char **tab, int r_c[2], int x_y[2], int max);
t_max	found_dot(char **tab, t_max sqr, int x_y[2], int r_c[2]);


#endif /* HEAD_H_ */
