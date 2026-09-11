#include <iostream>
using namespace std;

int fun(int n) {
    if (n == 10){
        return n ; 
    }

    int count = 0 ; 
    cout << n << endl ;
    count++ ;
    return fun(n + 1) ;
}

int main(){

    int n ; 
    cin >> n ;
    cout << "The count is : " << fun(n) << endl ;

    return 0 ; 
}