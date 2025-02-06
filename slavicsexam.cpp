#include <iostream>
#include<vector>
#include<algorithm>
#define ll long long

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
       string s,t;
       cin>>s>>t;
    ll n=s.size(),m=t.size();
    int i=0,j=0;
        while (i<n&&j<m)
        {
            if(s[i]=='?'||s[i]==t[j])
            {
                i++,j++;
            }
            else
            i++;

        }
        if(j!=m)
        cout<<"NO"<<endl;
        return;
        cout<<"YES"<<endl;
        while (i<n)
        {
            if(s[i]=='?')
            s[i]='d';
            i++;
        }
        cout<<s<<endl;
        
        }
        
        
    return 0;
}
