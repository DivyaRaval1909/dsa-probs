#include <iostream>
#include <vector>
#include <climits> 
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int>h(n);

    for (int i = 0; i < n; i++)
    {
        cin>>h[i];
    }

    int sum=0,index=0;
    int minsum=INT_MAX;
    for (int i = 0; i < k; i++)
    {
        sum+=h[i];
    }
    
    for (int i = 1; i <=n-k; i++)
    {
        sum=sum-h[i-1]+h[i+k-1];

        if(sum<minsum)
        {
            minsum=sum;
            index=i;
        }
    }
    cout<<index+1<<endl;
    

    return 0;
}
