#include <iostream>
using namespace std ;

// Reverse an array 
int main(){
    int size ;
    cout << "Enter the size of the array : " << endl ; 
    cin >> size ;
    vector<int> arr(size);
    cout << "Enter the elements of the array : " << endl ;          
    for(int i = 0 ; i < size ; i++) {
        cin >> arr[i];
    }
    for(int i = 0 ; i < size / 2 ; i++){
       swap(arr[i] , arr[size - i - 1]);
       cout << "Swapped " << arr[i] << " and " << arr[size - i - 1] << endl ;
    } 
    return 0 ; 
}

