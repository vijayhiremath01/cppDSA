// Finding Factorial of a number using Functions in C++ 

#include <iostream>
using namespace std;

int factorial(int n){
    if(n == 0){
        return 1 ;
    }else{
        int fact = 1 ; 
        for(int i = 0 ; i < n ; i++){
            fact *= (i+1);
        }
        return fact ;
    }
}

int main(){
    int n ; 
    cout << "Enter a number to find Factorial : ";
    cin >> n ;
    cout << "The Factorial of " << n << " is ";
    cout << factorial(n) << endl ; 
    return 0 ; 
}