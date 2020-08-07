#include <stdio.h>
#include <stdlib.h>

struct node{

    int data;
    struct node * left;
    struct node * right;

};

typedef struct node node;

node * getNewNode(int data)
{
    node * temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->left = 0;
    temp->right = 0;
    return temp;

}
//Pass the address of rootpointer
node *  insert(node * rootNode , int data)
{
    //If this is first node
    if(rootNode == 0){
        //Returns address
        rootNode = getNewNode(data);
        return rootNode;
    }

    //Now root is not empty
    else if(data <= rootNode->data){
        //Goes to left
        //Recursive call
        rootNode->left = insert(rootNode->left,data);

    }
    else{
        rootNode->right = insert(rootNode->right, data);
    }

    return rootNode;

}

int search(node * root, int data)
{

        if(root == 0){
            return 0;
        }
        else if(root->data == data){
            return 1;
        }
        else if(data<= root->data){
            return search(root->left, data);
        }
        else{
            return search(root->right, data);
        }

}


int main()
{
    //Root node
    node * rootPtr;
    rootPtr = 0;

    rootPtr = insert(rootPtr,16);
    rootPtr= insert(rootPtr,100);
    rootPtr=insert(rootPtr,10);




    return 0;
}
