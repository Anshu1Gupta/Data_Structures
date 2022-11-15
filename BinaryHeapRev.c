#include<stdio.h>
swap(int *a1,int *a2){

int *temp=*a1;
*a1=*a2;
*a2=*temp;
}
void heapify(int arr[],int i){
        int parent=(i-1)/2;
        if(arr[parent]<arr[i]){
            swap(&arr[parent],&arr[i]);
        }
    
}
heap(arr,n){
    for(int i=n-1;i>1;i--){
        heapify(arr,i);
    }
}
    int main(){
   int n;
     int arr[100];
   printf("Enter the number of nodes you want to be in the Heap:");
   scanf("%d\n",&n);
 
   printf("Enter the root node:\n");
   scanf("%d",&arr[0]);
if(n%2==1){
    for(int i=0;i<(n-1)/2;i++){
   printf("Enter the left child of %d:",arr[i]);
   scanf("%d",&arr[2*i+1]);
   printf("Enter the right child of %d:",arr[i]);
   scanf("%d",&arr[2*i+2]);
}
}
else{
    int i;
    for( i=0;i<(n-1)/2;i++){
   printf("Enter the left child of %d: ",arr[i]);
   scanf("%d",&arr[2*i+1]);
   printf("Enter the right child of %d: ",arr[i]);
   scanf("%d",&arr[2*i+2]);
}
printf("Enter the left child of %d: ",arr[i]);
   scanf("%d",&arr[2*i+1]);
}

printf("As The heap that you created may not be the structured and ordered heap\n");

heap(arr,n);
for(int i=0;i<n;i++){
    printf("%d\n",arr[i]);
}
    return 0;
}