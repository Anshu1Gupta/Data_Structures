#include<stdlib.h>
#include<stdio.h>
//Creating Max heap;
void swap(int arr[],int ele,int i){
    int temp=arr[ele];
    arr[ele]=arr[i];
    arr[i]=temp;
}
void heapifyMax(int arr[],int n,int i){
    int largest=i;
   int left =2*i;
   int right=2*i+1;
   if(left<=n &&arr[left]>arr[largest]){
    largest=left;
   }
   if(right<=n &&arr[right]>arr[largest]){
    largest=right;
   }
   if(largest!=i){
    swap(arr,largest,i);
    heapifyMax( arr,n,largest);
   }
}
void createMaxHeap(int arr[],int n){
   for(int j=n/2;j>=1;j--){
    heapifyMax(arr,n,j);
   }
   

}
// void heapifyMin(int arr[],int n,int i){
// int smallest=i;
// int left=2*i;
// int right=2*i+1;
// if(left<=n &&arr[left]<arr[smallest]){
//     smallest=left;
// }
// if(right<=n &&arr[right]<arr[smallest]){
//     smallest=right;
// }
// if(smallest!=i){
//    swap(arr,smallest,i);
//     heapifyMin( arr,n,smallest);
// }
// }
// void createMinHeap(int arr[],int n){
//    for(int j=n/2;j>=1;j--){
//     heapifyMin(arr,n,j);
//    }
// }




void HeapInsert(int arr[],int element,int n){
int index=n;
arr[n]=element;
while(index>1){
    int parent=index/2;
    if(arr[index]>arr[parent]){
        int temp=arr[index];
        arr[index]=arr[parent];
        arr[parent]=temp;
        index=parent;
    }
    else{
        return ;
    }

}
   
}

void HeapDeletion(int arr[],int n){
    arr[1]=arr[n];
    n=n-1;
    createMaxHeap(arr,n);
    // createMinHeap(arr,n);
}

void heapSort(int arr[],int n){
    int t=n-1;
    while(t--){
     int temp=arr[1];
     arr[1]=arr[n];
     arr[n]=temp;
     n=n-1;
     createMaxHeap(arr,n);
    //  createMinHeap(arr,n);
    }
}
int main(){
    


//Please Remember the no. of positive numbers that you entered;----------------------------------------

    int arr[100]={-1,12,23,25,4,2,12,24,34};
    // assuming array is starting from index 1
    //arr[0] is -1;

    // Above array representation as a complete Binary tree

     /*           12
                 / \
               23   25
               /\   /\
              4  2 12 24
            / 
           34             */ 



    // int n=sizeof(arr)/sizeof(int);
    // n=n-1;
    printf("Enter the number of elements that you have inserted\n");
     int n;
    scanf("%d",&n);
   

   //Structure of the Max Heap Function
    printf("Max heap Structure Is Given Below\n");
    createMaxHeap(arr,n);
    for(int i=1;i<=n;i++){
    printf("%d\n",arr[i]);
    }
   
    //Structure of the Min Heap Function
    //   printf("Min heap Structure Is Given Below\n");
    // createMinHeap(arr,n);
    // for(int i=1;i<=n;i++){
    // printf("%d\n",arr[i]);
    // }
    



    // Insertion In The heap
     int element;
    printf("Enter the element that you want to insert in the heap\n");
    scanf("%d",&element);
    n=n+1;
    HeapInsert(arr,element,n);
    printf("Heap after insertion\n");

    for(int i=1;i<=n;i++){
        printf("%d\n",arr[i]);

    }  
     
    
    //  Deletion In The Heap
    printf("Heap After Deletion\n");
   HeapDeletion(arr,n);
   n=n-1;
 for(int i=1;i<=n;i++){
        printf("%d\n",arr[i]);
    }




    // Heap Sort Algorithm.
    printf("Sorting of the heap\n");
    heapSort(arr,n);
    for(int i=1;i<=n;i++){
        printf("%d\n",arr[i]);
    }





   }



