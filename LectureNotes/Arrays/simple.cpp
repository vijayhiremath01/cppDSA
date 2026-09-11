// usage and declration of arrays 
#include <iostream>
using namespace std ; 

int main() {
    int arr[5] ;
    cout << "Enter 5 number to store in an array " << endl ;
    for(int i = 0 ; i < 5 ; i++){
      cin >> arr[i];
    }

    for(int i = 0 ; i < 5 ; i++){
        cout << arr[i] << " " ; 
    }
    return 0 ; 
}