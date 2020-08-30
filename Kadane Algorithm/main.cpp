#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t,n;
    cin>>t;
    for(int i=0; i<t;i++){
        cin>>n;
        int arr[n];
        int numN = 0;
        int maximum = -10000000;
        for(int j=0; j<n;j++){
            cin>>arr[j];
            if(arr[j] < 0){
                numN++;
            }
            if(arr[j] >maximum){
                maximum = arr[j];
            }
        }

        //Kadane's Algorithm
            if(numN == n){
             //All the numbers are negative
             printf("%d\n", maximum);
            }

            else{
                int max_so_far = 0;
                int max_ending_here = 0;

                for(int j=0; j<n;j++){
                    max_ending_here = max_ending_here + arr[j];
                    if(max_so_far< max_ending_here){
                        //Get to the value
                        max_so_far = max_ending_here;
                    }
                    //When it meets some large negative value.
                    if(max_ending_here < 0){
                        max_ending_here = 0;
                    }
            }
          printf("%d\n", max_so_far);





            }


    }





    return 0;
}
