#include <stdio.h>
#include <pthread.h>

void *calcAverage(void *params);
void *calcMax(void *params);
void *calcMin(void *params);

float average;
int max;
int min;


int main(){
    
    pthread_t thread_list[3];

    int values[7];

    for (int i = 0; i < 7; i++) {
        printf("Enter a value: ");
        scanf("%d", &values[i]);
    }

    /** Create new thread
     * PARAMS: Thread id ref, Thread attribute ref, method name, values to pass as parameters
     */
    pthread_create(&thread_list[0], NULL, calcAverage, &values);
    pthread_create(&thread_list[1], NULL, calcMax, &values);
    pthread_create(&thread_list[2], NULL, calcMin, &values);        

    /** Wait for Thread to finish
     * PARAMS: thread to join, return value
     */
    pthread_join(thread_list[0], NULL);
    pthread_join(thread_list[1], NULL);
    pthread_join(thread_list[2], NULL);
}

void *calcAverage(void *params) {
    int *val_p = (int *) params;
    int sum;
    for(int i = 0; i < 7; i++){
        sum += val_p[i];
    }
    average = sum / (7.00);
    printf("Average: %.2f \n", average);
    pthread_exit(0);

}

void *calcMax(void *params) {
    int *val_p = (int *) params;
    int max=val_p[0];
    for(int i = 0; i < 7; i++){
        if(val_p[i]>max)
            max = val_p[i];
    }
    printf("Max: %d \n", max);
    pthread_exit(0);

}

void *calcMin(void *params) {
    int *val_p = (int *) params;
    int min=val_p[0];
    for(int i = 0; i < 7; i++){
        if(val_p[i]<min)
            min=val_p[i];
    }
    printf("Min: %d \n", min);
    pthread_exit(0);
}
