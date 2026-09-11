#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> vec ;
    vec.push_back(10);
    vec.push_back(30);
    vec.push_back(58);
  
    // to check the capacity of the vector
    cout << "Capacity of the vector is : " <<  vec.capacity() << endl ; 
    // to check the size of the vector
    cout << "Size of the vector is : " << vec.size() << endl ; 
 return 0 ; 
}
    