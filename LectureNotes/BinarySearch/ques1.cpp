// Simple program to find Target using BinarySearch 

#include <iostream>
using namespace std ;

int binarySearch(int arr[] , int n , int target ){
    int start = 0 , end = n - 1 ; 

    while(start <= end){
        int mid = start + (end - start) / 2 ;

        if(arr[mid] > target){
            end = mid - 1 ; 
        }else if(arr[mid] < target){
            start = mid + 1 ;
        }else {
            return mid ; 
        }
    }
    return -1 ; 
}

int main() {
    int arr[] = {1 , 2, 4, 6, 7, 8, 12 };
    int n = sizeof(arr) / sizeof(arr[0]); // learned to check the size of the array 
  
    int target ; 
    cout << "Enter your target : " << endl ;
    cin >> target ;

    int targetFound = binarySearch(arr, n,target); // Just use parameter dont use datatypes here 

 if(targetFound != -1 ){
    cout << "Target found at : " << targetFound <<  endl ; 
 }else {
    cout << "Target not found 🥲 " << endl ; 
 }
    return 0;
}
