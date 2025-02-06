
#include <bit/stdc++.h>
#define ll long long
#define MOD 1000000007
#define ull unsigned long long
#define mxx 1e18 - 1
using namespace std;
using namespace std;



int main() {
    int t;
    cin>>t;
    while(t--)
    {
      ll n,k;
      cin>>n>>k;

      vector<int> a(n);

      for (int i = 0; i < n; i++)
      {
        cin>>a[i];
      }
      
      sort(a.begin(),a.end());

      ll alice=0;
      ll bob=0;
      ll turn=0;

      for (ll i = n-1; i >=0; i--)
      {
        if(turn==0)
        {
            alice+=a[i];
        }
        else{
            ll extra=a[i+1]-a[i];
            if(extra<=k)
            {
                    a[i]+=extra;
                    k-=extra;
            }
            else{
                a[i]+=k;
                k=0;
            }
            bob+=a[i];
        }
        turn^=1;
      }
      cout<<abs(alice-bob)<<endl;
    }
    return 0;
}
