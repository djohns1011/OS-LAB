#include <stdio.h>
#include <stdlib.h>

int main(){
    int pid, pid1, pid2;
    if(pid ==1){
        printf("ERROR in PROCESS CREATION\n");
        exit(1);
    }
    if(pid != 0){
        pid = getpid();
        printf("The Parent Process ID is %d\n",pid1);
    }else{
        pid2 = getpid();
        printf("The Child Process ID is %d\n",pid);
    }
}