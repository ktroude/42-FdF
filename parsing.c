#include "fdf.h"

t_map   parsing(int argc, char **argv)
{
	int		fd;
	char	*str;
    t_map   map;

	if ((fd = check_arg(argv, argc)) < 0)
		exit(1);
	if ((str = map_to_str(fd)) == NULL)
		exit(1);
    map = str_to_struct(str);
	if (map.array == NULL)
        print("Error: parsing\n", 1);
    return map;
}

int check_arg(char **argv, int argc)
{
    int fd;

    if (argc != 2)
        print("Error: wrong argument\n", 1);
    if ((fd = open(argv[1], O_RDONLY)) == -1)
    {
        print("Error: can't open ", 0);
        print(argv[1], 0);
        print("\n", 1);
    }
    return fd;
}

// open file, get the map and put it in a str
char    *map_to_str(int fd)
{
    char    *str;
    char    buf[1];
    int     ret;

    str = NULL;
    while ((ret = read(fd, buf, 1)) != 0)
    {
        if (ret == -1)
            print("Error: read failed\n", 1);
        str = add_char(str, buf);
    }
    return (str);
}

t_map   str_to_struct(char *str)
{
    t_map   map;
    int     i;
    int     j;
    int     k;

    j = 0;
    k = 0;
    map = init_map(str, map, &i);
    map = get_data(str, map, i, j);
    return (map);
}

t_map   get_data(char *str, t_map map, int i, int j)
{
    int k;

    k = 0;
    while(str[i])
    {
        map.array[j][k++] = ft_atoi(&str[i]);
        if (k == map.l)
        {
            k = 0;
            j++;
            map.array[j] = malloc(sizeof(int) * map.l);
        }
        if (j == map.h)
            break ;
        while (str[i] && str[i] != ' ' && str[i] != '\n')
            i++;
        while (str[i] == ' ' || str[i] == '\n')
            i++;
    }
    return (map);
}
