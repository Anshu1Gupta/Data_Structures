#include<stdio.h>
#include<stdlib.h>

struct stack{
  int top;
    char *arr;
    int size;
};
int isFull(struct stack*s){
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
char pop(struct stack *s){
    if(isEmpty(s)){
        printf("Stack underflow\n");
    }
    else{
        char x=s->arr[s->top];
        s->top--;
        return x;
    }
}
void push(struct stack *s,char c){
    if(isFull(s)){
        printf("Stack overflow\n");
    }
    else{
        s->top++;
        s->arr[s->top]=c;
    }
}
int paranthesisMatch(char *q){
   struct stack *s=(struct stack*)malloc(sizeof(struct stack));
   s->size=100;
   s->top=-1;
   s->arr=(char*)malloc(sizeof(char)*s->size);
   for(int i=0; q[i]!='\0';i++){
       if(isEmpty(s)&&q[i]==')'){
        return 0;
       } 
       else if(q[i]=='('){
        push(s,q[i]);
       }
       else if(q[i]==')'){
        pop(s);
       }
   }
   if(!isEmpty(s)){
    return 0;
   }
   else{
    return 1;
   }

   
}
int main(){
 char *q="(()()()()())";
 if(paranthesisMatch(q)){
    printf("Paranthesis Matched\n");
 }
 else{
    printf("Paranthesis not matched\n");
 }
}