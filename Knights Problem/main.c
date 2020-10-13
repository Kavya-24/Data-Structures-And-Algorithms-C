#include <stdio.h>
#include <stdlib.h>

int n = 8;
int k;
int doesIndexExits(int row int col){
    if(row >=n || row < 0 || col >=n || col<0 ){
        return 0;
    }

    return 1;

}

int doesIndexContains(int arr[n][n], int row, int col)
{
        if(arr[row][col] == 1){
            return 1;
        }

        return 0;

}
int isAllowed(int arr[n][n], int row, int col)
{
    //There are 8 ways/directions in which the
    int toCheckX= row;
    int toCheckY = col;

    //if index DNE, no issues, but of yes, check
    if(doesIndexExits(toCheckX+2, toCheckY +1) == 1 && doesIndexContains(arr, toCheckX+2, toCheckY+1) == 1){
        return 0;
    }
    if(doesIndexExits(toCheckX+2, toCheckY -1) == 1 && doesIndexContains(arr, toCheckX+2, toCheckY-1) == 1){
        return 0;
    }if(doesIndexExits(toCheckX-2, toCheckY +1) == 1 && doesIndexContains(arr, toCheckX-2, toCheckY+1) == 1){
        return 0;
    }if(doesIndexExits(toCheckX-2, toCheckY -1) == 1 && doesIndexContains(arr, toCheckX-2, toCheckY-1) == 1){
        return 0;
    }if(doesIndexExits(toCheckX+1, toCheckY +2) == 1 && doesIndexContains(arr, toCheckX+1, toCheckY+2) == 1){
        return 0;
    }if(doesIndexExits(toCheckX-1, toCheckY +2) == 1 && doesIndexContains(arr, toCheckX-1, toCheckY+2) == 1){
        return 0;
    }if(doesIndexExits(toCheckX+1, toCheckY -2) == 1 && doesIndexContains(arr, toCheckX+1, toCheckY-2) == 1){
        return 0;
    }if(doesIndexExits(toCheckX-1, toCheckY -2) == 1 && doesIndexContains(arr, toCheckX-1, toCheckY-2) == 1){
        return 0;
    }

        return 1;
}

void knights(int arr[n][n], int kni, int row, int col)
{

    if(row>=n || col>=n){
        return;
    }
    if(kni == 0){
        //All the knights have been placed
        //Print array
        printf("\n");
        for(int y=0; y<n;y++){
            for(int z=0; z<n;z++){
                printf("%d ", arr[y][z]);
            }
            printf("\n");
        }
        return;
    }

    //There will be four quadrants where we can add that knight. And, in doing so, we will see that the current row and column is not counted
    for(int i=row; i<n;i++){
            for(int j=col; j<n;j++){
                //Place on this
                if(isAllowed(arr, i,j) == 1){
                    arr[i][j] = 1;
                    knights(arr, kni--, );
                    arr[i][j] = 0;      //Backtrack

                }
            }
    }


    return;
}

int main()
{

    printf("Enter the knights you want to add on the chessboard: ");
    scanf("%d", &k);

    int  arr[n][n];
    memset(arr, 0, n*n*sizeof(int));

    printf("\n\nThe Squares are given by:\n");
    knights(arr,k, 0,0);
    return 0;
}
