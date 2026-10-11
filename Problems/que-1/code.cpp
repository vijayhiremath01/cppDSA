//Access an element at index

#include <iostream>
using namespace std ; 

int main(){

    int arr[] = {12,3,4,2,6,8,9};

    int idx ; 
    cout << "Enter the index to search an element : " << endl ; 
    cin >> idx ; 

    cout<< "The element at index " << idx << " is : " << arr[idx] << endl ; 

    return 0 ; 
}