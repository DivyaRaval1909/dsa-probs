#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//even than not second possible odd than deleting and keep max freq

bool altstr(int n,string a)
{
    int c=0;
for (int i = 0; i < n-3; i++)
{
    if((a[i]==a[i+2])&&(a[i+1]==a[i+3])&&n%2==0)
    {
        c++;
    }

    if(c==n-4)
    return true;
    else
    return false;

}

}

int main() {
    int t;
    cin>>t;
    while (t--)
    {
       int n;
       cin>>n;
       string s;
       cin>>s;
    }
    

    return 0;
}
