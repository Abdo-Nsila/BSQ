#ifndef MAP_DATA_H
#define MAP_DATA_H

typedef struct map_data
{
    char **map;
    int cols;
    int rows;
    char empty;
    char obstacle;
    char full;
    int **int_map;
} map_data;

#endif