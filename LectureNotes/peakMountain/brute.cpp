#include <iostream>
using namespace std ; 

int main(){
    int arr[] = {2,5,8,6,9,13,67,18,56};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0 ; i < n ; i++){
        if(arr[i] > arr[i - 1] && arr[i] > arr[i + 1]){
            cout << "The Peak Index in the given array is :" << i << endl ; 
            return i ; 
        }

    }
    return -1 ; 
    
}