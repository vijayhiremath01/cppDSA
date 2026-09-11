#include <iostream>
using namespace std ;

// int main(){
//     int a = 10 ;
//     int* ptr = &a ;
//     int** parentPtr = &ptr ;
//     cout << ptr << endl ;
//     cout << &a << endl ; 
//     cout << parentPtr << endl ; 
//     return 0 ; 
// }

void changeA(int* ptr){
     *ptr = 20 ;
}

int main(){
     int a = 10 ;
     changeA(&a);
     cout << "In main funx : " << a << endl ; 
     return 0 ; 
}