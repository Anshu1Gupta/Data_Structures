#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
}*f=NULL,*r=NULL;
struct node*createNode(int data){
    struct node*new=(struct node*)malloc(sizeof(struct node));
    new->data=data;
    new->next=NULL;
    return new;
}
void enqueue(int data){
    struct node*q=createNode(data);
    if(q==NULL){
        printf("Queue is Full \n");
        return ;
    }
    else{
        if(f=NULL && r==NULL){
            f=q;
            r=q;
            r->next=f;
        }
        else{
            r->next=q;
            r=q;
            r->next=f;

        }
    }
}
void dequeue(){
    if(f==NULL){
    printf("Queue is Empty\n");
    }
    else{
        if(f==r){
            printf("%d\n",f->data);
            f=NULL;
            r=NULL;
        }
        else{
            struct node*temp=f;
            int data=f->data;
            f=f->next;
            r->next=f;
           free(temp);
            printf("%d\n",data);
        }
    }
}
int main(){
// struct node *q=(struct node*)malloc(sizeof(struct node));
enqueue(90);
dequeue();

}