#include <stdio.h>
#include <stdlib.h>


int n;

void swapData(int * a, int * b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    return;

}

int partitionPosition(int arr[], int n, int l, int r)
{

    if(l==r){
        //Case when there is no
        return l;
    }

    int pivot = arr[l];
    int i = l;
    int j = r+1;

    //Use do whiles


    while(i<j){
        do{
            i++;
        }while(arr[i] <= pivot);

        do{
            j--;
        }while(arr[j] > pivot);

        //If i<j
        if(i<j){
            swapData(arr+i, arr+j);
        }


    }

    //Breaks when i>j;
    //j is the pivot position
    swapData(arr+l, arr+j);


    //If all the elements are equal, then j will remain at last element and i will come there. At that moment, the loop will break
    //The partition returned will be the last element
    //The right half will be empty
    //Partition
    return j;

}

void quickSort(int arr[], int n, int l, int r)
{

    //If left is less than right


    if(l<r){
        int p = partitionPosition(arr,n,l,r);
        quickSort(arr, n, l, p-1);
        quickSort(arr, n, p+1, r);

    }







}


int main()
{
   //The idea is to find such a number which seems to be sorted
   //Either the smallest at front or the largest at last or xi st all elements before xi are less than equal to it and all after xi are greater than equal to it
  //xi is called sorted element
  //Uses divide and conquer strategy
  printf("Enter the number of elements: ");
  scanf("%d", &n);

  int arr[n];
  for(int i=0; i<n;i++){
    scanf("%d", &arr[i]);
  }

  quickSort(arr, n, 0, n-1);
  for(int i=0; i<n;i++){
    printf("%d ", arr[i]);
  }

    return 0;
}
