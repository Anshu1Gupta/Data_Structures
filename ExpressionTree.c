#include<stdio.h>
#include<stdlib.h>
struct stack{
    int top;
    int size;
    char *arr;
};
struct stackExp{
    int top;
    int size;
   struct node* *arr;
};
struct node{
    char key;
    struct node*left;
    struct node*right;
}*root=NULL;
struct node*createNode(char data){
    struct node* x=(struct node*)malloc(sizeof(struct node));
    x->key=data;
    x->left=NULL;
    x->right=NULL;
    return x;
}

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
int isOperatorExp(char c){
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
struct node* popExp(struct stackExp *s){
    if(isEmpty(s)){
        printf("Stack underflow\n");
    }
    else{
        struct node* x=s->arr[s->top];
        s->top--;
        return x;
    }
}
void pushExp(struct stackExp *s,struct node* c){
    if(isFull(s)){
        printf("Stack overflow\n");
    }
    else{
        s->top++;
        s->arr[s->top]=c;
    }
}
void displayExp(char postfix[]){
    int i=0;
    while(postfix[i]!='\0'){
        if(postfix[i]==')'){}
       else{ printf("%c",postfix[i++]);
       }
    }
}
char* infixToPostfix(char *q){
    struct stack *s=(struct stack*)malloc(sizeof(struct stack));
    s->size=100;
    s->top=-1;
    s->arr=(char *)malloc(sizeof(char)*s->size);
    int i=0,j=0;
    char postfix[s->size];
    while(q[i]!='\0'){
        // if(q[i]=='('){
        //    push(s,q[i]);
        //    i++;
        //    while(q[i]!=')'){
        //     if(!isOperator(q[i])){
        //    postfix[j++]=q[i++];
        // }
        // else if(isOperator(q[i])){
        //   if(precedence(q[i])>precedence(s->arr[s->top])){
        //    push(s,q[i]);
        //    i++;
        //    }
        //    else{
        //     postfix[j++]=pop(s);
        //     } }
        // }
        // while(s->arr[s->top]!='(')
        // postfix[j++]=pop(s);
        // pop(s);
        // }
       
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
    printf("The Postfix Expression %s Is: ",q);
    display(&postfix[0]); 
    printf("Creating an Expression Tree for the postfix Expression\n");
   return postfix;
}
struct node* ExpressionTree(struct stack*st,char*postfix){
    for(int i=0;postfix[i]!='\0';i++){
        if(isOperatorExp(postfix[i])){
            struct node *v=createNode(postfix[i]);
             v->right=popExp(st);
             v->left=popExp(st);
        }
        else if(!(isOperatorExp(postfix[i]))){
            struct node*r=createNode(postfix[i]);
            push(st,r);
        }
    }
return pop(st);
}
void postOrder(struct node*st){
    if(st!=NULL){
        postOrder(st->left);
        postOrder(st->right);
        printf("%c",st->key);
    }
}
int main(){
    
char *q="a*b+g+h";
char *store=infixToPostfix(q);
 struct stackExp *st=(struct stackExp*)malloc(sizeof(struct stackExp));
    st->size=100;
    st->top=-1;
    st->arr=(struct node* *)malloc(sizeof(struct node*)*st->size);
 struct node*t=ExpressionTree(st,store);
  postOrder(st);
}