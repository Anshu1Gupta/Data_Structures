#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;
}*top=NULL;

void push(int data){
    struct node*new=(struct node*)malloc(sizeof(struct node));
    new->data=data;
    if(new==NULL){
        printf("No memory is Allocated\n");
    }
    else if(top==NULL){
        new->next=NULL;
        new->prev=NULL;
        top=new;

    }
    else{
        new->next=top;
        top->prev=new;
        top=new;
    }
}
int pop(){
    if(top==NULL){
        printf("Stack Underflow\n");
        return -1;
    }
    else if(top->next==NULL && top->prev==NULL){
        struct node*ptr=top;
        int data=top->data;
        top=NULL;
        free(ptr);
        return data;
    }
    struct node* new=top;
    int data=top->data;
    top=top->next;
    top->prev=NULL;
    free(new);
    return data;
}
int main(){
for(int i=0;i<9;i++){
    push(i+1);
}
for(int i=0;i<9;i++){
   printf("%d\n",pop());
}
}