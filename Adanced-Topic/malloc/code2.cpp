#include <iostream>
using namespace std ; 

int main(){

    int x = 10 ; 

    int* ptr = &x ; 

    *ptr = 50 ; 

    cout << "Value of x: " << x << endl ;

    return 0 ; 
}