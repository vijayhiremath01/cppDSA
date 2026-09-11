#include <iostream>
using namespace std ;

int main() {
    int n = 5 ;
    int arr[5] = {1 , 2, 3, 4, 5};
    int maxSum = INT_MIN ; 
    for(int start = 0 ; start < n ; start++) {
        int currSum = 0 ; 
        for(int end = start ; end < n ; end++){
           currSum += arr[end] ;
         maxSum = max(currSum , maxSum );
        }
    }
    cout << "The maximum sum of the subarray is : " << maxSum << endl ; 
    return 0 ;
} 