#include <stdio.h>

void firstFit(int blockSize[], int m, int processSize[], int n){
    int i,j;
    int allocation[n];

    for(i=0; i<n; i++){
        allocation[i] = -1;
    }

    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            if(blockSize[j] >= processSize[i]){
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }

    printf("\nProcess No\tProcess Size\tBlock No.\n");
    for(i=0; i<n; i++){
        printf("%d\t\t",i+1);
        printf("%d\t\t",processSize[i]);
        if(allocation[i] != -1){
            printf("%i",allocation[i]+1);
        }else{
            printf("Not Allocated");
        }printf("\n");
    }
}

int main(){
    int m,n;
    int blockSize[5];
    int processSize[4];
    printf("Enter the block's size: ");
    for(int i =0; i<5; i++){
        scanf("%d",&blockSize[i]);
    }
    printf("Enter the process's Size: ");
    for(int i =0; i<4; i++){
        scanf("%d",&processSize[i]);
    }
    m = sizeof(blockSize)/sizeof(blockSize[0]);
    n = sizeof(processSize)/sizeof(processSize[0]);

    firstFit(blockSize,m,processSize,n);
    return 0;
}