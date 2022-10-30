#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node* next;
    struct node* prev;
} *top;


void push(int data)
{
	
	struct node* new = (struct node*)malloc(sizeof(struct node));
    new->data=data;
	if (new==NULL)
	{
	    printf("We cannot allocate memory");
	    return;
	}
	
	
	if (top == NULL)
	{
	    new->next = NULL;
	    new->prev = NULL;
	    top = new;
	}
	else
	{
	    // top->next = new;
	    // new->prev = top;
        new->next=top;
        top->prev=new;
	    top = new;
	}
}
int pop()
{
    if (top == NULL)
    {
    printf("stack is empty. We have nothing to pop\n");
    return -1;
    
    }
    if(top->next == NULL && top->prev ==NULL){
        int a = top->data;
        struct node *new;
        new = top;
        top= NULL;
        free(new);
        return a;
    }
    struct node *new;
	new = top;
    int data=top->data;
	top = top->next;
	top->prev = NULL;
	free(new);
    return data;
}	
void display()
{
    struct node *new = top;
    if (new==NULL)
    {
        printf("Stack is empty\n");
        return;
    }
     while(new!= NULL)
    {
        printf("%d  ",new->data);
        new = new->prev;
    }
     printf("\n");
}
	
int main()
{

   push(12);
    push(12);
     push(12);
      push(12);
for(int i=0;i<4;i++){
    printf("%d\n",pop());
}      
    
}
    
	
	
	
	
	
	