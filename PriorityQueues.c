#include<stdlib.h>
#include<stdio.h>
struct node{
    struct node* next;
    int data;
    int pri;
}*f=NULL,*r=NULL;

struct node* createNode(int data,int pri){
 struct node*new=(struct node*)malloc(sizeof(struct node));
 new->data=data;
 new->pri=pri;
 new->next=NULL;
 return new;
}
void enqueue(int data,int pri){
    struct node*p;
    struct node*new=(struct node*)malloc(sizeof(struct node));
    new->data=data;
    new->pri=pri;
    new->next=NULL;
    if(r==NULL){
        f=new;
        r=new;
       
       printf("Enqueued %d Element\n",new->data);
    }
    
    else if(p->next==NULL&&r->pri<new->pri){
        new->next=r;
        f=new;
        printf("Enqueued %d Element\n",new->data);
    }
     else if(p->next==NULL&&r->pri>=new->pri){
       r->next=new;
        printf("Enqueued %d Element\n",new->data);
    }
    else{

        if(new->pri>p->pri){
            new->next=f;
            f=new;
        }
       else{
        while(r->next->pri>new->pri && r->next!=NULL){
            r=r->next;
        }
         if(new->pri>r->next->pri){
    new->next=r->next;
    r->next=new;
    printf("Enqueuing %d\n",r->data);
    }
     else{
        r->next=new;
    }
    }
       }
}
void dequeue(){
    if(f==NULL){
        printf("No Element in QUEUE\n");
    }
    else{
        struct node*h=f;
        int data=f->data;
        f=f->next;
        free(h);
        printf("%d\n",data);
    }
}

int main(){
enqueue(9,8);
enqueue(10,8);
enqueue(11,8);
enqueue(12,8);
enqueue(13,9);

// enqueue

printf("\n");
printf("DEQUEING BELOW\n");
dequeue();
dequeue();
dequeue();
dequeue();
dequeue();



}