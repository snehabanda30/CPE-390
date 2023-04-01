#include <iostream> 
#include <cmath>

using namespace std; 

int main() {
    //count from 1 to 50 odd numbers only 
    for(int i =1; i<=50;i+=2) 
    {
        cout<< i;
    }

    //109876543221blastoff 
    for (int i = 10; i>0;i--) 
    {
        cout <<i;
    }
    cout<<"blastoff\n"<<endl;
    //1 2 3 4 5 6 ... 1064

   for (int i = 0; i<10; i++) 
    {
        cout << pow(2,i); 
    }
    // Faster For Loop
    for (int i = 1; i <=1024; i = i+1) 
    {
        cout<< i<<endl;
    }
}