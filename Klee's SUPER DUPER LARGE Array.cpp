#include <iostream>
#include<vector>
#include<algorithm>
#define ll long long


using namespace std;
ll sum(ll l,ll r,ll k)
{
    return (r*(r+1)/2)-(l*(l-1)/2)+((r-l+1)*k);
}
int main() {
    int t;
    cin >> t;
    
    while (t--) {
       ll n,k;
       cin>>n>>k;
        ll start=0,end=n-1,ans=INT_FAST16_MAX;

        while (start>=end)
        {
            ll mid=(start+end)/2;
            ll x=sum(0,mid,k),y=sum(mid+1,n-1,k);
        if(x==y)
        {
            pl(0);
            return;
        }
        else if(x<=y)
        {
            start=mid+1;
            ans=min(ans,abs(x-y));
        }
        else
        {
            end=mid-1;
            ans=min(ans,abs(x-y));
        }
        }
        
        }
        
        
    return 0;
}
