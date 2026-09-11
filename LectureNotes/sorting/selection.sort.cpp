#include <iostream>
using namespace std;


void selectionSort(int arr[], int n) {
  for(int i = 0 ; i < n - 1 ; i++) {
    int smallestIdx = i ;
     for(int j = i + 1 ; j < n ; j++){
          if(arr[j] < arr[smallestIdx]){
            smallestIdx = j ;
          }
          // swap 
         swap(arr[smallestIdx] , arr[i]) ;
     }
  }
}

int main() {
    int arr[] = {6 , 8 , 5 , 4};
    int n = sizeof(arr) / sizeof(int) ;
    selectionSort(arr , n) ;
    for(int i = 0 ; i < n ; i++) {
        cout << arr[i] << " " ;
    }
    cout << endl ;
    return 0 ; 
}