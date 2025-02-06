#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 100005;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<long long> frs(MAX, 0);

   for (int i = 0; i < n; i++) {
        cin >> a[i];
        frs[a[i]]+=a[i];
    }

   long long prvs=0;
   long long currs=frs[1];

   for (int i = 2; i < MAX; i++)
   {
    long long news= max(currs,prvs+frs[i]);
    prvs=currs;
    currs=news;
   }
   
   cout<<currs<<endl;

    return 0;
}
