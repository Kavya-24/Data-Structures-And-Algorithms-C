#include <stdio.h>
#include <stdlib.h>


int n,m;
void swapData(int * a, int * b)
{
    int temp = *a;
    *a = *b;
    *b = temp;

    return;
}

void max_heapify(int arr[], int n, int indexRoot)
{
     int indexLeft = (2*indexRoot + 1);
     int indexRight = (2*indexRoot + 2);
     int leftData = arr[indexLeft];
     int rightData = arr[indexRight];

     int rootData = arr[indexRoot];

     if(rootData > leftData && rootData > rightData){
        return;
     }

     int largerIndex = indexRoot;
     if(leftData > arr[largerIndex] && indexLeft < n){
        largerIndex = indexLeft;
     }


     if(rightData > arr[largerIndex] && indexRight < n){
        largerIndex = indexRight;
     }


     //Now we have an index
    //Now switch the values if the data at the root is not maximum
     if(largerIndex != indexRoot){
        swapData(arr + largerIndex, arr + indexRoot);
        //Heapify the subtree again
        max_heapify(arr, n, largerIndex);
     }



        return;


}

void buildHeap(int arr[], int n)
{
    //build heap and max_heapify
    //To be done with the nodes from 1 to (n)/2

    int lastNonLeaf = (n/2) -1;
    for(int i=lastNonLeaf; i>=0; i--){
        max_heapify(arr, n, i);
    }


}


void printHeap(int  arr[], int n)
{
        for(int i=0; i<n;i++){
            printf("%d ",arr[i]);
        }
        printf("\n");

}


void heapSort(int arr[], int n)
{
    //Remove the node from top,
    //i is the index from the
    //We have the heap already built

    for(int x = n-1; x>=0; x--){

        //In the already built heap, the top element (First element is the maximum)
        //Take it to the last (SWAP)
        //Then, heapify. This will

        swapData(arr, arr+x);

        //Reduce the size of the Heap
        max_heapify(arr, x, 0);

    }


    return;
}


int main()
{
    //m arrays of size n each
    int m,n;
    printf("Enter the number of arrays: ");
    scanf("%d",&m);

    printf("\nEnter the number of elements in each array: ");
    scanf("%d",&n);

    printf("\nEnter the elements of the array: ");

    int size  = n;
    int arr[size];

    printf("\nEnter the elements of the array:\n");
    for(int i=0; i<size;i++){
        scanf("%d",&arr[i]);
    }

    //Build heap from it
    buildHeap(arr, size);
    printf("\nAfter building the heap:\n");
    printHeap(arr,size);

    heapSort(arr, size);
    printf("\nAfter sorting the heap:\n");
    printHeap(arr,size);








    return 0;
}
