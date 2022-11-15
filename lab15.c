#include<stdio.h>
#include<stdlib.h>
struct queue{
    int size;
    int f;
    int r;
    int *arr;
};
void enqueue(struct queue *q,int data){
    if(q->f==(q->r+1)%q->size){
        printf("Queue is Full \n");
    }
    else{
        if(q->r==-1){
            q->r=0;
            q->f=0;
            q->arr[q->r]=data;
        }
        else{
            q->r=(q->r+1)%q->size;
            q->arr[q->r]=data;
        }
    }
}
    

int dequeue(struct queue*q){
        if(q->f==-1&&q->r==-1){
            printf("Queue is Empty\n");
            return;
        }
        else{
            if(q->f==q->r){
                int x=q->arr[q->f];
                q->f=-1;
                q->r=-1;
                return x;

            }
            else{
                int data=q->arr[q->f];
                q->f=(q->f+1)%q->size;
                return data;
            }
        }

}
    int main(){
    struct queue*q=(struct queue*)malloc(sizeof(struct queue));
    q->size=12;
    q->f=-1;
    q->r=-1;
    q->arr=(int*)malloc(sizeof(int)*q->size);

    for(int i=0;i<11;i++){
        enqueue(q,(i+1)*10);
    }
    for(int i=0;i<11;i++){
     printf("%d \t",dequeue(q));
    }
    printf("\n");
    printf("Again Enqueueing and dequeueing \n");
     for(int i=0;i<11;i++){
        enqueue(q,(i+1)*10);
    }
    for(int i=0;i<11;i++){
     printf("%d \t",dequeue(q));
    }
    printf("\nHence we can use used space many number of times in circular queue\n ");
    return 0;
}