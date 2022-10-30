#include<stdio.h>
#include<stdlib.h>
struct node*f=NULL;
struct node* r=NULL;
struct node{
    int data;
    struct node* next;
};
struct node*createNode(int data){
    struct node*new=(struct node*)malloc(sizeof(struct node));
    new->next=NULL;
    new->data=data;
    return new;
}
int  Dequeue(){
    int val=-1;
  if(f==NULL){
    printf("No Element found\n");
  
  }
  else{
   struct node*ptr=f;
    f=f->next;
     val=ptr->data;
    free(ptr);
  }
  return val;
}

void enqueue(int data){
      struct node*n=createNode(data);
    if(n==NULL){
        printf("Enqueue is not possible\n");
    }
   else{
         if(f==NULL){
            f=r=n;
         }
        else{
             r->next=n;
         r=n;
        }
    }
}
int main(){

 for(int i=1;i<5;i++){
    enqueue(i*10);
 }
 for(int i=1;i<5;i++){
    printf("%d\n",Dequeue());
 }
 Dequeue();
}