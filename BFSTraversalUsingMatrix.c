#include<stdio.h>
#include<stdlib.h>
struct arr{
    int size;
    int *a;
};
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
int dequeue(struct queue*q){
    if(q->f==q->r){
       return 0;
    }
    else{
        q->f=(q->f+1)%q->size;
       return q->arr[q->f];
    }
}

    int A[7][7]={{0,1,0,1,0,0,0},
             {0,0,1,1,0,0,0},
             {0,1,0,0,1,0,0},
             {0,1,0,0,1,0,0},
             {0,0,1,1,0,1,1},
             {0,0,0,0,1,0,0},
             {0,0,0,0,1,0,0}};

// void BFS(int i){
//     struct queue*q=(struct queue*)malloc(sizeof(struct queue));
//     q->size=100;
//     q->f=q->r=0;
//     q->arr=(int*)malloc(sizeof(int)*q->size);
//   struct arr *visited=(struct arr*)malloc(sizeof(struct arr));
//   visited->size=100;
//   visited->a=(int *)calloc(sizeof(int),visited->size);

// int u;
// printf("BFS TRAVERSAL\n");
// printf("%d ",i);
// visited->a[i]=1;
// enqueue(q,i);
// while(!(q->f==q->r)){
//     u=dequeue(q);
//     for(int v=1;v<=7;v++){
//     if(A[u][v]==1 && visited->a[v]==0){
//         printf("%d ",v);
//         visited->a[v]=1;
//         enqueue(q,v);
//     }
//     }
// }
// }
    int visit[8]={0};
void DFS(int i){

 struct queue*x=(struct queue*)malloc(sizeof(struct queue));
    // x->size=100;
    // x->f=x->r=0;
    // x->arr=(int*)malloc(sizeof(int)*x->size);
//   struct arr *visit=(struct arr*)malloc(sizeof(struct arr));
//   visit->size=100;
//   visit->a=(int *)calloc(sizeof(int),visit->size);
    if(visit[i]==0){
        printf("%d",i);
        visit[i]=1;
        for(int v=0;v<7;v++){
            if(A[i][v]==1 && visit[v]==0){
               DFS(v);
            }
        }
   
    }}

int main(){//  BFS(1);
 DFS(1);
}