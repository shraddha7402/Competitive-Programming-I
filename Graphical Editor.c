#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char **Pixel;
int *m, *n;

void Create(int m, int n) {
    int i, j;
    Pixel = malloc(sizeof (char*)*n * n);
    for (i = 0; i < m * n; i++)
        Pixel[i] = malloc(sizeof (char*)*m);
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++) {
            Pixel[i][j] = '0';
        }
}

void ColorOneSpot(int x, int y, char color) {
    Pixel[x - 1][y - 1] = color;
}

void ColorColumn(int x, int y1, int y2, char color) {
    int i;
    for (i = y1; i <= y2; i++)
        Pixel[x - 1][i] = color;
}

void ColorRow(int x1, int x2, int y, char color) {
    int i;
    for (i = x1; i <= x2; i++)
        Pixel[i][y - 1] = color;
}

void ColorSquare(int *x1, int x2, int y1, int y2, char color) {
    int i, j;
    for (i = x1 - 1; i < x2; i++)
        for (j = y1 - 1; j < y2; j++)
            Pixel[i][j] = color;
}

void ColorNeighbor(int x, int y, char color) {
    int i, j;
    Pixel[y][x] = color;
    for (i = x; i <= x + 2; i++)
        if (i >= 0 && i <= m) {
            for (j = y; j <= y + 2; j++) {
                if (Pixel[i][j] == 0 && j >= 0 && j <= n)
                    Pixel[i][j] = color;
                ColorNeighbor(x, y - 1, color);
                ColorNeighbor(x, y + 1, color);
                ColorNeighbor(x - 1, y, color);
                ColorNeighbor(x + 1, y, color);
            }
        }

}

int main(void) {
    int i, j;
    char Input;
    while (Input != 'X') {
        int x, y, x1, y1, x2, y2;
        char color, name[20];
        scanf("%1s", &Input);
        switch (Input) {
            case 'I':
                scanf("%d%d", &m, &n);
                Create(*m, *n);
                break;
            case 'L':
                scanf("%d%d%s", &x, &y, &color);
                ColorOneSpot(x, y, color);
                break;
            case 'V':
                scanf("%d%d%d%s", &x, &y1, &y2, &color);
                ColorColumn(x, y1, y2, color);
                break;
            case 'H':
                scanf("%d%d%d%s", &x1, &x2, &y, &color);
                ColorRow(x1, x2, y, color);
                break;
            case 'K':
                scanf("%d%d%d%d%s", &x1, &x2, &y1, &y2, &color);
                ColorSquare(x1, x2, y1, y2, color);
                break;
            case 'F':
                scanf("%d%d%s", &x, &y, &color);
                ColorNeighbor(x, y, color);
                break;
            case 'S':
                scanf("%s", &name);
                printf("%s\n", name);
                for (i = 0; i < m; i++) {
                    for (j = 0; j < n; j++)
                        printf("%s ", Pixel[i][j]);
                    printf("\n");
                }

                break;
            case 'X':break;
        }
    }
    free(Pixel);
    return 0;
}