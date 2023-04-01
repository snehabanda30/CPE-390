#include <iostream>
#include <iomanip>
#include <cmath>
#include <bitset>
using namespace std;

/*"I pledge that I have abided by Stevens Honor System" - Sneha Banda"*/
void crypt(char mytext[], int n, uint8_t key)
{
    for(int i = 0; i<=n; i++) 
    {
        mytext[i]=mytext[i]^32;
    } 

}
uint32_t color(uint8_t r, uint8_t g, uint8_t b){
    return  uint32_t(r)<<16 | uint32_t(g)<<8;
}
void extractrgb(uint32_t color, uint8_t& r, uint8_t& g, uint8_t& b){
    r= uint32_t(color) >> 16; 
    g= uint32_t(color) >> 8; 

}
uint32_t compress2(const uint32_t x[], uint32_t len)
{ 
    uint32_t res = 0; 
    for(int i = 0; i< len; i++)
    {
        res=res<<=2;
        res = res+x[i];
    }
    
    return res;
}
uint64_t compress3(const uint32_t x[], uint32_t len)
{
    uint64_t res = 0; 
    for(int i = 0; i< len; i++)
    {
        res=res<<=3;
        res = res+x[i];
    }
    
    return res;

}


int main(){
    cout << "Question 1-----------------------------------" << endl;
    char a[6] = "hello";
    crypt(a, 5, 33);
    for (int i = 0; i < 5; i++) {
        cout << a[i] << " ";
    }

   cout << '\n';
    cout << "Question 2-----------------------------------" << endl;
    uint32_t c = color(0xFF, 0x80, 0x00); // should be 0xFF8000
    cout << bitset<32>(c) << '\n';

    cout << "Question 3-----------------------------------" << endl;
    uint8_t r, g, b;
    extractrgb(c, r, g, b);
    cout << "r=" << bitset<8>(r) << " g=" << bitset<8>(g) << "b=" << bitset<8>(b) << '\n';

cout << "Question 4-----------------------------------" << endl;
    const uint32_t a1[] = {1, 2, 3, 0, 1, 1, 3, 1, 1, 2, 3, 2};
    uint32_t packed1 =  compress2(a1, 12);
    cout << "packed array a1=" << packed1 << '\n';

 cout << "Question 5-----------------------------------" << endl;
    const uint32_t a2[] = {0, 7, 4, 6, 1, 5, 4, 4, 6, 1, 7, 5, 3};
    uint64_t packed2 = compress3(a2, 13);
    cout << "packed array a2=" << packed2 << '\n';
    cout << endl; 


   
    return 0;
}

/*
Question 1-----------------------------------
H E L L O
Question 2-----------------------------------
00000000111111111000000000000000
Question 3-----------------------------------
r=11111111 g=10000000b=00000000
Question 4-----------------------------------
packed array a1=7101806
Question 5-----------------------------------
packed array a2=65258284011
*/
