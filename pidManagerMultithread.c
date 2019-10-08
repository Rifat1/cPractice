#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#define MIN_PID 300
#define MAX_PID 5000

int *pa;
int allocatedPID;


int allocate_map(void){

    if(MAX_PID-MIN_PID==0){
        return -1;
    }
    int arrayPid[MAX_PID-MIN_PID]={0};
    pa=arrayPid;
    printf("\nInitializes Data Structure \n");
    return 1;
}

int allocate_pid(void){
    
    for(int i=0;i<=(MAX_PID-MIN_PID);i++){
        if(pa[i]==0){
            pa[i]=1;
            allocatedPID=i+MIN_PID;
            // printf("\nAllocated PID: ");
            return allocatedPID;
        }
    }
    printf("Unable to Allocate a PID (all pid's are in use)");
    return -1;
}

void release_pid(int pid){
    pid=pid-MIN_PID;
    pa[pid]=0;
    printf("\nPID Released and ready for use: %d \n",pid+MIN_PID);
}

void * allocateAndRelease(void* params)        //function called by the created thread
{
    // int *value=(int*)params;
    int newPID = allocate_pid();       //allocates a pid
    printf("Allocated PID: %d\n",newPID);
    sleep(1);
    release_pid(newPID);           //pid released
}

int main(){
    allocate_map();

    pthread_t thread_list[100];

    for (int i = 0; i < 100; i++) {
        /** Create new thread
        * PARAMS: Thread id ref, Thread attribute ref, method name, values to pass as parameters
        */
        pthread_create(&thread_list[i],NULL,allocateAndRelease,NULL);
    }

    for (int i = 0; i < 100; i++) {
        pthread_join(thread_list[i],NULL);
    }

}

