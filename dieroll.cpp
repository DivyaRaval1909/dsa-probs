#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int gcd(int a,int b)
{
    
    while(a > 0 && b > 0) {
        if(a > b) {
            a = a % b;
        }
         else {
            b = b % a; 
        }
        }
   
    if(a == 0) {
        return b;
    }
    
    return a;
    
}

int main() {
    int y,w;
    cin>>y>>w;
    int d=7-max(y,w);

    int gcd_=gcd(6,d);

    int deno=6/gcd_;
    int nume=d/gcd_;

    cout<<nume<<"/"<<deno<<endl;

    return 0;
}
