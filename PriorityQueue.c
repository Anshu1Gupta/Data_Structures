#include<stdio.h>
#include<stdlib.h>
#define size 5
struct priQ{
    int data;
    int pri;
}arr[size];
int r=-1;

int isEmpty(){
    if(r==-1){
        return 1;
    }
    else{
        return 0;
    }
}
int isFull(){
    if(r>=size-1){
        return 1;
    }
    else{
        return 0;
    }
}

void insert(int ele,int pri)
{
 
        r++;
        arr[r].data=ele;
        arr[r].pri=pri;
    
       
    
}
int peekMax(){
    int i,p=-1;
   if(!isEmpty()){
    for(i=0;i<=r;i++){
        if(arr[i].pri>p){
            p=arr[i].pri;
        }
    }
    return p;
   }
}
int peekMin(){
    int i,p=__INT_MAX__;
   if(!isEmpty()){
    for(i=0;i<=r;i++){
        if(arr[i].pri<p){
            p=arr[i].pri;
        }
    }
    return p;
   }
}
int deleteMax(){
    int i,j,p,ele=-1;
if(isEmpty()){
    printf("Queue is Empty\n");
    return -1;
}
else{
        p=peekMax();
    for(i=0;i<=r;i++){
        if(arr[i].pri==p){
            ele=arr[i].data;
            break;
        }
    }
    if(i<r){
        for(j=i;j<r;j++){
            arr[j].data=arr[j+1].data;
            arr[j].pri=arr[j+1].pri;
        }
       
    }
     r=r-1;
     return ele;
     
}
}
int deleteMin(){
        int i,j,p,ele=-1;
if(isEmpty()){
    printf("Queue is Empty\n");
    return -1;
}
else{
        p=peekMin();
    for(i=0;i<=r;i++){
        if(arr[i].pri==p){
            ele=arr[i].data;
            break;
        }
    }
    if(i<r){
        for(j=i;j<r;j++){
            arr[j].data=arr[j+1].data;
            arr[j].pri=arr[j+1].pri;
        }
       
    }
     r=r-1;
     return ele;
     
}

}
void display(){
    if(isEmpty()){
        printf("Queue is Empty\n");
    }
    else{
        for(int i=0;i<=r;i++){
        printf("  %d----%d \n",arr[i].data,arr[i].pri);
    }
    }
}
int main(){
    insert(20,2);
    insert(45,9);
    insert(56,7);
    insert(6,3);
    insert(26,3);
    insert(100,5);
     insert(36,4); 
    insert(4,1);
    printf("--------------------------------------------------------------------\n");
    printf(" DATA----Priority\n");
display();
  deleteMin();
  deleteMax();
  printf("----------------------------After operation--------------------------\n");
printf(" DATA----Priority\n");
display();
} 