#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_INFINITE 1000

int n;

//The struct for data
struct Node{

    char * name;
    struct Node * next;
    int influence;
    int position;               //[0,n-1] indexing for easier key reference
};

typedef struct Node Node;

//The struct for enqueue, dequeue data
struct queueNode{

 int item;
 struct queueNode * nextPtr;

};

typedef struct queueNode qNode;

int max(int a, int b)
{
    if(a>b){
        return a;
    }
    return b;
}

int LCS(char * X, char * Y,int m1, int m2)
{
    int LCSArray[m1+1][m2+1];
    int result = 0;

    for (int i=0; i<=m1; i++)
    {
        for (int j=0; j<=m2; j++)
        {

            if (i == 0 || j == 0)
                LCSArray[i][j] = 0;

            else if (X[i-1] == Y[j-1])
            {
                LCSArray[i][j] = LCSArray[i-1][j-1] + 1;
                result = max(result, LCSArray[i][j]);
            }
            else LCSArray[i][j] = 0;
        }
    }
    return result;


}

Node* createNewNode(Node names[n], int i)
{
    Node * temp = (Node*)malloc(sizeof(Node));
    temp->name = malloc(strlen(names[i].name+1));
    strcpy(temp->name, names[i].name);
    temp->position = names[i].position;
    temp->influence = names[i].influence;
    temp->next = 0;

    return temp;
}

void addToNetwork(Node names[n], int i, int j)
{

    //i is the parent base
    //names[j] is the element to add to the adjacency list
    Node *temp = &names[i];

    while(temp->next != 0){
        //Check till it reaches the last element
        temp = temp->next;
    }
    //Now temp is the last node
    //Create a newNode
    //On i add j
    temp->next = createNewNode(names, j);
    return;
}

void createNetwork(Node heads[n])
{
    //Array and linked list to make the adjacency list
    //Check for each element

    for(int i=0; i<n;i++){
        char *name1 = heads[i].name;
        int m1 = strlen(name1);

            for(int j = i+1; j<n;j++){
            //Base to add is names[i] and add names[j] to it if the network is created
            char *name2 = heads[j].name;
            int m2 = strlen(name2);
            int lcsValue = LCS(name1, name2, m1, m2);

            if(lcsValue >=2){
                //Add them to network
                //Undirected graph addition
                addToNetwork(heads,i, j);
                addToNetwork(heads, j,i);
            }

        }
    }

    return;

}

void printAdjacencyList(Node * toPrintName)
{
        Node * temp = toPrintName;
        while(temp != 0){
            printf("%s->", temp->name);
            temp = temp->next;
        }

        free(temp);
        //If friends is 0, then there is no element friend connected to it
        //The number of friends is the number of members in first hop
        //Their influence will be squared
        return;
}

void printNetwork(Node names[n])
{

    for(int i = 0; i<n;i++){
        //Print each linked list
        printAdjacencyList(&names[i]);
        printf("\n");
    }

    return;

}

//Used in calculating the second children while calculating intimacy
int addSecondChildren(Node names[n], int array[n], int childPosition, int p1, int p2 )
{

        int s = 0;
        Node * child = &names[childPosition];
        while(child != 0)
        {

            if(child->position != p1 && child->position != p2){
                if(array[child->position] == 0){
                    //Then this has not been discovered
                    array[child->position] = array[child->position] + 1;
                    s++;
                }
            }
            child = child->next;
            if(child == 0)
            {
                return s;


            }
        }



        return s;

}

//Used in calculation of influence
int getSecondChildren(Node names[n], int childPosition, int array[n])
{
        int s = 0;
        Node * child = (names+childPosition)->next;
        while(child != 0)
        {

                if(array[child->position] == 0){
                    //Then this has not been discovered
                    array[child->position] = array[child->position] + 1;
                    s++;
                }

            child = child->next;
            if(child == 0)
            {

                return s;

            }
        }



        return s;

}

//Finding the influence of a name
int influence(int p1, Node names[n])
{

    Node * parent = &names[p1];
    Node * ptr = (names+p1)->next;
    int second = 0;
    int first = -1;
    int arr[n];
    memset(arr, 0, sizeof(arr));
    arr[p1] = 1;

    while(parent != 0){
        first++;
        arr[parent->position] = 1;
        parent = parent->next;
    }

        //Check children
    while(ptr !=0){
            second = second + getSecondChildren(names,ptr->position,arr);

            ptr = ptr->next;
    }


    int inf = first*first + second;
    return inf;

}

//Finding intimacy between two struct nodes
int intimacy(int p1, int p2, Node names[n])
{
    //Get positions of all the children of the Nodes numbered p1, p2
    Node * parent1 = &names[p1];
    Node * parent2 = &names[p2];

    int array1[n];
    int array2[n];
     //Init
     memset(array1, 0, sizeof(array1));
     memset(array2, 0, sizeof(array2));

    //Add first child
    //Add second children of first child
    int second1 = 0;
    int second2 = 0;

    int first1 = -1;
    int first2 = -1;

    //Parent 1 is always fixed
    while(parent1 != 0){
        first1++;
        if(parent1->position != p1){
            //When it is not at the position of the orignal parents
            //This was the first neighbour
            //array1[parent1->position] = array1[parent1->position] + 1;
            //These children will be the ones whose second children we will count
            second1 = second1 + addSecondChildren(names,array1,parent1->position,p1,p2);

        }
        parent1 = parent1->next;
    }


    while(parent2 != 0)
    {
            first2++;

            if(parent2->position != p2){
            //When it is not at the position of the original parents
            //These children will be the ones whose second children we will count
            second2 = second2 + addSecondChildren(names,array2,parent2->position,p1,p2);

           }

            parent2 = parent2->next;


    }


    int intimacy = 0;
    for(int i=0; i<n;i++){
        if(array1[i] == array2[i] && array1[i] == 1)
        {
            intimacy++;
        }
    }



    return intimacy;
}

//Check for condition1
int doesEdgeFollowMinimumThreshold(int p1, int p2, Node names[n], int threshold)
{

    int inti = intimacy(p1,p2,names);
   // printf("\nIntimacy between names %s %s is %d",names[p1].name, names[p2].name,inti);
    if(inti >= threshold){
        return 1;
    }

    return 0;


}

//Check for condition2;
int doesFollowAbsoluteDifferenceFromSource(int p1, int p2, Node names[n], int t)
{

    //p1 is the source
    intimacy(p1,p2,names);
    //Now p1, and p2 will have their influences written in the struct Nodes
    int influenceOfSource = names[p1].influence;
    int influenceOfChild = names[p2].influence;
    //printf("\nInfluence between names %s %s is %d and %d",names[p1].name, names[p2].name,influenceOfSource, influenceOfChild);


    if(abs(influenceOfChild-influenceOfSource) <= t){
        return 1;
    }

    return 0;

}



//Main function
int main()
{
    //Sample at the end

    int t, threshold;
    printf("Enter the number of people you want in the network: ");
    scanf("%d", &n);

    //Adjacency list of Nodes with heads aligned in an array
    printf("\nEnter the names of the people\n");
    Node heads[n];
    char arr[20];

    for(int i=0; i<n;i++){
        scanf("%s", &arr);
        Node *p = (Node*)malloc(sizeof(Node));
        p->name = malloc(strlen(arr+1)+1);
        strcpy(p->name, arr);
        //This p is he head of the adjacency list
        p->next = 0;
        p->influence = 0;
        p->position = i;
        heads[i] = *p;

    }

    //Create a network
    for(int i=0; i<n;i++){
        printf("%s ", heads[i].name);
    }
    createNetwork(heads);

    //Print network
    printf("\nThe network is given by:\n");

    //This is the network of the first hop neighbors
    printNetwork(heads);

    //Populate Influence
    for(int i=0; i<n;i++){
        heads[i].influence = influence(i,heads);
    }



    printf("\nEnter the minimum threshold for the intimacy between the elements: ");
    scanf("%d", &threshold);
    printf("\nEnter the value of absolute difference t: ");
    scanf("%d", &t);

    char toFindSocietyName[20];
    printf("\nEnter the name whose society you want to find: ");
    scanf("%s", &toFindSocietyName);
    //threshold is the intimacy between each edge
    //Influence will be differed from the person
    //Find the node which we will use as source
    int posit = -1;
    for(int i=0; i<n;i++){

        if((strcmp(heads[i].name,toFindSocietyName)) == 0){
            //This is the person we are looking at
            posit =i;
            break;
        }
    }

    if(posit ==-1){
        //The the name entered does not exist
        printf("\nNo person of name %s exists in the network",toFindSocietyName);
        return 0;
    }

    //Now create the path
    int answer[n];                                                   //Stores position of the answers in terms of distance
    memset(answer, -1, sizeof(answer));                  //-1 to show that it cant be reached

    int colors[n];
    memset(colors, -1, sizeof(colors));
    //Colors indicate states
    //-1 is undiscovered
    //0 is discovered
    //1 is finished

    answer[posit] = 0;
    colors[posit] = 0;



    //We have a threshold and a minimum influence
    //USE BFS with minimum influence and edge threshold condition
    //Create a linked list of the positions

    qNode * head = 0;
    qNode * now;
    //Add the source to it
    //Initialization
    qNode * ptr = (qNode*)malloc(sizeof(qNode));
    ptr->item = posit;
    head = ptr;
    ptr->nextPtr = 0;
    now = ptr;


    while(head != 0){
        //State to reference with the Queue values
        //Dequeue the head thing
        //Enqueue and increment tail

        int u = head->item;
        //This is the source whose children we will add in the list
        Node * source = (heads + u)->next;
        //printf("\nThe item dequeued is %d and its first child is %d", u,source->position);

        while(source != 0)
        {
            //Add in answer
            //Check both the conditions
            //If source is the original node
        if(source->position != u){
            if(doesEdgeFollowMinimumThreshold(u,source->position,heads,threshold) ==1 && doesFollowAbsoluteDifferenceFromSource(u,source->position,heads,t)==1)
            {

                    if(colors[source->position] == -1){
                    //Undiscovered Node
                    answer[source->position] = answer[u] + 1;

                    //Enqueue
                    //printf("\nAdding node of position %d", source->position);
                    colors[source->position] = 0;       //Discovered and added
                    qNode * newPointer = (qNode*)malloc(sizeof(qNode));
                    newPointer->item = source->position;
                    newPointer->nextPtr = 0;
                    now->nextPtr = newPointer;
                    now = newPointer;
                    //This is the newNode added
                }



                }
            }



            source = source->next;
            if(source == 0){
                break;
            }

        }

        colors[u] = 1;                                                      //Finished Node
        head = head->nextPtr;

        if(head == 0){

            //Print the answer array
            printf("\nThe society of person %s,where absolute value of t is = %d and minimum edge threshold is = %d : \n", toFindSocietyName,t,threshold);
            for(int b =0; b<n;b++){
                printf("%s\t%d\n", heads[b].name,answer[b]);
            }
            printf("\n\n(In the above representation, all the members with there distances are given from the source position = %d, named %s)\n(-1 represents it does not exist in the society)",posit, heads[posit].name);

            return 0;
        }



    }

    /*Example:
        Input n = 6
        NAME
        kavya
        raima
        nita
        nirali
        aryani
        vani

        //The resultant network is
        kavya->aryani->
        raima->nirali->
        nita->nirali->aryani->vani->
        nirali->raima->nita->aryani->vani->
        aryani->kavya->nita->nirali->vani->
        vani->nita->nirali->aryani->

        The answer will be an array denoting distance from source (The person1 of the society)
        -1 will denote it does not lie it its society



    */



     return 0;
}
