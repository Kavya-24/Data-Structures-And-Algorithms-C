#include <iostream>
#include <bits/stdc++.h>


using namespace std;

struct Node{
    int data;
    int frequency;
    struct Node * left;
    struct Node * right;
};



typedef struct Node node;

node * getNewNode(int data)
{
    node * temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->left = 0;
    temp->right = 0;
    temp->frequency = 1;
    return temp;

}

//Pass the address of rootpointer
node *  insertF(node * rootNode , int data)
{

    if(rootNode == 0){
        //Returns address
        rootNode = getNewNode(data);
        return rootNode;
    }

    //Now root is not empty
    else if(data < rootNode->data){
        //Goes to left
        //Recursive call
        rootNode->left = insertF(rootNode->left,data);

    }

    else if(data > rootNode->data){
        rootNode->right = insertF(rootNode->right, data);
    }
    //When it is equal, increment frequency
    else if(data = rootNode->data || data == 0){
        rootNode->frequency = rootNode->frequency +1;
    }

    return rootNode;

}

int findMajorityElement(node * root, int x)
{

    if(root == 0){
        //End element
        return -1;
    }
    if(root ->frequency  >  x){
        //If this element is zero

        return root->data;
    }

    //Else go to left and right subtree
    int dr1 = findMajorityElement(root->left, x);
    int dr2 = findMajorityElement(root->right, x);
    //Either -1 or the data.

    if(dr1 >dr2){
        return dr1;
    }
    return dr2;


}


int main()
{
    int t,n;
    cin>>t;

    for(int i=0; i<t; i++){
        cin>>n;
        int e;

        //Create an empty root pointer
        node * root ;
        root = 0;

        for(int j=0; j<n;j++){
            cin>>e;
            root = insertF(root,e);
        }

        //We have successfully created the root
        //The case is when we only have one majority element
        //May be even or odd

        int l = findMajorityElement(root, n/2);
        printf("%d",l);
        cout<<endl;



    }



    return 0;
}
