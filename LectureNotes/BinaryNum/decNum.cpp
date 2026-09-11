//Program to find the Binary number of a Decimal number using Functions 
#include <iostream>
using namespace std ;

int decTobinary(int decNum ){
     int ans = 0 ;
     int power = 1 ;
     while(decNum > 0){
        int rem = decNum % 2 ;
        decNum = decNum / 2 ;
        ans += (rem * power) ; 
        power *= 10 ; 
     }
     return ans ; 
}

int main(){
    int n ; 
    cout << " Enter the decimal number :";
    cin >> n ;
    cout << " The binary number of the given decimal number is : " << decTobinary(n) << endl ;  // called function 
// to find binary numbers of decimal numbers upot n 
// for(int i = 1 ; i <= n ; i++){
//     cout << "The binary number of decimal number " << i << " is :" << decTobinary(i) << endl ; 
// }

    return 0 ; 
}