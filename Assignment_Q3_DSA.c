#include<stdio.h>
#include<stdlib.h>
//Structure of the node
struct node
{
int  data;
struct node* next;
char mark; // set to 1 if deleted, and 0 otherwise
};
// To check the number of deleted data and the number of non-deleted data
// define the following two variable. Initially, both variables are set to be zero.


int Total_Count = 0; // the total number of data in the struct node*
int Delete_Count = 0; // the total number of deleted data


// The following are the required functions:
struct node* toFind(int value,struct node* list)
{
struct node* P = list->next;
while ( P != NULL && (P->data !=value || P->mark) )
P = P->next;
return P;
}
int IsLast(struct node* P, struct node* list)
{
return P->next == NULL;
}

void Lazy_Deletion(int value, struct node* list)
{
struct node* P;
P = toFind(value, list);
if (P)
{
P->mark = 1;
Delete_Count++;
if( Total_Count - Delete_Count == Delete_Count )
   {   
// the number of deleted data is the same as the number  of non-deleted data  in the list then perform deletion
Deletion(list);
   }
}
}
void Deletion(struct node* list)
{
struct node* P;
struct node* Previous;
struct node* temp;
Previous = list;
P = list->next;
while ( !IsLast(P,list) )
{
if ( P->mark )
{
temp = P;
P = P->next;
Previous->next = P;
free( temp );
Total_Count--;
Delete_Count--;
}
else
{
Previous = P;
P = P->next;
}
}
}

