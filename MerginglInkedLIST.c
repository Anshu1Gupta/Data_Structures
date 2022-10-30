#include<stdio.h>
#include<stdlib.h>
//Below program is for insertion and deletion in a Circularly Doubly linked List
struct node{
int data;
struct node*next;

}*head=NULL;
struct node* createNode(int data){
  struct node* x=(struct node*)malloc(sizeof(struct node));
  x->data=data;
  x->next=NULL;

  return x;
}
void display(struct node*head){
struct node *temp=head;

while(temp!=head){
printf("%d\n",temp->data);
temp=temp->next;
}
}

struct node* merge(struct node*head1,struct node*head2){
struct node* new=(struct node*)malloc(sizeof(struct node));
struct node* st;
new->next=NULL;
struct node* ptr1;
struct node* ptr2;
while(ptr1!=NULL && ptr2!=NULL){
    if(ptr1->data<ptr2->data){
           if(new==NULL){
            new=ptr1;
            st=ptr1;
           
            ptr1=ptr1->next;
                   st->next=NULL;
           }
           else{
            struct node*st=new;
            
            st->next=ptr1;
            st=st->next;
     
            ptr1=ptr1->next;
             st->next=NULL;
           }
    }
    else{
        if(new==NULL){
            new=ptr2;
            st=ptr2;
             ptr2=ptr2->next;

            st->next=NULL;
           
           }
          else{
            struct node*st=new;
            
            st->next=ptr2;
            st=st->next;
             ptr2=ptr2->next;
            st->next=NULL;
           
           }
    }   
}
    while(ptr1!=NULL){
     st->next=ptr2;
     st=st->next;
     st->next=NULL;
            
            ptr1=ptr1->next;
    }
     while(ptr2!=NULL){
     st->next=ptr2;
     st=st->next;
     st->next=NULL;
            
            ptr2=ptr2->next;
    }

    return new;
}

int main(){
struct node* head1=createNode(10);
struct node* second1=createNode(20);
struct node* third1=createNode(30);
struct node* fourth1=createNode(40);
struct node* fifth1=createNode(60);
head->next=second1;
second1->next=third1;
third1->next=fourth1;
fourth1->next=fifth1;
fifth1->next=NULL;
struct node* head2=createNode(10);
struct node* second2=createNode(20);
struct node* third2=createNode(30);
struct node* fourth2=createNode(40);

head2->next=second2;
second2->next=third2;
third2->next=fourth2;
fourth2->next=NULL;
struct node*new=(struct node*)malloc(sizeof(struct node));
printf("List before the operation is \n");
display(head);

printf("List after merging  is \n");

  display(head);
 new= merge(head1,head2);
 display(new);
}