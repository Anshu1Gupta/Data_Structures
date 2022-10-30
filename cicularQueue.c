#include<stdio.h>
#include<stdlib.h>
struct queue{
    int f;
    int r;
    int size;
    int *arr;
};
void enqueue(struct queue*q,int data){
    if((q->r+1)%q->size==q->f){
        printf("Queue is FULL\n");
    }
    else {
        q->r=(q->r+1)%q->size;
        q->arr[q->r]=data;
    }
}
void dequeue(struct queue*q){
    if(q->f==q->r){
        printf("Queue is Empty\n");
    }
    else{
        q->f=(q->f+1)%q->size;
        printf("%d\n ",q->arr[q->f]);
    }
}


int main(){
    struct queue*q;
    q=(struct queue*)malloc(sizeof(struct queue));
    q->f=0;q->r=0;
    q->size=100;
    q->arr=(int *)malloc(sizeof(int)*q->size);
    for(int i=0;i<q->size-1;i++){
        enqueue(q,i+1);
    }
     for(int i=0;i<q->size-1;i++){
       dequeue(q);
    }
     printf("Again enqueued and dequeued\n");
     for(int i=0;i<q->size-1;i++){
        enqueue(q,i+1);
    }
    for(int i=0;i<q->size-1;i++){
       dequeue(q);
    }
   
}