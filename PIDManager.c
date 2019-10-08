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
            printf("\nAllocated PID: ");
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
int main(){
    allocate_map();
    printf("%d ",allocate_pid());
    printf("%d \n",allocate_pid());
    release_pid(300);
    printf("%d ",allocate_pid());
    printf("%d \n",allocate_pid());
}

