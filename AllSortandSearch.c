#include <stdio.h>
// Sorting Methods
void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }
}
void BubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int flag = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                flag = 1;
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        if (flag == 0)
        {
            printf("The array is already sorted \n");
            return;
        }
    }
    display(arr, n);
}
void SelectionSort(int arr[], int n)
{
    int j, i, key;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    display(arr, n);
}
void InsertionSort(int arr[], int n)
{
    int i, j, key;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    display(arr, n);
}
void Merge(int arr[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low;
    int x = high - low + 1;
    int arrc[high + 1];
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            arrc[k++] = arr[i++];
        }
        else
        {
            arrc[k++] = arr[j++];
        }
    }
    while (i <= mid)
    {
        arrc[k++] = arr[i++];
    }
    while (j <= high)
    {
        arrc[k++] = arr[j++];
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = arrc[i];
    }
}
void MergeSort(int *arr, int low, int high)
{
    if (low < high)
    {
        int m = (low + high) / 2;
        MergeSort(arr, low, m);
        MergeSort(arr, m + 1, high);
        Merge(arr, low, m, high);
    }
}
void QuickSort(int *arr, int low, int high)
{
    int partitionIndex;
    if (low < high)
    {
        partitionIndex = partition(arr, low, high);
        QuickSort(arr, low, partitionIndex - 1);
        QuickSort(arr, partitionIndex + 1, high);
    }
}
int partition(int *arr, int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    while (arr[i] <= pivot)
    {
        i++;
    }
    while (arr[j] > pivot)
    {
        j--;
    }
    if (i < j)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    if (i >= j)
    {
        int temp = arr[low];
        arr[low] = arr[j];
        arr[j] = temp;
    }
    return j;
}
void heapSort(int arr[], int n)
{
    int t = n - 1;
    while (t--)
    {
        int temp = arr[1];
        arr[1] = arr[n];
        arr[n] = temp;
        n = n - 1;
        createMaxHeap(arr, n);
        //  createMinHeap(arr,n);
    }
}
void swap(int arr[], int ele, int i)
{
    int temp = arr[ele];
    arr[ele] = arr[i];
    arr[i] = temp;
}
void heapifyMax(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;
    if (left <= n && arr[left] > arr[largest])
    {
        largest = left;
    }
    if (right <= n && arr[right] > arr[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(arr, largest, i);
        heapifyMax(arr, n, largest);
    }
}
void createMaxHeap(int arr[], int n)
{
    for (int j = n / 2; j >= 1; j--)
    {
        heapifyMax(arr, n, j);
    }
}




// Searching Methods
void SequentialSearch(int arr[], int n, int find)
{
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == find)
        {
            flag = 1;
            printf("The element %d has been found at index %d :", find, i);
        }
    }
    if (flag == 0)
    {
        printf("Element not found\n");
    }
}
int BinarySearch(int arr[], int low, int high, int find)
{
    int i = low, j = high, m;
    int flag = 0;
    while (i <= j)
    {
        m = (i + j) / 2;
        if (arr[m] == find)
        {
            flag = 1;
            return m + 1;
        }
        else if (arr[m] > find)
        {
            j = m - 1;
        }
        else if (arr[m] < find)
        {
            i = m + 1;
        }
    }
    if (flag == 0)
    {
        return 0;
    }
}



int main()
{
    int size, find;
    printf("Enter the size of the array that you want\n");
    scanf("%d", &size);
    int arr[size];
    printf("Enter the elements in the array\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    // printf("Enter the element that you want to find\n");
    // scanf("%d",&find);
    //  BubbleSort(arr,size);
    //  SelectionSort(arr,size);
    //  InsertionSort(arr,size);
    // SequentialSearch(arr,size,find);
    // int x=BinarySearch(arr,0,size-1,find);
    // if(x==0){
    //     printf("No element is Found\n");
    // }
    // else{
    //     printf("The element %d found at index %d\n",find,x-1);
    // }

    printf("Before Sorting\n");
    display(arr, size);
    printf("After Sorting\n");
    // BubbleSort(arr,size);
    // SelectionSort(arr,n);
    // InsertionSort(arr,n);
    // MergeSort(arr, 0, size - 1);
    // QuickSort(arr, 0, size - 1);
    display(arr, size);
}