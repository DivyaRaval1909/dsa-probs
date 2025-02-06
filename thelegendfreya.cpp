#include <bits/stdc++.h>
using namespace std;

int main()
{
int t;
cin>>t;
while (t--)
{
    int x,y,k;

    int xs=(x+k-1)/k;
    int ys=(y+k-1)/k;
    int ans=0;
    ans+=2*max(xs,ys);

    if(xs>ys)
    ans--;

    cout<<ans<<endl;


    return 0;
}