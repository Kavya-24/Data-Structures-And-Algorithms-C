#include <iostream>

using namespace std;

int n = 4;

void printMaze(int arr[4][4])
{

     for(int i=0; i<4;i++){
        for(int j=0; j<4;j++){
           cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

}

bool checkCoordinates(int x, int y, int maze[4][4])
{
    if(x < 0 || y<0 || x>=n || y>=n || maze[x][y] == 0){
        return false;
    }

    return true;
}

bool solve(int   maze[4][4], int x, int y, int sol[4][4])
{

    //If first element is not 1 (0,0) then it will not be able to go further
    if(maze[0][0] == 0){
        return false;
    }

    //Check if it has reached the end
    if(x== 3 && y== 3 && maze[x][y] == 1){
         //Base condition
         sol[x][y] = 1;
        return true;
    }


    if(checkCoordinates(x,y, maze) == true){

            sol[x][y] = 1;

            //Go in x dirn
            if(solve(maze, x+1, y, sol) == true){
                return true;
            }

            //Go in y
            if(solve(maze, x, y+1, sol) == true){
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

    cout<<"\nThe solution is given by:\n";
    solveMaze(arr);


    return 0;
}
