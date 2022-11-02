#include<stdlib.h>
#include<stdio.h>

struct queue{
    int size;
    int r1;
    int r2;
    int f1;
    int f2;
    int *arr;
};
void enqueue(struct queue*q,int data){
    if(q->r1>=q->r2-1){
        printf("Queue Is Full\n");
    }
    else{
        if(q->r1==-1){
            q->f1=0;q->r1=0;
         q->arr[q->r1]=data;
        }
        else{
            q->r1++;
            q->arr[q->r1]=data;
        }
    }
}
void inject(struct queue *q,int data){
    if(q->r1>=q->r2-1){
        printf("Queue is Full\n");
    }
    else{
        if(q->r2==q->size){
            q->r2=q->size-1;
            q->f2=q->size-1;
        q->arr[q->r2]=data;
        }
        else{
            q->r2--;
            q->arr[q->r2]=data;
        }
    }
}
void dequeue(struct queue*q){
    if(q->f1==-1){
        printf("Queue is Empty from front\n");
    }
 else{
    if(q->f1==q->r1){
        printf("%d\n",q->arr[q->f1]);
        q->f1=-1;
        q->r1=-1;

    }
    else{
        printf(" Dequeued from front : %d \n",q->arr[q->f1]);
        q->f1++;
    }
 }
}
void eject(struct queue*q){
    if(q->f2==q->size){
        printf("Queue is Empty from back\n");
    }
 else{
    if(q->f2==q->r2){
        printf("%d\n",q->arr[q->f2]);
        q->f2=q->size;
        q->r2=q->size;

    }
    else{
        printf("Ejected from back: %d \n",q->arr[q->f2]);
        q->f2--;
    }
 }
}
int main(){
struct queue *q=(struct queue*)malloc(sizeof(struct queue));
q->size=10;
q->f1=-1;
q->r1=-1;
q->r2=q->size;
q->f2=q->size;


enqueue(q,89);
enqueue(q,89);

dequeue(q);



}