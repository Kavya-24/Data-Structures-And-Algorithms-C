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

int maximum(int arr[], int n)
{
    return arr[0];
}

int extractMaximum(int arr[], int n)
{
    int y = arr[0];
    int lastElement = arr[n-1];
    arr[0] = lastElement;
    //Now we have (n-1) terms with children as heaps, but only master parent as non-heap
    max_heapify(arr, n-1, 0);




    return y;
}

void createAndInsert(int arr[], int val, int n)
{
    arr[n-1] = val;
    int i = (n-1);      //(Index)
    while(i>=0){
        int parent = (i-1)/2;

        if(arr[parent] < arr[i]){
            swapData(arr+parent, arr+i);
            i = parent;
        }

        else{
            break;
        }



    }

    printf("\nThe heap after insertion is given by:\n");
    printHeap(arr,n);

}

int main()
{

    printf("Enter the n or total number of element: ");
    scanf("%d", &n);

    int arr[n];         //Max Heap
    int arr2[n];       //Min Heap
    int arr3[n];       //Priority Queue

    for(int i=0; i<n;i++){
        cin>>arr[i];
        arr2[i] = arr[i];
        arr3[i] = arr[i];
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

    ///Priority Queues are implemented using heaps
    //The four basic operations are given by
    //1. Insert(S,x)
    //2. Extract-Max(S)
    //3. Maximum(S)
    //4. Increase-Key (S,x,k)       (k is the new key)
    ///

    printf("\nThe operations for priority queue are:\n");

    //Build a max heap from arr3 for Priority queue
    buildHeap(arr3,n);

    //Print the maximum
    printf("\nThe maximum is given by %d", maximum(arr3, n));

    //Print and extract the maximum
    int c = extractMaximum(arr3, n);
    printf("\nThe maximum is given by %d", c);
    printf("\nThe heap after removing this (Extracting maximum) is:\n");
    printHeap(arr3, n-1);

    //Now we have a new array where the maximum is extracted
    int k, ind;
    printf("\nEnter the index of the element you want to change: ");
    cin>>ind;
    printf("\nEnter the value: ");
    cin>>k;

    //If the k is less than the value, then we wont  then (DONT TAKE n-1)
    if(k < arr3[ind]){
        cout<<"Key can not be less than the root element";
    }
    else{
        arr3[ind] = k;
        while(ind >= 0){
            //Find its parent and compare
            int parentIndex = (ind-1)/2;
                if(arr3[parentIndex] < arr3[ind]){
                    swapData(arr3+parentIndex, arr3 + ind);
                    ind = parentIndex;
                }
                else{
                    break;
                }

        }
    }

    printf("\nThe array after changing the value is given by:\n");
    printHeap(arr3, n-1);

    //Now insert a new key with a certain value
    int val;
    printf("\nEnter the value of the key you want to insert in the heap: ");
    cin>>val;

    //arr[n-1] is free
    createAndInsert(arr3,val,n);



    return 0;
}
