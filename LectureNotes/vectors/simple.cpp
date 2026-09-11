// learning vectors in c++ 
#include <iostream>
#include <vector>
using namespace std;

int main() {

    // integer vector 
    vector<int> vec = {1 , 2 , 3, 4, 5, };
    for(int i : vec) {
        cout << i << endl ; 
    }

    //character vector 
    vector<char> vecChar = {'a' , 'b' , 'c' , 'd' , 'e'};
    for(char i : vecChar){
        cout << i << endl ;
    }
 
    //fixed size vector
    vector<int> vecFixed(5 , 9);
    for(int val : vecFixed){
        cout << val << endl ; 
    }

    return 0 ; 
}