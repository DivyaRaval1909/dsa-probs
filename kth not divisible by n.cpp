#include <iostream>
#include <vector>
using namespace std;


int main() {
    int t;
    cin >> t;  
    while (t--) {
        int n,k;
        cin>>n>>k;
        vector<int>a(k);
        int count=0;
        int i=1;
        while (count==k)
        {
            if(i%n!=0)
           { count++;
            i++;
            }
        }
        
        
        
    }

    return 0;
}
