#include<stdio.h>

int stack[100];
int top=-1;
void main()

{  
    char ie[100], pe[100];                                 int i, j=0;
    printf("\n Enter infix expression: ");          gets(ie);
    for(i=0; ie[i]!='\0'; i++)
      {      if(ie[i]=='(')  push(ie[i]);     // open parenthesis is pushed into the stack
              else if( (ie[i] >= 'a'  && ie[i] <= 'z') || (ie[i] >= '0'  && ie[i] <= '9')) {pe[j++]=ie[i]; }  //operand
              else if(ie[i]==')')   // if it is closed parenthesis then pop all symbols from the stack upto open parenthesis encountered in the stack
                {while(stack[top]!='(')    { pe[j++]=pop(stack, top); }  // Assume the given infix expression is parenthesis balanced one
	    pop();  }
               else  // if it is an operator
	{  while(top > -1 &&  (prio(stack[top])>=prio(ie[i]) ))
    {
      pe[j++]=pop();}
                     push(ie[i]); }
       }
    while(top>-1)     {pe[j++]=pop(); } // Leftover symbols from the stack are popped  
    pe[j]='\0';    
    printf("the infix expression %s converted to %s postfix expression",ie, pe);
}
