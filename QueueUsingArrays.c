#include<stdio.h>
#include<stdlib.h>
struct Queue{
    int f;
    int r;
    int size;
    int *arr;
};
void enqueue(struct Queue*q,int data){
 if(q->r==q->size-1){
    printf("Queue is Full\n");
 }
 else{
    q->r++;
    q->arr[q->r]=data;
 }
}
int dequeue(struct Queue*q){
    if(q->f==q->r){
        printf("\nQueue is Empty\n");
       
    }
    else{
        q->f++;
        return q->arr[q->f];
    }
}
int main(){
 struct Queue*q =(struct Queue*)malloc(sizeof(struct Queue));
    q->f=-1;
    q->r=-1;
    q->size=100;
    q->arr=(int *)malloc(sizeof(int)*q->size);
    for(int i=0;i<q->size;i++){
 enqueue(q,i+1);
    } 
    for(int i=0;i<q->size;i++){
      printf("%d\n", dequeue(q));
    }
    

}