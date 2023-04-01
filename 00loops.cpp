#include <iostream> 

using namespace std; 

int main() {
    int a = 1; 
    while (a <= 10) {
        cout << a << "hello"; // hello\0
        a++; // a +=1; a = a+1; ++a; 
    }

    for( int i = 1; i<10 ; i++) 
    {
        cout<< i << ' '; 
    }
    // syntatically the same thing on machine language as well 
    cout<< '\n';
}