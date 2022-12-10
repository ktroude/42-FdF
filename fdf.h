#ifndef FDF_H
#define FDF_H

#include "mlx/mlx.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct mlx_struct
{
    t_data  img;
    t_vars  vars;
}   t_mlx;

typedef struct map
{
    int **array;
    int l;
    int h;
}   t_map;

//  Parsing
t_map   parsing(int argc, char **argv);
int     check_arg(char **argv, int argc);
char    *map_to_str(int fd);
int     **str_to_array(char *str);
t_map   get_data(char *str, t_map map, int i, int j);

// mlx set up
t_mlx   init_mlx(t_mlx mlx);
t_mlx   loop_and_hooks(t_mlx mlx);
void    free_mlx(t_mlx mlx);
int     ft_close(int keycode, t_vars *vars);
int     ft_close_x(t_vars *vars);

//  Utils
void    print(char *str, int i);
char    *add_char(char *s1, char*s2);
int     ft_strlen(char *str);
char	**ft_split(char const *s, char c);
int     get_array_size(char *str);
int     ft_atoi(char *str);
t_map   init_map(char *str, t_map map, int *i);
int     get_line_size(char *str);

#endif
