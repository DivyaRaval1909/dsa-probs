#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while (t--)
    {
       int n;
       cin>>n;
       int a[n];

       for (int i = 0; i < n; i++)
       {
        cin>>a[i];
       }
       int oc=0,ec=0;
       for (int i = 0; i <n; i++)
       {
        
        if(a[i]%2!=i%2)
        {
            if(a[i]%2==0)
            oc++;
            else
            ec++;
        }
       }
       if(oc==ec&&oc!=0)
       {
        cout<<oc<<endl;
       }
       else if(oc==0&&ec==0)
       {
        cout<<0<<endl;
       }
       else
       {
        cout<<-1<<endl;
       }
       
       
    }
    

    return 0;
}
