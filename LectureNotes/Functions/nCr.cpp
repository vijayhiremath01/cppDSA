// To find nCr using functions 
#include <iostream>
using namespace std ;

int factorial(int n){
    int fact = 1 ;
    for(int i = 1; i < n ; i++){
        fact *= i ;
    }
    return fact ;
}

int nCr(int n , int r){
    int factN = factorial(n);
    int factR = factorial(r);
    int factNmR = factorial(n - r);
    int nCr = factN / (factR * factNmR);   
}

int main(){
    int n , r ;
    cout << "Enter the value of n : ";
    cin >> n ;
    cout << "Enter the value of r :" ;
    cin >> r ;
    cout << "nCr is " << nCr(n , r) << endl ;
    return 0 ;
}

