#include <stdio.h>
const int N = 3;

float average(int length, int array[]);


int main(void)
{
    int scores [N];

    for(int i =0 ; i < N; i++){
        printf("Enter score #%i: ", i);
        scanf("%d", &(scores[i]));
    }

    printf("Average: %.2f\n", average(N, scores));
}


float average(int length, int array[]){
    float sum =0;

    for(int i = 0; i < length; i++) {
        sum += (float)array[i] / length;
    }
    return sum;
}

