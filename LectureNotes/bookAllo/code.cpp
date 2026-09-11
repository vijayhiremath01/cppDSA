#include <iostream>
#include <vector>
using namespace std ;

// to check whether it is valid or not !
bool isValid(vector<int> &arr , int n , int m , int maxAllowedPages ) { // O(n)
  int studentCount = 1 , pageSum = 0 ; 
    for(int i = 0 ; i < n ; i++){
        if(m > n) return false ; 
        if(pageSum + arr[i] <= maxAllowedPages){
            pageSum += arr[i];
        }else{
            studentCount++ ;
            if(studentCount > m || arr[i] > maxAllowedPages){
                return false ; 
        }else {
            pageSum = arr[i];
        }
    }
}
}

int allocateBooks(vector<int> &arr , int n , int m ){ // Time Complexity : O(logN * n)
    if(m > n) return -1 ;

    int sum = 0 ; 
    for(int i = 0 ; i < n ; i++){ // O(n)
        sum += arr[i] ;
    } 
    
    int ans = -1 ;
    int st = 0 , end = sum ; 
    while(st <= end) {
     int mid = st + (end - st) / 2 ; 
     if(isValid(arr , n , m , mid)){ // if it is valid go to left part 
       ans = mid ;
       end = mid -1 ;
     } else {
        st = mid + 1 ; 
     }
    }
    return ans ; 

}


int main() {
    int n , m ; 
    cout << "Enter the number of books " << endl ; 
    cin >> n ; 
    vector<int> arr(n);
    cout << "Enter the number of students " << endl ; 
    cin >> m ; 
    cout << "Enter the number of pages in each book " << endl ;
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i] ;
    }   
    cout << "The minimum number of pages allocated to a student is " << allocateBooks(arr , n , m) << endl ;
    return 0 ;
}