#include<stdio.h>
void display(int ar[],int n){
    for(int i=0;i<n;i++){
        printf("%d\n",ar[i]);
    }
}
int delete(int ar[],int pos,int n){
    for(int i=pos-1;i<n-1;i++){
        ar[i]=ar[i+1];
    }
    n=n-1;
    display(ar,n);
}
    int main(){
    int ar[]={1,2,3,4,5,6,7,8};
delete(ar,8,8);
    return 0;
}