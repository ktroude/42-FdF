#include "fdf.h"

t_map   init_map(char *str, t_map map, int *i)
{
    *i = 0;
    map.h = get_array_size(str);
    map.l = get_line_size(str);
    map.array = malloc(sizeof(int *) * map.h);
    if (!map.array)
        print("Error: malloc failed\n", 1);
    map.array[0] = malloc(sizeof(int) * map.l);
    while(str[*i] == ' ')
        *i++;
    return map;
}

int get_line_size(char *str)
{
    int i;
    int ret;

    i = 0;
    if (str[i] == ' ')
        ret = 0;
    else
        ret = 1;
    while (str[i])
    {   
        if (str[i] == ' ')
        {
            while (str[i] == ' ')
                i++;
            if (str[i] && str[i] != '\n')
                ret++;
        }
        i++;
    }
    return ret;
}

