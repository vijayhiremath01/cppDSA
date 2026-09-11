// sum of digit of a number 

#include <iostream>
using namespace std ;

int sumOfDigits(int num){
    int sum = 0 ;
    while(num > 0){
    int lastDigit = num % 10 ;
    num = num / 10 ;
    sum += lastDigit ;
    }

    cout << "Sum of Digit of a number is :" << sum << endl ;
    return sum ;
}

int main(){
    int num ; 
    cout << "Enter a number to find sum of digits : ";
    cin >> num ;
    sumOfDigits(num);
    return 0 ;
}