// #include <iostream>
// using namespace std ;

// // Function prototype (declaration)
// int add(int a , int b) {
//     return a + b ;
// }

// int main() {
//     int num1 , num2 ;
//     cout << " Enter Two Numbers to add ";
//     cin >> num1 >> num2 ;
//     //Calling Function 
//     int sum = add(num1 , num2);
//     cout << "The Sum of the two numbers is " << sum << endl ;
//     return 0 ; 
// }

#include <stdio.h>

int sum() {
    int a , b ;
    printf("Enter the a , b : ");
    scanf("%d%d" , &a , &b);
   int sumNum = a + b ;
   return sumNum ;
} 

int main() {
    int a = 20 , b = 20 ;
    int numSum = sum();
    printf("%d" , numSum);
    return 0 ; 
}


// Vinay 