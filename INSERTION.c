#include<stdio.h>
#include<Stdlib.h>
int binary(int arr[],int first,int last,int f){
   
    int i=first;
    int j=last;
  while(i<=j){
     int m=(last+first)/2;
      if(arr[m]==f){
       return m+1;
}
else if((arr[m]<f)){
    binary(arr,m+1,last,f);
}
else{
    binary(arr,first,m-1,f);
}
  }
}
int main(){
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
printf("%d",binary(arr,0,9,6));
}