#include<stdlib.h>
#include<stdio.h>
struct stack{
    struct node**arr;
    int size;
    int top;
};
int operand(char c){
    if(c=='+'||c=='-'||c=='/'||c=='*'){
        return 1;
    }
    else{
        return 0;
    }
}
struct node{
    char data;
    struct node* left;
    struct node* right;
};
void push(struct stack* x,struct node* c){
    x->top++;
    x->arr[x->top]=c;
}
struct node*pop(struct stack*x){
    return x->arr[x->top--];
}
struct node*createNode(char data){
    struct node* t=(struct node*)malloc(sizeof(struct node));
    t->data=data;
    t->left=NULL;
    t->right=NULL;

    return t;
}

 struct node *ExpressionTree(char * str){
    struct stack *s=(struct stack*)malloc(sizeof(struct stack));
    s->arr=(struct node **)malloc(s->size*(struct node*));
s->size=100;
s->top=-1;

    int i=0;
    while(str[i]!='\0'){
        if(operand(str[i])){
            struct node* x=createNode(str[i]);
            push(s,x);
            i++;
        }
        else if(!operand(str[i])){
            struct node*r=pop(s);
            struct node*l=pop(s);
            struct node* character=createNode(str[i]);
            character->left=l;
            character->right=r;
            push(s,character);
            i++;

        }
    }
    return pop(s);
 }

void traversal(struct node*op){
if(op==NULL){
    return;
}
else{
    traversal(op->left);
    printf("%d\n",op->data);
    traversal(op->right);
}
}

int main(){
char *ptr="ab+cd-*";
  struct node*n=  ExpressionTree(ptr);
  traversal(n);

}