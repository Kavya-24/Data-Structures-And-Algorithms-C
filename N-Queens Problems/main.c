#include <stdio.h>
#include <stdlib.h>

//Global
int n;

int check_row(int  arr[n][n], int tow, int column)
{

        int j;
        for(j=0; j< n;j++){
            if(arr[tow][j]== 1){
                return 0;
            }
        }

    return 1;
}

int check_column(int  arr[n][n], int tow, int column)
{

        int i;
        for(i=0; i< n;i++){
            if(arr[i][column]== 1){
                return 0;
            }
        }

    return 1;
}


int check_diagonal(int arr[n][n], int tow, int column)
{
       //Left diagonal
       int i = tow;
       int j = column;

       while(i >= 0 && j >=0){
            if(arr[i][j] == 1){
                return 0;
            }
            i--;
            j--;
       }

       //Right Diagonal
       i = tow,
       j= column;


       while(i >=0 && j < n){
            if(arr[i][j] == 1){
                return 0;
            }
            i--;
            j++;
       }


    return 1;
}


int isSafe(int  arr[n][n], int row, int column)
{
    return check_column(arr,row, column) && check_diagonal(arr,row, column) && check_row(arr, row, column);


}

//X is the number of placed
int placeMyQueens(int  arr[n][n], int row, int column)
{
    if(row >=n){
        //Case when all the queens are placed successfully
        //Print all such combinations
        printf("\n");
        for(int u=0; u<n;u++){
            for(int v=0; v<n;v++){
                printf("%d ", arr[u][v]);
            }
            printf("\n");
        }
        return 1;
    }

    //Start with the row,
    int j;
    for(j=0; j<n;j++){
        //Check if it is safe to add in that location

        if(isSafe(arr, row, j) == 1){
            arr[row][j] = 1;

            //if
                placeMyQueens(arr,row+1, j+1);
               // {
                //If the queens can be placed in the next positions
                //This one will not be returned if we want to print all the possible combinations
              //  return 1;
           // }
            arr[row][j] = 0;
        }

    }



    return 1;

}

int main(){

    printf("Enter the number of queens you want to add: ");
    scanf("%d", &n);

    int  arr[n][n];
    memset(arr, 0, n*n*sizeof(int));

    //Use Backtracking
        printf("\n\nThe Squares are given by:\n");
        placeMyQueens(arr, 0,0);


    //This was when only one map is given and we were to find the first such ocurring set




    return 0;
}
