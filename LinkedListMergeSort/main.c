#include <stdio.h>
#include <stdlib.h>

struct Node{

    int data;
    struct Node * next;

};

typedef struct Node node;

void printList(node * x)
{
    printf("\n");
    while(x!=0){
        printf("%d ", x->data);
        x = x->next;
    }
}

node * partition(node * x, node *front,node*  back)
{

    node * slow = x;
    node * fast=x->next;

    if(x == 0 || x->next == 0){
        front = x;     //&a
        back = 0;     //&b
        return;
    }

    else{
        //When it is not the last element  or the only element
        slow = x;
        fast = x->next;

        while(fast!= 0){
            fast = fast->next;
            //If now fast is null
            if(fast !=0){
                //When it is not null
                slow = slow->next;
                fast = fast->next;

            }
        }



    }



        front = x; //First head
        back = slow->next; //Second head
        slow->next = 0;
        printList(front);
        printList(back);

        return slow;
}

node * mergeLists(node * a, node * b)
{
    //Returns the new head
    node * merged = 0;
    if(a==0){
        //First list is empty
        return b;
    }
    else if(b== 0){
        return a;
    }

    if(a->data <= b->data){
        merged = a;
        merged->next = mergeLists(a->next, b);
    }

    else{
        merged = b;
        merged->next = mergeLists(a, b->next);
    }

    return merged;

}
void mergeSort(node * head)
{

    //Get a partition
    node * source = head;
    node * a = 0;
    node * b = 0;

    if(head == 0 || head->next == 0){
        return;
    }

    node * part = partition(source, &a, &b);
    //Source is the original head

    mergeSort(&a);
    mergeSort(&b);
    head = mergeLists(a,b);


    return;

}

int main()
{

    int n;
    scanf("%d", &n);
    node * head = 0;
    node  *now;
    node * p;

    for(int i=0; i<n;i++){
        p = (node*)malloc(sizeof(node));
        p->next = 0;
        int x;
        scanf("%d",&x);
        p->data = x;

        if(head == 0){
            head =p;
            now = p;

        }
        else{
            now->next = p;
            now = p;
        }

    }

    printList(head);
    mergeSort(head);
    printList(head);



    return 0;
}
