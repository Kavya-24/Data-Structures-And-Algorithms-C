#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

//Print mirror tree
void mirror(node* node)
{
    node * t = node;

    node* temp = (node*)malloc(sizeof(node));

    if(t == NULL){
        return;
    }

    //What we want to do is to create
    temp = t->left;
    t->left = t->right;
    t->right = temp;


    mirror(t->left);
    mirror(t->right);

}

//Print the nodes at a distance k from the root node
// function should print the nodes at k distance from root
void printKdistance(struct node *root, int k)
{
  if(root == 0){
      return;
  }
  if(k == 0){
      printf("%d ", root->data);
  }

 else if(k >0){
        //Go in left and right both directions
        printKdistance(root->left, k-1);
        printKdistance(root->right, k-1);
  }

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
        //Check wrt to the numerical data
        else if(data<= root->data){
            return search(root->left, data);
        }
        else{
            return search(root->right, data);
        }

}

//For minimum, we can reduce it to finding the minimum in that tee and its respective subtrees
int recMin(node* p)
{
      if(p==0){
        printf("The tree is empty");
        return -1;
    }
    if(p->left == 0){
        return p->data;
    }
      return recMin(p->left);
}

int recMax(node*p)
{
    if(p==0){
        printf("The tree is empty");
        return -1;
    }
        if(p->right ==0){
            return p->data;
        }

       return recMax(p->right);

}


int findMin(node * root)
{

    //Empty tree
    if(root==0){
        printf("The tree is empty");
        return -1;
    }
    node * temp = root;
    //go to left child
   while(temp->left != 0){
    temp = temp->left;
   }

   return temp->data;

}

int findMaz(node* root)
{
    //Root is a local variable
     if(root==0){
        printf("The tree is empty");
        return -1;
    }
    node * temp = root;
    //go to left child
   while(temp->right != 0){
    temp = temp->right;
   }

   return temp->data;


}



int findHeight(node * root)
{
    //Leaf node
    if(root == 0){
        return  -1;
    }

    int lh = findHeight(root->left);
    int rh = findHeight(root->right);
    int x = rh;
    if(lh > rh){
        x = lh;
    }
    return   x+1;
}

node *  deleteNode(node * root, int data)
{
    if(root == 0){
        return root;
    }

    if(data < root->data){
        root->left = deleteNode(root->left, data);
    }
    else if( data > root->data){
        root->right = deleteNode(root->right, data);
    }
    else if ( data == root->data){
        //Find min in right subtree
        //No child case
        if(root->left == 0 && root->right == 0){
            //Deallocate
            free(root);
            root = 0;
            return root;
        }
        //No left child
        else if(root->left == 0){
                node * temp = root;
                root = root->right;
                free(temp);
                return root;
        }
        //No right child
        else if(root->right == 0){
                node * temp = root;
                root = root->left;
                free(temp);
        }

        //Both children present
        else if(root->right != 0 && root->left != 0){
            //Search the min in the right sub tree
            int val= findMin(root->data);
            root->data = val;
            deleteNode(root, data);
            return root;
        }




    }


    //If the data has only one child, we link that child to the parent of the to be del node
    //If more than one child. Min from right subtree  or max in leftto the oarent. This will be no left child to that node


}

///Also use InOrder traversal and check state if they are in ascending order
int isBinarySearchTree(node * p, int minValue, int maxValue)
{
    if(p==0){
        return 1;
    }
    if(p->data >= minValue && p->data < maxValue && isBinarySearchTree(p->left, minValue, p->data) && isBinarySearchTree(p->right, p->data, maxValue) ){
        return 1;
    }

}




///root then left then right
void preOrderTraversal(node * root)
{
    //Print the data
    if(root == 0){
        return;
    }
    printf("%d ", root->data);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);

}

void postOrderTraversal(node * root)
{
    if(root==0){
        return;
    }

    ///L R D
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf("%d ", root->data);

}

void inOrder(node * root)
{

    if(root==0){
        return;
    }
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);

}

void printLevel(node * root, int level)
{
    if(root == 0){
        //Either empty or at leaf node
        return;
    }
    //Reaches the last level in all
    if(level == 1){
        printf("%d", root->data);
    }
    else if(level >1){
        printLevel(root->left, level-1);
        printf(" ");
        printLevel(root->right, level-1);
    }

}

void levelOrder(node * root)
{
    if(root == 0){
        printf("\nTree is empty");
        return;
    }
    //Use the recurion to find the height and then printBy level
    int h = findHeight(root);

    for(int i=0; i<=h+1; i++){
        printLevel(root,i);
        printf("\n");
    }

    //Create a queue
    //C++
   /* queue<node*> q;
    q.push(root);
    while(!q.empty()){
        node * front = q.front();
        printf("%d", front->data);
        if(front->left != 0){
            q.push(front->left);
        }
        if(front->right != 0){
            q.push(front->right);
        }
        //Dequeue
        q.pop();
    } */

}


int main()
{
    //Root node
    node * rootPtr;
    rootPtr = 0;

    rootPtr=insert(rootPtr,7);
    rootPtr=insert(rootPtr,4);
    rootPtr=insert(rootPtr,9);
    rootPtr=insert(rootPtr,1);
    rootPtr=insert(rootPtr,6);


    //Tye minimum will be in Left BST and the maximum in Right BST
    printf("The maximum and minimum elements from while loop are %d and %d", findMaz(rootPtr), findMin(rootPtr));
    printf("\n Min and max from recursion is %d and %d", recMin(rootPtr), recMax(rootPtr));


    //To find height of the subtree, it will max of left subtree and right subtree +1
    //Use recursive functions to call for a smaller unit of Left subtree and same for right subtree
    printf("\nThe height of the trees is %d. Of left st is %d and right st is %d", findHeight(rootPtr), findHeight(rootPtr->left), findHeight(rootPtr->right));

    //Tree transversal
    //Breadth First- goes to next level only when all the nodes of the same levl are done ltr = level order traversal
    //depth approach. L Root R , Inorder tranversal == ives sorted lsit
    // L R root  and , Post Order Traversal
    //root L R == visiting all the chioldren = preorder
    //Left always visted before

        ///Level Order - Breadth Traversal
        //Enqueue a node, then fifo and visit its childre
        //First enquee the left then the right child
        //Algorithm
        printf("\nLevel Order Traversal:\n");
       levelOrder(rootPtr);

       printf("\nPre Order Traversal:\n");
       preOrderTraversal(rootPtr);

       printf("\nPost Order Traversal:\n");
       postOrderTraversal(rootPtr);

       printf("\nInOrder Traversal:\n");
       inOrder(rootPtr);

        //Time complexity : O(n)
        //Space Complexity O(h) prop to log n  O(n) = worst case

        //check the binary search trees
        int val = isBinarySearchTree(rootPtr, findMin(rootPtr), findMaz(rootPtr));
        if(val == 0){
            printf("\nIt is not a BST");
        }
        else{
            printf("\nIt is a BST");
        }

        //Delete a node
        deleteNode(rootPtr,6);
        printf("\n");
        inOrder(rootPtr);





    return 0;
}
