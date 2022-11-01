#include<stdio.h>
#include<stdlib.h>
struct stack {
    int top;
    int *arr;
    int size;
};
 int A[7][7]=
{{0,0,0,0,0,0,0},
{0,0,1,1,0,0,0},
{0,0,0,0,1,1,0},
{0,0,0,0,1,1,1},
{0,0,0,0,0,1,1},
{0,0,0,0,0,0,0},
{0,0,0,0,0,0,0}};
int vi[7]={0};
int isFull(struct stack *s){
    if(s->top==s->size-1){
        return 1;
    }
    else{
        return 0;
    }
}
int isEmpty(struct stack *s){
    if(s->top==-1){
        return 1;
    }
    else{
        return 0;
    }
}
void push(struct stack*s,int data){
    if(isFull(s)){
        printf("Stack Overflow\n");
    }
    else{
        s->top++;
        s->arr[s->top]=data;
    }
}
int pop(struct stack *s){
    if(isEmpty(s)){
        printf("Can not Pop any more\n");
    }
    else{
        int data=s->arr[s->top];
        s->top--;
        return data;
    }

}
void DFS(struct stack *s,int i){
    

        
        vi[i]=1;
    for(int j=1;j<=7;j++){
  if(vi[j]==0&&A[i][j]==1){
    DFS(s,j);
    push(s,j);
  }
    }
    }
int main(){
    struct stack *s=(struct stack *)malloc(sizeof(struct stack ));
    s->size=100;
    s->arr=(int *)malloc(sizeof(struct stack)*s->size);
    s->top=-1;
     int i=2;
    DFS(s,i);
    push(s,i);
   while(!isEmpty(s)){
    printf("%d\n",pop(s));
   }
    
}