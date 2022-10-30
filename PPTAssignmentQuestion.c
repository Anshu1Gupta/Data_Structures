#include<stdio.h>
#include<stdlib.h>


struct stack {
    int size;
    int top;
    char*arr;
};
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
if(s->top==s->size-1){
   printf("Stack Overflow\n");

}
else{
    s->top++;s->arr[s->top]=c;
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
//Paranthesis Matching Program
int paranthesisMatch(struct stack *s,char *str){

    for(int i=0;str[i]!='\0';i++){
    if(str[i]==')'|| str[i]==']'|| str[i]=='}'){
       if(isEmpty(s)){
        return 0;
       }
       
       else{
       if(str[i]==')'){
         if( s->arr[s->top] !='('){
             return 0;
         }
         else{
            pop(s);
         }
       }
      else  if(str[i]==']'){
         if( s->arr[s->top] !='['){
             return 0;
         }
         else{
            pop(s);
         }
       }
       else if(str[i]=='}'){
         if( s->arr[s->top] !='{'){
             return 0;
         }
         else{
            pop(s);
         }
       }
       }
    }
    else if(str[i]=='('||str[i]=='['||str[i]=='{'){
        push(s,str[i]);
   
    }
    }
    if(isEmpty(s)){
        return 1;
    }
    else{
        return 0;
    }
}
//String Reversal Program
void stringReversal(struct stack *s,char *str){
 for(int i=0;str[i]!='\0';i++){
    push(s,str[i]);
 }
}
//Decimal To BInary Conversion
void dToB(struct stack *s,int num){
    int store;
    while(num){
        store=num%2;
        num=num/2;
        push(s,store);
    }
}
void display(struct stack *s ){
    if(s->top==-1){
        printf("Nothing can be displayed\n");
    }
    else{
       while(s->top!=-1){
        printf("%d",pop(s));
       }
    }
}
 int main(){


//     struct stack *s=(struct stack *)malloc(sizeof(struct stack));
//     s->size=100;
//     s->top=-1;
//     s->arr=(char*)malloc(sizeof(char)*s->size);
        //   Calling String Reversal Function
// char * string="AnshuGupta";
// stringReversal(s,string);
// display(s);


        //Palindrome String or NOT
// int i=0,flag=0;
//     while(s->top!=-1){
//         if(string[i]!=pop(s)){
//      flag=1;
//         }
//         i++;
//     }
//     if(flag==0){
//         printf("Palindrome String\n");
//     }
//     else{
//         printf("Not Palindrome\n");
//     }


          //Calling paranthesis Matching Function
// int x= paranthesisMatch(s,string);
// if(x){
// printf("Paranthesis are matched\n");
// }else{
// printf("Paranthesis are not Matched\n");
// }

        // Calling Decimal To binary Conversion Function
//   int num=16;
//   printf("Enter the number whose binary you want\n");
//   dToB(s,num);
//   display(s);


// Calling Doubly Linked List
for(int i=1;i<=10;i++){
    doublePush(i*10);
}
for(int i;i<10;i++){
    printf("%d",doublePop());
}
}