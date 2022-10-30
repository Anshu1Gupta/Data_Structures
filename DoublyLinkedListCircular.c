#include<stdio.h>
#include<stdlib.h>
//Below program is for insertion and deletion in a Circularly Doubly linked List
struct node{
int data;
struct node*next;
struct node*prev;
}*head=NULL;
struct node* createNode(int data){
  struct node* x=(struct node*)malloc(sizeof(struct node));
  x->data=data;
  x->next=NULL;
  x->prev=NULL;
  return x;
}
void display(struct node*head){
struct node *temp=head;
printf("%d\n",temp->data);
temp=temp->next;
while(temp!=head){
printf("%d\n",temp->data);
temp=temp->next;
}
}
struct node* insertBegin(struct node* head,int data){
    struct node*new=(struct node*)malloc(sizeof(struct node));
    new->data=data;
    new->next=NULL;
    new->prev=NULL;
   
   if(new==NULL){
    printf("Insertion is not possible\n");
    return head;
   }
   else if(head==NULL){
    head=new;
    head->prev=head;
    head->next=head;
    return head;
   }
   else if(head->next==head){
    new->next=head;
    head->prev=new;
    new->prev=head;
    head->next=new;
    head=new;
    return head;
   }
   else{
    struct node* temp=head;
     do{
     temp=temp->next;
     }while(temp->next!=head);
     temp->next=new;
     new->prev=temp;
     new->next=head;
     head->prev=new;
     head=new;
     return head;     
   }
  }
struct node* insertEnd(struct node*head,int data){
struct node*new=(struct node*)malloc(sizeof(struct node));
    new->data=data;
    new->next=NULL;
    new->prev=NULL;
   
   if(new==NULL){
    printf("Insertion is not possible\n");
    return head;
   }
   else if(head==NULL){
    head=new;
    head->prev=head;
    head->next=head;
    return head;
   }
   else if(head->next==head){
    head->next=new;
    new->prev=head;
    new->next=head;
    head->prev=new;
    return head;
   }
   else{
    struct node* temp=head;
    do{
      temp=temp->next;
    }while(temp->next!=head);
    temp->next=new;
    new->prev=temp;
    new->next=head;
    head->prev=new;
    return head;
   }
  }
struct node* insertBefore(struct node*head,int  find,int data){
struct node*new=(struct node*)malloc(sizeof(struct node));
    new->data=data;
    new->next=NULL;
    new->prev=NULL;
   if(new==NULL){
    printf("Insertion is not possible\n");
    return head;
   }
   else if(head==NULL){
   printf("No insertion possible because list is Empty\n");
   return head;
   }
   else if(head->next==head){
    new->next=head;
    new->prev=head;
    head->next=new;
    head->prev=new;
    head=new;
    return head;
   }
   else if(head->data==find){
  struct node*temp=head;
  do{
    temp=temp->next;
  }while(temp->next!=head);
    temp->next=new;
    new->prev=temp;
    new->next=head;
    head->prev=new;
    head=new;
    return head;
   }
   else{
    struct node*temp=head;
    do{
      temp=temp->next;
    }while(temp->data!=find);
    new->next=temp;
    new->prev=temp->prev;
    temp->prev->next=new;
    temp->prev=new;
return head;
   }
}
struct node* insertAfter(struct node*head,int  find,int data){
struct node*new=(struct node*)malloc(sizeof(struct node));
    new->data=data;
    new->next=NULL;
    new->prev=NULL;
   if(new==NULL){
    printf("Insertion is not possible\n");
    return head;
   }
   else if(head==NULL){
   printf("No insertion possible because list is Empty\n");
   return head;
   }
   else if(head->next==head&&head->data==find){
    head->next=new;
    head->prev=new;
     new->next=head;
    new->prev=head;
    return head;
   }
   else if(head->data==find){
      head->next->prev=new;
    new->next=head->next;
    new->prev=head;
    head->next=new;
    return head;
   }
   else{
    struct node*temp=head;
    do{
      temp=temp->next;
    }while(temp->data!=find);
    new->next=temp->next;
    new->prev=temp;
    temp->next->prev=new;
    temp->next=new;
return head;
   }
}
struct node*deleteBegin(struct node*head){
 if(head==NULL){
  printf("Deletion not possible as the list is Empty\n");
  return NULL;
 }
 else if(head->next==head){
  head==NULL;
  return head;
 }
 else{
  struct node* temp=head;
  do{
    temp=temp->next;
  }while(temp->next!=head);
  head=head->next;
  temp->next=head;
  return head;
 }
}
struct node*deleteEnd(struct node*head){
  if(head==NULL){
  printf("Deletion not possible as the list is Empty\n");
  return NULL;
 }
 else if(head->next==head){
  head==NULL;
  return head;
 }
 else{
  struct node* temp=head;
  do{
    temp=temp->next;
  }while(temp->next!=head);
  temp->prev->next=head;
  temp->next->prev=temp->prev;
  return head;
 }
}
struct node*deleteBefore(struct node*head,int find){
  if(head==NULL){
  printf("Deletion not possible as the list is Empty\n");
  return NULL;
 }
 else if(head->next==head){
  
    printf("Deletion not possible because no element found previous or after head\n");
    return head;
 }
 else if(head->data==find){
  struct node*temp=head;
  do{
    temp=temp->next;
  }while(temp->next!=head);
  temp->next->prev=temp->prev;
  temp->prev->next=head;
return head;
 }
 else{
  struct node* temp=head;
  do{
    temp=temp->next;
  }while(temp->data!=find);
  struct node*f=temp;
  temp->prev->prev->next=temp;
   temp->prev=temp->prev->prev;
  return head;
 }
}
struct node*deleteAfter(struct node*head,int find){
  if(head==NULL){
  printf("Deletion not possible as the list is Empty\n");
  return NULL;
 }
 else if(head->next==head){
    printf("Deletion not possible because no element found previous or after head\n");
    return head;
 }
 else if(head->data==find){
  head->next->next->prev=head;
  head->next=head->next->next;
return head;
 }
 else{
  struct node* temp=head;
  do{
    temp=temp->next;
     }while(temp->data!=find);
  if(temp->next==head){
    head=head->next;
    temp->next=head;
    head->prev=temp;
  return head;
  }
  else{
      temp->next->next->prev=temp;
  temp->next=temp->next->next;
 
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
second->prev=head;
second->next=third;
third->prev=second;
third->next=fourth;
fourth->prev=third;
fourth->next=fifth;
fifth->prev=fourth;
fifth->next=head;
head->prev=fifth;
printf("List before the operation is \n");
display(head);

printf("List after the operation is \n");

//All Deletion Operation
// head=deleteBegin(head);
// head=deleteEnd(head);
// head=deleteBefore(head,60);
// head=deleteAfter(head,60);
//All Insertion Operation
// head=insertBegin(head,60);
// head=insertEnd(head,60);
// head=insertBefore(head,10,60);
// head=insertAfter(head,60,90);

  display(head);
}