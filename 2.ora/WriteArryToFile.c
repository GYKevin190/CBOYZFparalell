#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void Write(int a, int b, int n);

int main()
{
    int lower, upper, n;
    srand(time(NULL));
    printf("Enter lower bound: ");
    scanf("%d", &lower);
    printf("Enter upper bound: ");
    scanf("%d", &upper);
    printf("Enter n : ");
    scanf("%d", &n);
    fugv(lower,upper,n);
    return 0;
}

void Write(int a, int b, int n){
for(int i=0; i<n;i++){
    FILE *fptr;
    int array[n];
    fptr = fopen("C:\\Egyetem\\ParAlgh\\2.ora\\array.txt","w");
    for(int i=0; i<n;i++){
        int num = (rand() % (b - a + 1)) + a;
        array[i]=num;
        //printf( "%d \n"  , array[i]);
        fprintf(fptr,"%d \n",array[i]);
    }
    }
}