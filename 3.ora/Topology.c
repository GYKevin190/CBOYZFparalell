#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define N 50
#define SIZE 12
#define CUBE_SIZE 5

int main() {
    int n, i, j, nodes, edges;
    double ratio;

    
    printf("Planar grid:\n");
    printf(" n Nodes Edge Ratio \n");
    for(n = 1; n <= N; n++) {
        nodes = n * n;
        edges = (n - 1) * n * 2;
        ratio = (double)edges / nodes;
        printf("%2d %12d %12d %12lf\n", n, nodes, edges, ratio);
    }


    int x1, y1, x2, y2, dist;
    int distances[SIZE * SIZE * SIZE] = {0};
    for(x1 = 0; x1 < SIZE; x1++) {
        for(y1 = 0; y1 < SIZE; y1++) {
            for(x2 = x1; x2 < SIZE; x2++) {
                for(y2 = y1; y2 < SIZE; y2++) {
                    dist = (int)round(sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
                    distances[dist]++;
                }
            }
        }
    }


    printf("\Distribution of distances between npoints in the case of a planar grid :\n");
    for(i = 0; i < SIZE * SIZE; i++) {
        printf("%2d: ", i);
        for(j = 0; j < distances[i]; j += 10) {
            printf("*");
        }
        printf("\n");
    }


    printf("\Spatial grid:\n");
    printf("n Nodes Edge Ratio \n");
    for(n = 1; n <= N; n++) {
        nodes = n * n * n;
        edges = (n - 1) * n * n * 3;
        ratio = (double)edges / nodes;
        printf("%2d %12d %12d %12lf\n", n, nodes, edges, ratio);
    }


    printf("\nNumber of edges :\n");
    printf("n Planar Spatial\n");
    for(n = 1; n <= N; n++) {
        int edges_sik = (n - 1) * n * 2;
        int edges_ter = (n - 1) * n * n * 3;
        printf("%2d %10d\n", n, edges_sik, edges_ter);


int x3, y3, z3, x4, y4, z4, dist3;
int distances3[CUBE_SIZE * CUBE_SIZE * CUBE_SIZE] = {0};
for(x3 = 0; x3 < CUBE_SIZE; x3++) {
    for(y3 = 0; y3 < CUBE_SIZE; y3++) {
        for(z3 = 0; z3 < CUBE_SIZE; z3++) {
            for(x4 = x3; x4 < CUBE_SIZE; x4++) {
                for(y4 = y3; y4 < CUBE_SIZE; y4++) {
                    for(z4 = z3; z4 < CUBE_SIZE; z4++) {
                        dist3 = (int)round(sqrt(pow(x4 - x3, 2) + pow(y4 - y3, 2) + pow(z4 - z3, 2)));
                        distances3[dist3]++;
                    }
                }
            }
        }
    }
}

printf("\Distribution of distances between npoints in the case of a spatial grid:\n");
for(i = 0; i < CUBE_SIZE * CUBE_SIZE * CUBE_SIZE; i++) {
    printf("%2d: ", i);
    for(j = 0; j < distances3[i]; j += 10) {
        printf("*");
    }
    printf("\n");
}

return 0;

}
}
