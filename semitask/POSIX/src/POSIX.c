#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include<windows.h>
#include <math.h>
#include "posix.h"



int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Error! You need to give 2 int number as input.\n");
        return 1;
    }
    int thread_num = atoi(argv[1]);

    int succses_needed_input = atoi(argv[2]);
    float values[thread_num];
    pthread_t thread[thread_num];
    float real_succses_needed = (float) succses_needed_input/thread_num;
    int succses_needed=  round(real_succses_needed);
    int i;

    for (i = 0; i < thread_num; i++) {
        pthread_create(&thread[i], NULL, generate_blackjack, (void *) &succses_needed);
    }

    for (i = 0; i < thread_num; i++) {
        void *result;
        pthread_join(thread[i], &result);
        values[i] = *((float *) result);
        free(result);
    }

    for (i = 0; i < thread_num; i++) {
        printf("Times taken for thread %d : %f \n", i+1, values[i]);
    }

    return 0;
}

void *generate_blackjack(void *ptr) {
    int number = *(int *) ptr;
    clock_t start= clock();
    float *f = malloc(sizeof(float));
    int i;
    int j;
    int k;
    int succsses_count=0;
    int card;
    int cards[12];
    for (i=0; succsses_count<number ; i++){
        k=0;
        for(j=0; j<12;j++){
            cards[j]=0;
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
    //printf("az ido itt: %lf \n",(float)(end - start) / CLOCKS_PER_SEC  );
    *f = (float)(end - start) / CLOCKS_PER_SEC;
    return (void*)f;
    
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