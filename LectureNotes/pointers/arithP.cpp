#include <iostream>
using namespace std ; 
 
int main() {
    int a = 10 ;
   int* ptr = &(a);

   cout << ptr << endl ;
   ptr++ ;
   cout << ptr << endl ; 
   ptr += 2 ; // 2 int sized incrament will be there 
   cout << ptr << endl ; 
  return 0 ; 
}