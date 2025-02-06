#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
int n,t;
cin>>n>>t;
vector<int> a(n);
for (int i = 0; i < n; i++)
{
    cin>>a[i];
}

sort(a.begin(),a.end());

if(a.size()==1&&t>a[0])
{
cout<<1<<endl;
}
else{
int sum=a[0],count=0,m=0;
while (sum<t)
{
    sum+=a[m++];
    count++;
}
cout<<count<<endl;
}
    return 0;

}