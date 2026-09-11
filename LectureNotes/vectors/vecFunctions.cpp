// exploring the vector functions 
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> vec ;
    //to push some values ino empty vector 
    vec.push_back(10);
    vec.push_back(30);
    vec.push_back(58);
    // to pop the last element 
    vec.pop_back();
    // to check the value of 1st element 
   cout <<  vec.front()  << endl ; 
   // to check the value of the last element 
   cout << vec.back() << endl ;
   // to check the size of the vector
   cout << vec.size() << endl ; 
   // to check if the vector is empty or not 
   cout << vec.empty() << endl ; 
   // to print the value at pertciular index 
   cout << vec.at(1) << endl ; 
   // to print value of vector 
   for(int val : vec){
    cout << val  << endl ;
   }
   return 0 ; 
}

