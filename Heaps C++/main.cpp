#include <iostream>
#include <bits/stdc++.h>
using namespace std;



int n;
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

     //No conditions of i, safe assumptions

     //When the root data is greater than its left and right subtree
     if(rootData > leftData && rootData > rightData){
        return;
     }

     //if the left child is greater
/*
1
3
5
4
6
13
10
9
8
15
17
*/
     int largerIndex = indexRoot;
     if(leftData > arr[largerIndex] && indexLeft < n){
        //
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

void min_heapify(int arr[], int n, int i)
{
    //Check its parent
    int indexParent = (i-1)/2;
    int parentData = arr[indexParent];
    int rootData = arr[i];

    //Return condition
    if(rootData < parentData){
        return;
    }

    int smallest = i;
    if(parentData > rootData && indexParent >=0){
        //Then we have to shif and heapify
        swapData(arr+i, arr+indexParent);
        smallest = indexParent;
        min_heapify(arr,n,smallest);
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

void buildMinumumHeap(int arr[], int n)
{
    //Build min heap
    //Parent is (i-1)/2
    int firstLeaf = (n/2);
    for(int i=firstLeaf; i<n;i++){
        min_heapify(arr,n,i);
    }

}


void printHeap(int  arr[], int n)
{
        for(int i=0; i<n;i++){
            printf("%d ",arr[i]);
        }
        cout<<endl;

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

    printf("Enter the n or total number of element: ");
    scanf("%d", &n);

    int arr[n];
    int arr2[n];
    for(int i=0; i<n;i++){
        cin>>arr[i];
        arr2[i] = arr[i];
    }

    printf("\nMAX HEAPS:\n");
    printf("The input array is given by:\n");
    printHeap(arr, n);

     //In this array, we need to heapify only the last few elements
    printf("\nThe Heap built from the array is given by:\n");
    buildHeap(arr, n);
    printHeap(arr,n);

    //Print a sorted list
    //Create an empty array
    heapSort(arr, n);
    printf("\nThe sorted array is given by:\n");
    printHeap(arr, n);

    printf("\n\nMIN HEAPS:\n");
    printf("The input is given by:\n");
    printHeap(arr2, n);

    printf("\nThe Heap built from the array is given by:\n");
    buildMinumumHeap(arr, n);
    printHeap(arr,n);



    return 0;
}
