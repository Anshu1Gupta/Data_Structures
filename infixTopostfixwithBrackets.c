#include<stdio.h>
#include<stdlib.h>
struct stack{
    int top;
    int size;
    char *arr;
};
int precedence(char c){
  if(c=='+'||c=='-'){
    return 1;
  }
  else if(c=='*'||c=='/'){
    return 2;
  }
  else{
    return 0;
  }
}
int isOperator(char c){
    if(c=='-'||c=='+'||c=='*'||c=='/'){
        return 1;
    }
    else{
        return 0;
    }
}
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
void display(char postfix[]){
    int i=0;
    while(postfix[i]!='\0'){
        if(postfix[i]==')'){}
       else{ printf("%c",postfix[i++]);
       }
    }
}
void infixToPostfix(char *q){
    struct stack *s=(struct stack*)malloc(sizeof(struct stack));
    s->size=100;
    s->top=-1;
    s->arr=(char *)malloc(sizeof(char)*s->size);
    int i=0,j=0;
    char postfix[s->size];
    while(q[i]!='\0'){
        if(q[i]=='('){
           push(s,q[i]);
           i++;
           while(q[i]!=')'){
            if(!isOperator(q[i])){
           postfix[j++]=q[i++];
        }
        else if(isOperator(q[i])){
          if(precedence(q[i])>precedence(s->arr[s->top])){
           push(s,q[i]);
           i++;
           }
           else{
            postfix[j++]=pop(s);
            } }
        }
        while(s->arr[s->top]!='(')
        postfix[j++]=pop(s);
        pop(s);
        }
       
        if(!isOperator(q[i])){
            
           postfix[j++]=q[i++];
        }
        else if(isOperator(q[i])){
           if(precedence(q[i])>precedence(s->arr[s->top])){
           push(s,q[i]);
           i++;
           }
           else{
            postfix[j++]=pop(s);
           }

        }
    }
    while(!isEmpty(s)){
       postfix[j++]=pop(s);
    }
    postfix[j++]='\0';
    display(&postfix[0]); 
}
int main(){
    
char *q="a*(b+g)";
infixToPostfix(q);
}