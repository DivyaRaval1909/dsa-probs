#include <iostream>
#include<vector>
#include<algorithm>
#define ll long long

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
       string s;
       cin>>s;
       char temp;
       for (int i = 1; i < s.size(); i++)
       {
        if(s[0]==s[i])
        cout<<"NO"<<endl;
        else
        {
            temp=s[0];
            s[0]=s[i];
            s[i]=temp;
            cout<<"YES"<<endl;
            cout<<s<<endl;
        }
       }
       
        
        }
        
        
    return 0;
}
