//#include "map_data.h"
#include <stdio.h>

typedef struct s_map_data
{
    int cols;
    int rows;
    int **int_map;
} map_data;

// Note: int_map cols = cols +1 , rows = rows +1;

// Example of int map that we get:
// [
// [0 , 0 , 0 , 0 , 0 , 0 , 0]
// [0 ,-1 ,-1 ,-1 ,-1 ,-1 ,-1]
// [0 ,-1 ,-1 ,-1 ,-1 ,-1 ,-1]
// [0 ,-1 , 0 ,-1 ,-1 ,-1 ,-1]
// [0 ,-1 ,-1 ,-1 ,-1 ,-1 ,-1]
// [0 ,-1 ,-1 , 0 ,-1 ,-1 ,-1]
// ]

// 0 is the obstacle
// -1 is the empty cell
// We will fill this map with the number that egal 1 + the minimum number betwen the left, top and top left of the current cell
// If the current cell is an obstacle, we will leave it 0
// we start from int_map[1][1] to int_map[rows + 1][cols + 1]

int min(int a, int b)
{
    if (a < b)
        return a;
    return b;
}

void fill_int_map(map_data *map)
{
    int i;
    int j;

    // print all map rows cols values
    printf("rows: %d", map->rows);
    printf("cols: %d", map->cols);
    
    i = 1;
    while (i < map->rows)
    {
        j = 1;
        while (j < map->cols)
        {
            map->int_map[i][j] = 1 + min(map->int_map[i-1][j], min(map->int_map[i][j-1], map->int_map[i-1][j-1]));
            j++;
        }
        i++;
    }
}

