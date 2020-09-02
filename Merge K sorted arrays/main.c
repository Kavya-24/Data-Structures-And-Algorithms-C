#include <stdio.h>
#include <stdlib.h>


int n,m;

struct Node{

    int data;
    struct Node * next;

};

typedef struct Node node;


void swapData(node* a, node * b)
{

    int temp = a->data;
    node * n2 = a->next;
    a->data = b->data;
    a->next = b->next;
    b->data = temp;
    b->next = n2;

    return;
}


void printHeap(node * arr[], int n)
{
        for(int i=0; i<n;i++){
            printf("%d ",arr[i]->data);
        }
        printf("\n");

}


void min_heapify(node * arr[], int m, int i)
{
    //Check its parent
    //Recieves a heap array with nodes as elements and m elements and a inex for minum heap


    int indexParent = (i-1)/2;
    node *  parentNode = arr[indexParent];
    node * rootNode = arr[i];
    int parentData = parentNode->data;
    int rootData = arr[i]->data;

    //Return when the current data is greater than its parent (Property of Mim-Heap)
    if(rootData >= parentData){
        return;
    }


    int smallest = i;
    if(parentData > rootData && indexParent >=0){
        //Then we have to shif and heapify

        swapData(arr[i], arr[indexParent]);
        smallest = indexParent;
        min_heapify(arr,n,smallest);
    }


    return;

}
void buildMinumumHeap(node *  arr[], int m)
{
    //Build min heap
    //Parent is (i-1)/2
    //All the n leaves are going to be min-heapified
    int firstLeaf = (m/2);
    for(int i=firstLeaf; i<m;i++){
        min_heapify(arr,m,i);
    }

}



int main()
{

    printf("Enter the total number of arrays: ");
    scanf("%d",&m);


    printf("\nEnter the total number of elements: ");
    scanf("%d",&n);


    //The total size of the solution heap is n
    int output[n];
    int o = 0;

    node* heap[m];        //This will have a maximum of this heap. In case the values are null add some infinite value so
    int h = 0;

    node * heads[m];        //Pointer to store the heads of all the arrays in form of linked lists formed
    int c = 0;

    for(int i=0; i<m;i++){

        printf("\nEnter the elements of array #%d\n", i+1);
        //Create head and now and p for it
        node * head = 0;
        node * now = 0;
        node * p;
        int d;
        while(1){
            p = (node*)malloc(sizeof(node));
            scanf("%d", &d);
            p->data = d;
            p->next = 0;

            if(head == 0){
                //This is the new head and also here is where we will find the first element of each array
                head = p;
                now = p;
                heads[c++] = head;
                heap[h++] = head;
            }

            else{
                now->next = p;
                now = p;
            }

            int condition;
            printf("\nPress 1 to continue adding elements and 0 to exit: ");
            scanf("%d", &condition);
            if(condition == 0){
                break;
            }
        }

    }


    //All the linked lists have been chosen with the heads stored in the head[m] and the first heap of size m in heap[m];
    buildMinumumHeap(heap,m);
    printHeap(heap, m);


    while(m != 0){

        node * smallestInHeap = heap[0];
        int value = smallestInHeap->data;
        node * nextPointerToTheSmallest = smallestInHeap->next;

        output[o] = value;
        o++;

        //If the next pointer is null
        if(nextPointerToTheSmallest!= 0){

            heap[0]->data = nextPointerToTheSmallest->data;
            heap[0]->next = nextPointerToTheSmallest->next;
            //Build minimum heap from this
           buildMinumumHeap(heap,m);
        }

        else if(nextPointerToTheSmallest == 0){
            //For the item to be replaced, this was the element
            //Use the rest m-1 nodes to create the nodes as that array is complete

            //m is total size.
            //Index of the last is m-1
            //Now we need to delete the node

            swapData(heap[0], heap[m-1]);


            //Reduce m so as to not use it
            m--;
            buildMinumumHeap(heap, m);
            printHeap(heap, m);

        }





    }



    printf("\nThe sorted and merged array is given by:\n");
    for(int i=0; i<n;i++){
        printf("%d ", output[i]);
    }











    return 0;
}
