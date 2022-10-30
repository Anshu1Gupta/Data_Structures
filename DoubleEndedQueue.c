#include<stdio.h>
#include<stdlib.h>
struct queue{
    int size;
    int f;
    int r;
    int *arr;
};
void enrear(struct queue*q,int data){
 if(q->r<q->f){
    printf("Queue is Full at rear side\n");
 }
 else{
    q->r--;
    q->arr[q->r]=data;
 }
}
void enfront(struct queue*q,int data){
 if(q->f>q->r ){
    printf("Queue is Full at frontend\n");
 }
 else{
    q->f++;
    q->arr[q->f]=data;
    
    
 }
}
int defront(struct queue*q){
    if(q->f==-1){
        printf("\nQueue is Empty at front end\n");
       
    }
    else{
        
        int x=q->arr[q->f];
        q->f--;
        return x;
    }
}
int derear(struct queue*q){
    if(q->r==q->size){
        printf("\nQueue is Empty at rear side\n");
       
    }
    else{
        int y=q->arr[q->r];
        q->r++;
        return y;
       
        
    }
}
int main(){
struct queue*q=(struct queue *)malloc(sizeof(struct queue));
q->size=10;
q->f=-1;
q->r=q->size;

q->arr=(int*)malloc(sizeof(int)*q->size);

for(int i=1;i<=6;i++){
    enfront(q,i*10);
}


for(int i=1;i<=6;i++){
    enrear(q,i*10);
}

for(int i=1;i<=6;i++){
   printf("%d\n", derear(q));
}

}