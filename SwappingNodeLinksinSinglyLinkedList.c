#include<stdio.h>
#include<stdlib.h>
//Below program is for insertion and deletion in a Circularly Doubly linked List
struct node{
int data;
struct node*next;

};
struct node* createNode(int data){
  struct node* x=(struct node*)malloc(sizeof(struct node));
  x->data=data;
  x->next=NULL;
 return x;
}

void display(struct node* head){
    struct node* ptr=head;
    while(ptr!=NULL){
        printf("%d\n",ptr->data);
    ptr=ptr->next;
    }

}
 struct node* swap(struct node* head,int after){
    struct node* p=NULL;
    struct  node*q=head;
        if(head==NULL){
            printf("Swapping not possible\n");
            return head;
        }
        else if(head->next==NULL){
               printf("Swapping not possible\n");
               return head;
        }
        else{
            while(q->data!=after && q->next!=NULL){
                p=q;
                q=q->next;
            }

            if(q->next==NULL)
            {
                printf("Swapping not possible\n");
                return head;
            }
            else{
                struct node*temp=q->next;
                p->next=temp;
                q->next=temp->next;
                temp->next=q;
               return head;
            }
            
        }
 }


int main(){
struct node* head=createNode(10);
struct node* second=createNode(20);
struct node* third=createNode(30);
struct node* fourth=createNode(40);
struct node* fifth=createNode(60);
head->next=second;
second->next=third;
third->next=fourth;
fourth->next=fifth;
fifth->next=NULL;


head=swap(head,40);
display(head);


}