// To check minimum of two number 
#include <iostream>
using namespace std ;

// Functions Prototype 
int minOfTwo(int a , int b){
    if(a < b){
        cout << a << " is Minimum " << endl ;
        return a ;
    }else {
        cout << b << " is Minimum " << endl ;
        return b ; 
    }
}

int main() {
    int num1, num2;
    cout << "Enter The numbers you want to check : ";
    cin >> num1 >> num2 ;
    // Calling a function 

    minOfTwo(num1 , num2);
    return 0 ; 
}