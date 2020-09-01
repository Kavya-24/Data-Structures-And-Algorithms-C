#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int totalPaths(int m , int n)
{
    if(m == 1 || n == 1){
        return 1;
    }

    //Traverse through all the rows, amd through all cols and then through diagonals
    return totalPaths(m, n-1) + totalPaths(m-1,n) + totalPaths(m-1, n-1);



}

int main()
{
    int t,m,n;
    cin>>t;

    for(int i=0; i<t;i++){
        cin>>m>>n;

        //A matrix of size m*n
        //Find the total paths
        int p = totalPaths(m,n);
        cout<<p<<endl;




    }


    return 0;
}
