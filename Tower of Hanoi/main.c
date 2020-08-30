#include <stdio.h>
#include <stdlib.h>


int count=0;
void printTowerMoves(char x, char y)
{
    count++;
    printf("Moving from %c to %c\n",x,y);
    return;

}

void hanoi(char a, char b, char c, int n)
{

    if(n==1){
        //Base case
        printTowerMoves(a,b);
    }

    else{

        hanoi(a,c,b,n-1);
        printTowerMoves(a,b);
        hanoi(c,b,a,n-1);



    }



}

int main()
{

    //For the tower of Hanoi
    int n;
    printf("Enter the number of hoops: ");
    scanf("%d", &n);

    //print Hanoi
    hanoi('A', 'B', 'C', n);

    //The total steps
    printf("The total steps printed are %d", count);



    return 0;
}
