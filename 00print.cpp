#include <iostream> 
using namespace std;

int main() { //WinMain  
    // int not guaranteed size, not guaranteed 
   
   {
    int a = 3 / 2; // Answer is one 
    int b = 7 / 2; // Answer is three 
    int c = 7 % 2; // 7 mod 2 (Remainder)
    int d = 2+3; 
    int e = 2 -3;
    }
    
    // what is a bit? 0/1 
    // on Arduino Uno 1=5v 
    // on Arduino Due 1 = 3.3 V 
    //How do you know which one to choose?
    uint8_t a;
    uint16_t b = 65535; 
    uint32_t c=10000000; 
    uint32_t d=123456789012345678ULL; 
    int age; 
    cout << "How old are you?" <<endl;
    cin>>age; 
    age=(age*365*24*60*60);
    cout << "Age is " << age << endl;
    //print out your age in seconds 


}