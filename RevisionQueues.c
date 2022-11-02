//Building Queue using arrays;

#include<stdio.h>
#include<stdlib.h>
struct queue{
    int size;
    int f;
    int r;
    int *arr;
};
void enqueue(struct queue*q,int data){
    if(q->f==(q->r+1)%q->size){
        printf("Queue is full\n");
        return ;
    }
    else{
        if(q->r==-1){
            q->f=0;
            q->r=0;
            q->arr[q->r]=data;

        }
        else{
           q->r=(q->r+1)%q->size;
            q->arr[q->r]=data;
        }
    }
}
void dequeue(struct queue *q){
    if(q->f==-1&&q->r==-1){
        printf("Ques is Empty\n");
        return ;
    }
    else {
        if(q->f==q->r){
           
               int data=q->arr[q->f];
        printf("%d\n",data);
            q->f=-1;
            q->r=-1;
            // printf("Queue is Empty\n");
           
        }
         
        else{
        int data=q->arr[q->f];
        printf("%d\n",data);
        q->f=(q->f+1)%q->size;
    //    printf("%d\n",q->arr[q->f]);
        }
    }
}
// void display(struct queue*q){
// if(q->r==-1){
//     printf("Queue is Empty\n");
//     return ;
// }
// else{
//   while(q->f>q->r){
//     dequeue(q);
//   }
// }
// }
int main(){
    struct queue *q=(struct queue *)malloc(sizeof(struct queue));
    q->f=-1,q->r=-1;
    q->size=5;
    q->arr=(int*)malloc(sizeof(int)*q->size);
    enqueue(q,91);
    enqueue(q,34);
     enqueue(q,34);
    //   enqueue(q,34);
    //    enqueue(q,34);
//   dequeue(q);
//   dequeue(q);

//   dequeue(q);

//   dequeue(q);

//   dequeue(q);
//   dequeue(q);q
// dequeue(q);
  dequeue(q);
  dequeue(q);
  dequeue(q);
  dequeue(q);

  dequeue(q);
  dequeue(q);
  enqueue(q,67); dequeue(q);


//   printf("%d\n",dequeue(q));






}