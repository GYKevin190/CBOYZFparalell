#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include "sequential.h"
#define N 12


int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Error! You need to give 1 int as input!.\n");
        return 1;
    }
    srand(time(NULL));
    int i;
    int j;
    int k;
    int succsses_count=0;
    int card;
    int sim_count=atoi(argv[1]);
    int cards[N];
    clock_t start= clock();
    for (i=0; succsses_count<sim_count ; i++){
        k=0;
        for(j=0; j<N;j++){
            cards[j]=0;
        }
        while(sum_array(cards) <21){
            card=rand()/(RAND_MAX/9)+2;
            cards[k]=card;
            k++;
            if (sum_array(cards)==21){
                succsses_count++;
            }
        }
    }
    clock_t end = clock();
    float time_taken=(float)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken: %lf", time_taken);
    return 0;
}

int sum_array(int array[]){
    int sum=0;
    int i=0;
    while( array[i]!=0){
        sum+=array[i];
        i++;
    }
    return sum;

}
