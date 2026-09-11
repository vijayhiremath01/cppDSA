#include <stdio.h>

int main(){
    int age = 18;
    int* ptr = &age;
    printf("%p" , (void*)ptr);
    int** ptr2 = &ptr ;
    printf("%p" , &ptr);
    return 0 ; 
}
