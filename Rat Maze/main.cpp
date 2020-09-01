#include <iostream>

using namespace std;

int n = 4;

void printMaze(int arr[4][4])
{

     for(int i=0; i<n;i++){
        for(int j=0; j<n;j++){
           cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

}

bool checkCoordinates(int x, int y)
{
    if(x < 0 || y<0 || x>=n || y>=n){
        return false;
    }

    return true;
}

bool solve(int   maze[4][4], int x, int y, int sol[4][4])
{
    //Check if it has reached the end
    if(x== n-1 && y== n-1 && maze[x][y] == 1 && sol[x][y] == 1){
        return true;
    }

    if(checkCoordinates(x,y) == true){

        sol[x][y] = 1;

        //Go in x dirn
        if(solve(maze, x+1, y, sol) == true){
         return true;
        }

        //Go in y
        if(solve(maze, x, y+1, sol)){
                return true;
        }


        //If this is not possible,
        //Backtrack

        sol[x][y] = 0;
        return false;

    }


    return false;


}




bool solveMaze(int maze[4][4])
{
    //Create a solution array
    int solution[4][4];
    for(int i=0; i<4;i++){
        for(int j=0; j<4;j++){
            solution[i][j] = 0;
        }
    }

    if(solve(maze, 0,0,solution) == false){
        cout<<"\nSolution does not exist";
        return false;
    }

    printMaze(solution);
    return true;


}




int main()
{


    int arr[4][4];
    cout<<"Enter the grid. Put 0 for dead end and 1 for available space:\n";

    for(int i=0; i<4;i++){
        for(int j=0; j<4;j++){
            cin>>arr[i][j];
        }
    }

    cout<<"The input maze is given by\n";
    printMaze(arr);

    solveMaze(arr);


    return 0;
}
