#include <iostream> 
using namespace std ; 

void bubbleSort(int arr[] , int n) {

    // checking 

    bool isSwap = false ;

    for(int i = 0 ; i < n - 1 ; i++) {
        for(int j = 0 ; j < n - i - 1 ; j++) {
            if(arr[j] > arr[j + 1]) {
                // swap 
                int temp = arr[j] ; // instead of using this we can use swap built in function
                arr[j] = arr[j + 1 ] ;
                arr[j + 1 ] = temp ;
                isSwap = true ; 
            }
        }
        if(!isSwap ) {
           return ; 
        }
    }
}

int main() {
    int arr[] = {6 , 8 , 5 , 4};
    int n = sizeof(arr) / sizeof(int) ; 
    bubbleSort(arr , n) ; 
    for(int i = 0 ; i < n ; i++) {
        cout << arr[i] << " " ;
    }
    return 0 ; 
}