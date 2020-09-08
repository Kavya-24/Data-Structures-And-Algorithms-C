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

int randomIndex(int l, int r)
{
    //Return a random integer between l,r inclusive

    //The random raneg is given by
    int y = (rand() %(r-l+1)) + l;
    return y;


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


int findSmallest(int arr[], int l, int r, int s)
{
    //Get a random partition
    if(l==r){
        return arr[l];
    }

    if(l<r){
        int index = randomIndex(l,r);
        swapData(arr+l, arr+index);
        int k = partitionPosition(arr,n,l,r);

        //We can even find the p

        if(s <=k+1)
        {
            //First partition
            findSmallest(arr,l,k,s);
        }

        else{
            findSmallest(arr,k+1,r,s-k);
        }

    }



}


int main()
{
    int s,l;
    printf("Enter the number of elements");
    scanf("%d", &n);

    int arr[n];

    //Build a max heap for this and use heap-extract
    //Build a min heap and then also use heap-extract

    for(int i=0; i<n;i++){
        scanf("%d", &arr[i]);
    }

    //Use quick select

    printf("\nEnter the key for smallest");
    scanf("%d", &s);
    int x = findSmallest(arr,0,n-1,s);
    printf("\nThe %d  smallest element is %d", s,x);


    //use min and max-heap as well


    return 0;
}
