#include<stdio.h>
#include<stdlib.h>
struct queue{
    int size;
    int f;
    int r;
    int *arr;
};
struct node{
    int data;
    struct nod* next;
};
struct arr{
    int size;
    int *a;
};
int isEmpty(struct queue*q){
    if(q->f==q->r){
        return 1;
    }
    else {
        return 0;
    }
}
int isFull(struct queue*q){
    if((q->r+1)%q->size==q->f){
        return 1;
    }
    else return 0;
}
int dequeue(struct queue*q){

if(q->f==q->r){
       return 0;
    }
    else{
        q->f=(q->f+1)%q->size;
       return q->arr[q->f];
    }
}
void enqueue(struct queue*q,int data){
    if(isFull(q)){
        printf("Queue is Full\n");
    }
    else{
        q->r=(q->r+1)%q->size;
        q->arr[q->r]=data;
    }
}
 int A[7][7]={{0,1,0,1,0,0,0},
             {0,0,1,1,0,0,0},
             {0,1,0,0,1,0,0},
             {0,1,0,0,1,0,0},
             {0,0,1,1,0,1,1},
             {0,0,0,0,1,0,0},
             {0,0,0,0,1,0,0}};

  void BFS(int i){
    struct queue*q=(struct queue*)malloc(sizeof(struct queue)); 
    q->f=q->r=0;
    q->size=100;
    q->arr=(int *)malloc(sizeof(int)*q->size); 
    struct arr *visited=(struct arr*)malloc(sizeof(struct arr));
    visited->size=100;
    visited->a=(int *)calloc(sizeof(int),visited->size);
int u;

printf("%d ",i);
visited->a[i]=1;
enqueue(q,i);
while(!(q->f==q->r)){
    u=dequeue(q);
    for(int v=1;v<=7;v++){
    if(A[u][v]==1 && visited->a[v]==0){
        printf("%d ",v);
        visited->a[v]=1;
        enqueue(q,v);
    }
    }
}
}
  
  int visit[8]={0};
  void DFS(int i){
  printf("%d ",i);
   visit[i]=1;
  for(int v=1;v<=7;v++){
    if(A[i][v]==1&& visit[v]==0){
        DFS(v);
    }
  }
  }
int main(){
    printf("BFS TRAVERSAL\n");
    BFS(1);
    printf("\n");
    printf("DFS Traversal\n");
    DFS(1);


}