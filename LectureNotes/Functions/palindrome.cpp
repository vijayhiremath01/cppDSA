// Ckecking palindrome using Functions and if-else statement 
#include <iostream>
#include <string>
using namespace std ;

bool isPalindrome(string str){
    int n = str.length();
    for(int i = 0 ; i < n/2 ; i++){
        if(str[i] != str[n - 1 - i]){
            return false ;
        }
    }
    return true ; 
}

int main(){
    string str ;
    cout << "Enter a String to check the palindrome : ";
    cin >> str ;
    if(isPalindrome(str)){
        cout << str << " is a Palindrome String" << endl ;    
    }else {
        cout << str << " is not a Palindrome String " << endl ; 
    }
    return 0 ;
}