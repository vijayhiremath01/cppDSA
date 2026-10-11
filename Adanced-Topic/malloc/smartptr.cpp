#include <iostream>
#include <memory>

using namespace std ; 

int main(){
    auto ptr = make_unique<int>(10);

    cout << "Value of ptr: " << *ptr << endl ;
    // here we dont have to delete the pointer as it will be automatically deleted when it goes out of scope
    cout << "Address of ptr: " << ptr.get() << endl ;

    return 0 ; 
}