#include <iostream>
using namespace std ;

int binaryTodecimal(int binNum){
    int ans = 0 ; 
    int power = 1 ;
    while(binNum > 0){
        int rem = binNum% 10 ;
        binNum /= 10 ;
        ans += (rem * power);
        power *= 2 ;
    }
    return ans ; 
}

int main() {
    int binNum ; 
    cout << " Enter the Binary Number : ";
    cin >> binNum ; 
    cout << " The Decimal number of the given Binary number is : " << binaryTodecimal(binNum) << endl ; 
    return 0 ; 
}