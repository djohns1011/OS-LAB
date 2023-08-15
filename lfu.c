#include <stdio.h>

void print(int fc, int frame[]){
    int k;
    for(k=0;k<fc;k++){
        printf("%d\t",frame[k]);
    }printf("\n");
}

void main(){
    int page[20],frame[10],count[20];
    int flag,move=0,ct=0,repIndex,leastCount;
    int i,j,fc,pc;

    printf("Enter the no. of pages: ");
    scanf("%d",&pc);
    printf("Enter the pages: ");
    for(i=0;i<pc;i++){
        scanf("%d",&page[i]);
    }
    printf("Enter the no. of frames: ");
    scanf("%d",&fc);
    for(j=0;j<fc;j++){
        frame[j] = -1;
    }

    printf("Sequence \t Frames\n");
    
    for(i=0;i<pc;i++){
        printf("%d\t\t",page[i]);
        flag = 0;
        for(j=0;j<fc;j++){
            if(frame[j] == page[i]){
                flag = 1;
                count[j]++;
                printf("No Replacement\n");
                break;
            }
        }
        if((flag == 0) && (ct < fc)){
            frame[move] = page[i];
            count[move] = 1;
            move = (move + 1) % fc;
            ct++;
            print(fc,frame);
        }else if (flag == 0){
            repIndex = 0;
            leastCount = count[0];
            for(int k=0;k<fc;k++){
                if(count[k] < leastCount){
                    leastCount = count[k];
                    repIndex = k;
                }
            }
            frame[repIndex] = page[i];
            count[repIndex] = 1;
            ct++;
            print(fc,frame);
        }
    }
    printf("Total Page Faults: %d", ct);
}