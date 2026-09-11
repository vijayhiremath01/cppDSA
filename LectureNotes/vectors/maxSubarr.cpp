#include <iostream>
using namespace std ;

int main() {
      int n ;
      cout << "Enter the size og the array : " << endl ; 
      cin >> n ;
      int arr[n] ;
      cout << "Enter the elements of the array : " << endl ; 
      for(int i = 0 ; i < n ; i++) {
        cin >> arr[i] ;
      }
      for(int start = 0 ; start < n ; start++){
        for(int end = start ; end < n ; end++){
            for(int i = start ; i <= end ; i++){
                cout << arr[i] ;
            }
            cout << " " ;
        }
        cout << endl ; 
      }

      return 0 ; 
}