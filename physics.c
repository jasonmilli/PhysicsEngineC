#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct particle {
    int x;
    int y;
    int vx;
    int vy;
    char symbol;
} particle;
char* drawGrid(particle part, char * is) {
    char *grid = malloc(616);
    strcpy(grid, "\n");
    int i;
    for (i = 0; i< 49; i++) {
        strcat(grid, "\n");
    }
    for (i = 0; i< 20; i++) {
        strcat(grid, "|");
        int j;
        for (j = 0; j < 20; j++) {
            if (j == part.x && i == part.y) {
                strcat(grid, "X");
            } else {
	        strcat(grid, " ");
            }
        }
        strcat(grid, "|\n");
    }
    for (i = 0; i < 22; i++) {
        strcat(grid, "@");
    }
    strcat(grid, "\n");
    strcat(grid, is);
    strcat(grid, "\n");
    return grid;
}
void moveR(particle *part) {
    part->x += part->vx;
    part->y += part->vy;
    if (part->x <= 0 || part->x >= 19) {
        part->vx = -part->vx;
    }
    if (part->y <= 0 || part->y >= 19) {
        part->vy = -part->vy;
    }
    //part->vy += 1;
}
int main() {
    int i;
    particle part;
    part.x = 2;
    part.y = 3;
    part.vx = 1;
    part.vy = 2;
    part.symbol = '*';
    for (i = 0; i< 200; i++) {
        char is[10];
        sprintf(is, "%d", i);
        char *grid= drawGrid(part,is);
        printf("%s",grid);
        free(grid);
        moveR(&part);
        usleep(200000);
    }
    return 0;
}
