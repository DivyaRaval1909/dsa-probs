#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n,k;
        cin>>n,k;
        vector<int> a(n),b(n);

        for (int i = 0; i < n; i++)
        {
            cin>>a[i];//5 6 7 6 8
        }
        for (int i = 0; i < n; i++)
        {
            cin>>b[i];//7 9 10 6 8
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end(),greater<int>());
        int sum=0;
        for (int i = 0; i < n; i++)
        {
            if(a[i]>b[i])
            sum+=a[i];
            else
            { if(k--)
              sum+=b[i];
              else
              sum+=a[i];
            }
        }
        
       cout<<sum<<endl;
        
    }
    

    return 0;
}
