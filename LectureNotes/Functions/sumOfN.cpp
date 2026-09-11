#include <iostream>
using namespace std ;

// Function Prototype 
int sumOfN(int num){
    int sum = 0 ;
    for(int i = 0 ; i <= num ; i++){
        sum += i ;
        
    }
    return sum ;
}

int main() {
    int num ;
    cout << "Enter The Number :";
    cin >> num ;
    // Calling a function 
    int result = sumOfN(num);
    cout << "The sum of the first " << num << " Natural numbers is " << result << endl ; 
    return 0 ; 
}