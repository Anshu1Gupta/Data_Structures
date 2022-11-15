#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
   int top;
   char *arr;
};
void display(char arr[]){
    int i=0;
    while(arr[i]!='\0'){
      printf("%c",arr[i]);
      i++;
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
int isFull(struct stack *s){
    if(s->top==s->size-1){
        return 1;
    }
    else{
        return 0;
    }
}
void push(struct stack *s,char c){
    if(isFull(s)){
        printf("Stack Overflow\n");


    }
    else{
        s->top++;
        s->arr[s->top]=c;

    }
}
char pop(struct stack *s){
    if(s->top==-1){
        printf("Stack Underflow\n");
    }
    else{
        char x=s->arr[s->top];
        s->top--;
        return x;
    }
}
int precedence(char c){
    if(c=='+'||c=='-'){
        return 2;
    }
    else if(c=='*'||c=='/'||c=='%'){
        return 3;
    }
    else{
        return 0;
    }
}
int operation(char c,int x2,int x1){
    if(c=='*'){
        return x2*x1;
    }
    else if(c=='-'){
        return x2-x1;
    }
    else if(c=='+'){
        return x2+x1;
    }
    else if(c=='/'){
        return x2/x1;
    }

}
int isOperator(char c){
    if(c=='+'|| c=='-'||c=='*'||c=='/'){
        return 1;
    }
    else{
        return 0;
    }
}
double evaluation(char *str){
     struct stack *s2=(struct stack *)malloc(sizeof(struct stack));
    s2->size=100;
    s2->top=-1;
    s2->arr=(char*)malloc(sizeof(char)*s2->size);
    int i=0;
while(str[i]!='\0'){
 if(!isOperator(str[i])){
    push(s2,str[i]);
 }
 else if(isOperator(str[i])){
    double x2=pop(s2)-48;
    double x1=pop(s2)-48;
 double p=operation(str[i],x2,x1);
push(s2,p+48);
 }
 i++;
}
return pop(s2)-48;
}
void IntoPo(char *str){
    struct stack *s=(struct stack *)malloc(sizeof(struct stack));
    s->size=100;
    s->top=-1;
    s->arr=(char*)malloc(sizeof(char)*s->size);
    char postfix[s->size];
int i=0,j=0;
    while(str[i]!='\0'){
        if(str[i]=='('){
            push(s,str[i]);
            i++;
            while(str[i]!=')'){
                if(!isOperator(str[i])){
                    postfix[j++]=str[i++];
                }
                else if(isOperator(str[i])){
                    if(precedence(str[i])>precedence(s->arr[s->top])){
                        push(s,str[i]);
                        i++;
                    }
                    else {
                        postfix[j++]=pop(s);
                    }
                }
            }
            while(s->arr[s->top]!='('){
                postfix[j++]=pop(s);
            }
            pop(s);
            i++;
        }

   else if(!isOperator(str[i])){
        postfix[j++]=str[i++];
    }
    else if(isOperator(str[i])){
        if(precedence(str[i])>precedence(s->arr[s->top])){
            push(s,str[i]);
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
printf("\n The answer we got after evaluation of the above postfix is :%.2lf",evaluation(&postfix[0]));
}


int main(){
      char *str="4*4%2+9";
      IntoPo(str);
}