#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <omp.h>
#include <math.h>
#include<windows.h>
#include"openmp.h"


int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Error! you need to give 2 int number as input!\n");
        return 1;
    }

    int thread_num = atoi(argv[1]);
    int succses_needed_input = atoi(argv[2]);
    float values[thread_num];

    float real_succses_needed = (float) succses_needed_input/thread_num;
    int succses_needed=  round(real_succses_needed);
    int i;

    #pragma omp parallel num_threads(thread_num)
    {
        #pragma omp for
        for (i = 0; i < thread_num; i++) {
            clock_t start= clock();
            int number = succses_needed;
            float f;
            int j;
            int k;
            int succsses_count=0;
            int card;
            int cards[12];
            for (j=0; succsses_count<number ; j++){
                k=0;
                for(int l=0; l<12;l++){
                    cards[l]=0;
                }
                while(sum_array(cards) <21 ){
                    card=rand()/(RAND_MAX/9)+2;
                    cards[k]=card;
                    k++;
                    if (sum_array(cards)==21){
                        succsses_count++;
                    }
                }
            }
            clock_t end = clock();
            f = (float)(end - start) / CLOCKS_PER_SEC;
            values[omp_get_thread_num()] = f;
        }
    }

    for (i = 0; i < thread_num; i++) {
        printf("The  %d. thread time taken was %f \n", i+1, values[i]);
    }
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