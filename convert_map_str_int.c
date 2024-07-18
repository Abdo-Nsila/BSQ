#include "map_data.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void fill_int_map(map_data *map);

void concert_map_str_int(map_data *map) {
    int i;
    int j;

    i = 0;
    map->int_map = (int **)malloc(sizeof(int *) * (map->rows + 1));
    while (i <= map->rows) {
        map->int_map[i] = (int *)malloc(sizeof(int) * (map->cols + 1));
        j = 0;
        while (j <= map->cols) {
            if (i == 0 || j == 0) {
                map->int_map[i][j] = 0;
            } else {
                if (map->map[i-1][j-1] == map->obstacle)
                    map->int_map[i][j] = 0;
                else
                    map->int_map[i][j] = -1;
            }
            j++;
        }
        i++;
    }
}

int main() {
    map_data map;
    map.rows = 5;
    map.cols = 5;
    map.empty = '.';
    map.obstacle = '0';
    
    // Allocate and initialize map.map
    // ....
    // ....
    // 0...
    // .0..
    
    // fill map using malloc and strdup or cpy
    map.map = (char **)malloc(sizeof(char *) * map.rows);
    for (int i = 0; i < map.rows; i++) {
        map.map[i] = (char *)malloc(sizeof(char) * (map.cols + 1));
        // Example initialization, should be replaced with actual data
        strcpy(map.map[i], "....");
    }
    strcpy(map.map[2], "0...");
    strcpy(map.map[3], ".0..");


    concert_map_str_int(&map);
    fill_int_map(&map);
    
    // Print the integer map
    for (int i = 0; i <= map.rows; i++) {
        for (int j = 0; j <= map.cols; j++) {
            printf("%d ", map.int_map[i][j]);
        }
        printf("\n");
    }
    
    // Free allocated memory for map.map
    for (int i = 0; i < map.rows; i++) {
        free(map.map[i]);
    }
    free(map.map);
    
    // Free allocated memory for map.int_map
    for (int i = 0; i <= map.rows; i++) {
        free(map.int_map[i]);
    }
    free(map.int_map);

    return 0;
}
