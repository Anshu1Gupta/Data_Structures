#include<stdio.h>
    #include<stdlib.h>
    struct stack{
        int data;
        struct stack*next;
    }*top=NULL;
int pop()
    {
       if(top==NULL){
        printf("Stack Underflow\n");
       
       }
       else{
        struct stack*h=top;
        int x=h->data;
        top=top->next;
        free(h);
        return x;
       
       }
    }
void push(int data)
{
    struct stack *new=(struct stack*)malloc(sizeof(struct stack));
    new->data=data;
    new->next=NULL;
    if(new==NULL)
    {
        printf("Stack Overflow \n");
        
    }
    else
    {
        if(top==NULL)
        {
            top=new;
            top->next=NULL;
        }
        else
        {
            new->next=top;
            top=new;
        }
    }
}
    int main(){
        for(int i=0;i<9;i++){
            push(i+1);
        }
        for(int i=0;i<10;i++){
            printf("%d\n",pop());
        }
    return 0;
}