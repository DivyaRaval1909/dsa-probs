#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define ull unsigned long long
#define mxx 1e18 - 1
using namespace std;
using namespace std;
int main()
{
int t;
cin>>t;
while (t--)
{
   int a1,a2,b1,b2;
   cin>>a1>>a2>>b1>>b2;

    
    int su=0;
    
    if((a1>=b1&&a2>b2)||(a1>b1&&a2>=b2))
    su=su+2;
    if((a1>=b2&&a2>b1)||(a1>b2&&a2>=b1))
    su=su+2;
    
    
    cout<<su<<endl;

}


    return 0;
}