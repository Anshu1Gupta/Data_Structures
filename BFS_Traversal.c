#include<stdio.h>
#include<stdlib.h>
 
struct circularQueue
{
    int size;
    int f;
    int r;
    int* arr;
};
 
 
int isEmpty(struct circularQueue *q){
    if(q->r==q->f){
        return 1;
    }
    return 0;
}
 
int isFull(struct circularQueue *q){
    if((q->r+1)%q->size == q->f){
        return 1;
    }
    return 0;
}
 
void enqueue(struct circularQueue *q, int val){
    if(isFull(q)){
        printf("This Queue is full");
    }
    else{
        q->r = (q->r +1)%q->size;
        q->arr[q->r] = val; 
        printf("Enqueue element: %d\n", val);
    }
}
 
int dequeue(struct circularQueue *q){
    int a = -1;
    if(isEmpty(q)){
        printf("This Queue is empty");
    }
    else{
        q->f = (q->f +1)%q->size;
        a = q->arr[q->f]; 
    }
    return a;
}
 
   int visited[7]={0};
     int A[7][7]={ {1,0,0,1,0,0,1},
              {0,1,0,0,1,0,1},
              {1,0,1,0,0,1,0},
              {1,0,1,1,0,0,1},
              {1,0,0,1,1,0,0},
              {1,1,1,0,0,0,0},
              {1,1,1,0,0,0,0,}};
   void BFS(int i){
   
    struct circularQueue *q=(struct queue*)malloc(sizeof(struct circularQueue)); ;
    q->size = 100;
    q->f = q->r = 0;
    q->arr = (int*) malloc(q->size*sizeof(int));
    int u;
    printf("%d\n",i);
    visited[i]=1;
    enqueue(q,i);
    while(!isEmpty(q)){
        u=dequeue(q);
        for(int v=1;v<=7;v++){
          if(A[u][v]==1 && visited[v]==0){
            printf("%d\n",v);
            visited[v]=1;
            enqueue(q,v);
          }
        }
    }
   }
   
   void DFS(int i){
   
       
               printf("%d\n",i);
               visited[i]=1;
        
        for(int x=1;x<=7;x++){
            if(A[i][x]==1 &&visited[x]==0)
            {
                DFS(x);
            }
        }
   }
int main(){
    
  
   BFS(1);
    
    
    // Enqueue few elements
    // enqueue(&q, 12);
    // enqueue(&q, 15);
    // enqueue(&q, 1); 
    // printf("Dequeuing element %d\n", dequeue(&q));
    // printf("Dequeuing element %d\n", dequeue(&q));
    // printf("Dequeuing element %d\n", dequeue(&q)); 
    // enqueue(&q, 45);
    // enqueue(&q, 45);
    // enqueue(&q, 45);
 
    // if(isEmpty(&q)){
    //     printf("Queue is empty\n");
    // }
    // if(isFull(&q)){
    //     printf("Queue is full\n");
    // }
 
    return 0;
}
